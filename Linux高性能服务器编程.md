# 一、TCP/IP协议族

## 1.协议族体系结构

![1568164704107](pic/1568164704107.png)

### 1.数据链路层

数据链路层实现了网卡接口的网络驱动程序，以处理数据在物理媒介（以太网，令牌环）上的传输。有两个常用协议ARP（地址解析协议）和RARP（逆地址解析）协议。网络层必须先把目标机器的ip地址转换为物理地址，才能使用数据链路层提供的服务。

### 2.网络层

网络层实现数据报的选路和转发。任务是选择中间节点（路由器）来确定两台主机的通信路径。重要协议是ip协议，数据报根据目的ip地址决定下一跳。

另一个重要协议是ICMP（因特网控制报文）协议，主要用来检测网络连接。

![1568165354968](pic/1568165354968.png)

8位类型：用来区分报文类型，ICMP分为**差错报文**（用来回应网络错误，比如目标不可到达（3）和重定向（5）和**查询报文**（用来查询网络信息，比如ping用来查看目标是否到达（8））。

8位代码：有的ICMP用这个来进一步细分不同的条件。比如重定向报文用代码0表示网络重定向，用代码1表示主机重定向。

16位校验和：用来对整个报文（包括头部和内容）进行循环冗余校验（CRC），以检验报文在传输过程中是否损坏。

### 3.传输层

为两台主机的应用程序提供端到端的通信。只在乎端到端，不在乎数据包的中转过程。主要有TCP，UDP，SCTP

TCP：为应用层提供可靠的，面向连接的，基于流的服务，使用超时重传，数据确认确保数据正确发送到目的端。内核中会维持一些必要的数据结构，比如连接的状态，读写缓冲区，定时器等。

UDP：为应用层提供不可靠的，无连接的基于数据报的服务。每个UDP数据报都有一个长度，接收端必须以该长度为最小单位将所有内容一次性读出，否则数据会被截断。

### 4.应用层

负责应用程序的逻辑。上面三层在内核空间实现，该层在用户空间实现，主要协议：

ping：是应用程序而不是协议，利用ICMP报文检测网络连接
telnet：远程登录协议，在本地完成远程任务
OSPF：开放最短路径优先，动态路由更新协议，用于路由器之间的通信告知各自的路由信息。
DNS：提供机器域名到ip地址的转换

## 2.封装

![1568168494761](pic/1568168494761.png)

TCP报文段：

![1568205956301](pic/1568205956301.png)

UDP无须为应用层数据提供副本，当一个UDP数据报被发送成功之后，UDP内核缓冲区的该数据报也就被丢弃了

以太网帧：![1568206175619](pic/1568206175619.png)

类型：来标识上层协议

CRC：对帧的其他部分进行循环冗余校验

MTU：帧的最大传送大院，即帧最多携带多少上层协议数据（比如IP数据报），图上所示最大为1500字节

## 3.分用

当帧到达主机时，将沿着协议栈自底向上一次传递，各层协议一次处理头部数据，以获取所需的信息，并最终处理后的帧交给应用程序，这个过程叫分用。
![1568206498410](pic/1568206498410.png)

TCP和UDP通过其头部的16位的端口号字段来区分上层应用程序

## 4.ARP协议工作原理

ARP协议能够实现任意网络层地址到物理地址的转换，IP地址到以太网地址（MAC地址）的转换工作原理：主机向自己所在的网络广播一个ARP请求，以请求包含目标机器的网络地址，此网络上的其他机器都会受到这个请求，但只有被请求的目标机器会回应一个ARP应答，其中包含自己的物理地址。

**以太网ARP请求报文/应答报文：**

![1568207316947](pic/1568207316947.png)

硬件类型：定义物理地址的类型，它的值为1表示MAC地址
协议类型：表示要映射的协议地址类型，值为0x800，表示IP地址
硬件地址长度和协议地址长度：MAC地址长度：6，IP地址长度：4
操作字段：ARP请求1，ARP应答2，RARP请求3，RARP应答4

### 1.ARP高速缓存

通常ARP维护一个高速缓存，其中包含经常访问（比如网关地址）或最近访问的ip地址到物理地址的映射，这就避免了重复的ARP请求，提高了发送数据包的速度。

`arp -a`：查看和修改ARP高速缓存
`sudo arp -d 192.168.1.109`：删除某个机器对应的ARP缓存项
`sudo arp -s 192.168.1.109 08:00:27:53:10:67`：添加某个机器对应的ARP缓存项2.

### 2.使用tcpdump观察ARP通信过程

![1568208912142](pic/1568208912142.png)

![1568208886065](pic/1568208886065.png)

抓取的数据包本质上是以太网帧

![1568208979192](pic/1568208979192.png)

## 6.DNS工作原理

![1568211606356](pic/1568211606356.png)

**16位标识**：用于标记一对DNS查询和应答
**16位标志**：用于协商具体的通信方式和反馈通信状态，如下：
![1568211711091](pic/1568211711091.png)

QR：查询/应答标志。0和1
opcode：定义查询和应答的类型：标准查询0，反向查询1（ip->主机域名)，请求服务器状态2
AA：授权应答标志，仅由应答报文使用，1表示域名服务器是授权服务器
TC：截断标志，仅当DNS报文使用UDP服务时使用，1表示DNS报文超过512字节会被截断
RD：递归查询标志。1表示递归查询，0表示迭代查询
RA：允许递归标志，仅由应答报文使用，1表示DNS支持
zero：未用必须都设置0
rcode：4位返回码，表示应答的状态，0无错误，3域名不存在

**查询问题**的格式：

![1568212652387](pic/1568212652387.png)

查询名以一定的格式封装了要查询的主机域名。查询类通常为1。16位查询类型表示如何进行查询操作：
A：值是1表示获取目标主机的ip地址
CNAME，值是5，表示获得目标主机的别名
PTR：值是12，表示反向查询

**剩下三个采用资源记录格式：**
![1568213780607](pic/1568213780607.png)

### socket的功能：

1.将应用程序数据从用户数据缓冲区中复制到TCP/UDP内核发送缓冲区，以交给内核发送数据，或者从内核TCP/UDP接收缓冲区复制数据到用户缓冲区，以读取数据

2.应用程序可以通过它们来修改内核中各层协议的某些头部信息和其他数据结构，从而精细的控制底层通信的行为，比如socketopt函数设置ip数据报在网络上的存活时间。

# 二、IP协议详解

IP头部信息：用来指定IP通信的源端IP地址、目的端IP地址，指导IP分片和重组，指定部分通信行为

IP数据报的路由和转发：发生在除目标机器外的所有主机和路由器上，他们决定数据报是否应该转发以及何时转发

## 1.IP服务的特点

**无状态，无连接，不可靠**

无状态：IP通信双方不同步传输数据的状态信息，因此所有IP数据报的发送传输和接收都是相互独立没有上下文的

无连接：IP通信双方都不长久地维持对方的任何信息

不可靠：IP协议不能保证IP数据报准确到达接收端

## 2.IPv4头部结构

长度通常为20字节

![1568268901033](pic/1568268901033.png)

4位头部长度：标识IP头部有多少个32bit字（4字节），最长为60字节

8位服务类型：3位优先选段（忽略），4位TOS字段，1位保留字段（必须置0）
	4位TOS分别表示：最小延时，最大吞吐量，最高可靠性，最小费用，其中最多一个能置1，根据实际需要设置

16位总长度：整个IP数据报的长度，最大长度65535字节

16位标识：唯一的标识主机发送的每一个数据报，没发送一个数据报，值就+1

3位标志字段：第一位保留，第二包表示进制分片，第三位表示更多分片

13位分片位移：分片相对原始IP数据报开始处的偏移

8位生存时间TTL：数据报到达目的地之前允许经过的路由器跳数

8位协议：用来区分上层协议

16位头部校验和：有发送端填充，接收端对其使用CRC算法检验IP数据报头部在传输过程中是否损坏

选项字段包括：记录路由，时间戳，松散源路由选择，严格源路由选择

## 3.IP分片

分片可能发送在发送端，也可能发生在中转路由器上

![1568270143455](pic/1568270143455.png)

## 4.IP路由

![1568270289689](pic/1568270289689.png)

1.当IP模块接收到来自数据链路层的IP数据报时，它首先对该数据报的头部做CRC校验，准确无误之后就分析其头部的具体信息。
2.如果IP数据包的头部设置了源站选路选项，则IP模块调用数据报转发子模块来处理该数据报
3.如果目标IP是本机的某个IP或者广播地址，就决定派发给哪个上层应用
4.如果不是发送给本机的也调用数据报转发子模块
5.数据报转发子模块首先检查系统是否允许转发，如果不允许，IP数据报就会被丢弃，如果允许就执行一些操作然后交给IP数据报输出子模块
6.计算下一跳路由
7.IP输出队列存放所有等待发送的IP数据报，还包括封装了本机上层数据的IP数据报

### 1.路由机制

1.查找路由表中和数据包的目标IP地址完全匹配的主机IP地址，如果找到，就使用该路由项，没找到转步骤2
2.查找路由表中和数据报的目标IP地址具有相同网路ID的网络IP地址，比如相同网关地址，找到使用否则转3
3.选择默认路由项，通常意味着下一跳路由是网关

## 5.IP转发

1.检查头部TTL，如果TTL是0，则丢弃
2.查看头部严格源路由选择选项，如果该选项被设置，则检测数据报的目标IP地址是否是本机的某个IP地址，如果不是，则发送一个ICMP源站选路失败给发送端
3.如果有必要，给源端发送一个ICMP重定向报文，以告诉下一跳更合理的路由器
4.TTL-1
5.处理头部选项
6.如果有必要则执行IP分片操作

## 6.重定向

![1568271475622](pic/1568271475622.png)

![1568271744007](pic/1568271744007.png)

# 三、TCP协议详解

在应用程序中具有很强的可操作性，以下从四方面讨论：

TCP头部信息，TCP状态转移过程，TCP数据流，TCP数据流的控制

![1568272024276](pic/1568272024276.png)

![1568272058649](pic/1568272058649.png)

## 1.TCP头部结构

![1568272087553](pic/1568272087553.png)

4位头部长度：标识该TCP头部有多少个32bit字（4字节），最长是60

16位窗口：是TCP控制流量的一个手段

![1568273635548](pic/1568273635548.png)

![1568273652491](pic/1568273652491.png)

![1568273669777](pic/1568273669777.png)

# 四、TCP/IP实例:访问Internet上的Web服务器

![1568273985564](pic/1568273985564.png)

## 1.HTTP代理服务器的工作原理

在HTTP通信链上，客户端和目标端服务器之间通常存在某些中转代理服务器，他们提供对目标资源的中转访问，一个HTTP请求可能被多个代理服务器转发，后面的服务器成为前面服务器的上游服务器，代理服务器按照使用方式和作用分为正向代理，反向代理和透明代理

**正向代理：**要求客户端自己设置代理服务器的地址，客户的每次请求都会发送到该服务器，比如处于防火墙内的局域网机器要访问Internet或者要访问一些外国网站。

**反向代理**：被设置在服务器端，因为客户端无法设置。是指用代理服务器来接收Internet上的连接请求，**然后将请求转发给内部网络上的服务器**，并将从内部服务器上得到的结果返回给客户端。

正向代理服务器和客户端主机处于同一个逻辑网络，该网络可以是一个本地LAN，也可以是一个更大的网络。
反向代理服务器和真正的Web服务器也位于同一个逻辑网络中，这通常是由提供网站的公司来配置和管理。

![1568424659272](pic/1568424659272.png)

**透明代理：**只能设置在网关上。

## 2.访问DNS服务器

![1568425019086](pic/1568425019086.png)

## 3.本地名称查询

Linux将目标主机名和对应的IP地址存放在/etc/hosts配置文件中，当需要查询某个对应时，程序先检查该文件

## 4.HTTP通信

![1568425750052](pic/1568425750052.png)

### 1.HTTP请求

![1568426456221](pic/1568426456221.png)

**第一行**：请求行，GET是请求方法，表示客户端以只读的方式来申请资源

![1568426494285](pic/1568426494285.png)

安全：GET,HEAD,OPTIONS,TRACE		不安全：POST,PUT,DELETE,PATCH
等幂的：GET,HEAD,OPTIONS,TRACE,PUT,DELETE,即多次连续的，重复的请求和只发送一次该请求具有完全相同的效果。

**第二行**：表示客户端使用的程序时wget		**第三行：**表示目标主机名    
**第四行：**告诉服务器当处理完这个HTTP请求之后就关闭连接

### 2.HTTP应答

![1568426871537](pic/1568426871537.png)

**第一行：**状态行，200 OK是状态码和状态信息

![1568426921576](pic/1568426921576.png)

**第二行：**表示目标Web服务器程序的名字是BWS    **第三行：**表示目标文档的长度为8024字节
**第四行：**表示目标文档index.html是text类型中的html文档，charset是text文档类型的一个参数，用来指定编码
**第五行：**表示服务器传送一个Cookie给客户端，BAIDUID指定Cookie名字，expires指定生存时间，domain和path指定Cookie生效的域名和路径

# 五、Linux网络编程基础API

三个方面：socket地址API，socket基础API，网络信息API

## 1.socket地址API

**主机字节序：**现代PC大多采用小端字节序，因此也叫小端字节序

**网络字节序：**大端字节序

![1568511057905](pic/1568511057905.png)

### 1.通用socket地址

![1568511197096](pic/1568511197096.png)

- 地址族协议sa_family：![1568511262537](pic/1568511262537.png)

- sa_data成员用于存放socket地址值![1568511314837](pic/1568511314837.png)

14字节的sa_data根本无法完全容纳多数协议族的地址值，因此Linux定义了下面这个新的通用socket地址结构体

![1568511418372](pic/1568511418372.png)

### 2.专用socket地址

- **Unix本地域协议族：**
  ![1568511452625](pic/1568511452625.png)

- **TCP/IP协议族：**![1568511478668](pic/1568511478668.png)

### 3.IP地址转换函数

![1568511558369](pic/1568511558369.png)

**点分十进制转和网络字节序的转换：**

![1568512387490](pic/1568512387490.png)

## 2.创建socket

![1568512463529](pic/1568512463529.png)

- domain：告诉系统使用哪个底层协议
- type：指定服务类型
- protocol：在前两个参数构成的协议集合下，再选择一个具体的协议，通常是0表示默认协议

## 3.命名socket

socket和socket地址绑定称为给socket命名

![1568512639312](pic/1568512639312.png)

bind成功返回0，失败返回-1

## 4.监听socket

![1568512717717](pic/1568512717717.png)

- backlog：内核监听队列的最大长度

SIGTERM：程序结束信号，由assert调用产生

```c
//test_backlog.c
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

static bool stop = false;
/*SIGTERM信号的处理函数，触发时结束主程序中的循环*/
static void handle_term( int sig )
{
    stop = true;
}

int main( int argc, char* argv[] )
{
    signal( SIGTERM, handle_term );

    if( argc <= 3 )
    {
        printf( "usage: %s ip_address port_number backlog\n", basename( argv[0] ) );
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi( argv[2] );
    int backlog = atoi( argv[3] );

    int sock = socket( PF_INET, SOCK_STREAM, 0 );
    assert( sock >= 0 );

    struct sockaddr_in address;
    bzero( &address, sizeof( address ) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );

    int ret = bind( sock, ( struct sockaddr* )&address, sizeof( address ) );
    assert( ret != -1 );

    ret = listen( sock, backlog );
    assert( ret != -1 );
	/*循环等待连接，知道SIGTERM信号打断*/
    while ( ! stop )
    {
        sleep( 1 );
    }

    close( sock );
    return 0;
}
```

## 5.接受连接

![1568513221285](pic/1568513221285.png)

accept只是从监听队列中取出连接，而不论连接处于何种状态，如ESTABLISHED状态和CLOSE_WAIT状态

## 6.发起连接

![1568513539921](pic/1568513539921.png)

- sockfd：是本地的套接字

## 7.关闭连接

![1568513643387](pic/1568513643387.png)![1568513648558](pic/1568513648558.png)

![1568513664129](pic/1568513664129.png)

可见，shutdown能够分别关闭socket上的读和写，或者全部关闭，而close只能将socket上的读和写同时关闭

## 8.数据读写

### TCP数据读写

![1568513724349](pic/1568513724349.png)

![1568513788948](pic/1568513788948.png)

### UDP数据读写

![1568595582188](pic/1568595582188.png)

### 通用数据读写函数

![1568595622531](pic/1568595622531.png)

msghdr的定义如下：

![1568595875464](pic/1568595875464.png)

msg_iovec成员是iovec结构体类型的指针，iovec结构体的定义如下：

![1568596057161](pic/1568596057161.png)

## 9.带外标记

内核通知应用程序带外数据到达的两种常见方式：I/O复用产生的异常事件和SIGURG信号，即使受到通知，还需要带外数据在数据流中为具体位置，才能准确接收带外数据，通过![1568769377572](pic/1568769377572.png)

## 10.地址信息函数

获得一个连接socket的本端socket地址，以及远端socket地址：

![1568769429634](pic/1568769429634.png)

## 11.socket选项

如果说fcntl系统调用是用来控制文件描述符属性的通用方法，那么下面俩系统调用是用来专门读取和设置scoket文件描述符属性的方法：

![1568769532864](pic/1568769532864.png)

![1568769594793](pic/1568769594793.png)

### 1.SO_REUSEADDR选项

设置该选项来强制使用被处于TIME_WAIT状态的连接占用的socket地址

```c
int sock = socket( PF_INET, SOCK_STREAM, 0 );
    assert( sock >= 0 );
    int reuse = 1;
    setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof( reuse ) );

    struct sockaddr_in address;
    bzero( &address, sizeof( address ) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );
    int ret = bind( sock, ( struct sockaddr* )&address, sizeof( address ) );
```

### 2.SO_RCVBUF和SO_SNDBUF选项

分别用来表示TCP接收缓冲区和发送缓冲区的大小，TCP接收缓冲区的最小值是256字节，而发送缓冲区最小值是2048字节

### 3.SO_RCVLOWAT和SO_SNDLOWAT选项

分别用来表示TCP接收缓冲区和发送缓冲区的低水位标记，他们一般被I/O复用系统调用用来判断socket是否刻度或可写。默认情况下，低水位标记为1字节。

### 4.SO_LINGER选项

用于控制close系统调用在关闭TCP连接时的行为，设置该选项的值时，我们需要getsetsocketopt传递一个linger类型的结构体：

![1568771921840](pic/1568771921840.png)

- l_onoff=0：此时该选项不起作用，close用默认行为
- l_onoff!=0&&l_linger=0：此时close立即返回，TCP模块将丢弃被关闭的socket对应的TCP发送缓冲区中残留的数据，同时给对方发送一个复位报文段，这是提供了异常终止一个连接的方法
- l_onoff!=0&&l_linger>0：
  - 对于阻塞的socket：close将等待一段长为l_linger的时间，直到TCP模块发送完所有残留数据并得到对方的确认，失败返回-1并设置errno为EWOYLDBLOKC
  - 对于非阻塞的socket：close立即返回，此时需要根据返回值判断残留数据是否发送完毕

## 12.网络信息API

### 1.gethostbyname和gethostbyaddr

**gethostbyname函数**：根据主机名来获取主机的完整信息，通常先在本地的/etc/hosts配置文件中查找主机，如果没有找到再去访问DNS服务器

**gethostbyaddr函数**：根据IP地址来获取主机的完整信息

![1568772394838](pic/1568772394838.png)

这俩函数返回的都是hostent结构体类型的指针，定义如下：

![1568772440710](pic/1568772440710.png)

```c
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

int main( int argc, char *argv[] )
{
	assert( argc == 2 );
	char *host = argv[1];
	//获取目标主机地址信息
	struct hostent* hostinfo = gethostbyname( host );
	assert( hostinfo );
	//获取daytime服务信息
	struct servent* servinfo = getservbyname( "daytime", "tcp" );
	assert( servinfo );
	printf( "daytime port is %d\n", ntohs( servinfo->s_port ) );

	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = servinfo->s_port;
	//本身就是网络字节序，所以不需要转换
	address.sin_addr = *( struct in_addr* )*hostinfo->h_addr_list;

	int sockfd = socket( AF_INET, SOCK_STREAM, 0 );
	int result = connect( sockfd, (struct sockaddr* )&address, sizeof( address ) );
	assert( result != -1 );

	char buffer[128];
	result = read( sockfd, buffer, sizeof( buffer ) );
	assert( result > 0 );
	buffer[ result ] = '\0';
	printf( "the day tiem is: %s", buffer );
	close( sockfd );
    return 0;
}
```

### 3.getaddrinfo

该函数既能通过主机名获得IP地址，也能通过服务名获得端口号

![1568773107084](pic/1568773107084.png)

hostname接收主机名或者IP地址，service可以接收服务名或端口号，hints是应用程序给getaddrinfo的一个提示，以对getaddrinfo的输出进行更精确的控制，result指向一个链表用来存储getaddrinfo反馈的结果。

该函数反馈的每一条结果都是addrinfo结构体类型的对象，定义如下：

![1568773301789](pic/1568773301789.png)

![1568773327307](pic/1568773327307.png)

### 4.getnameinfo

该函数通过socket地址同时获得以字符串表示的主机名和服务名

![1568858402567](pic/1568858402567.png)

该函数将返回的主机名存储在host参数指向的缓存中，将服务名存储在serv参数指向的缓存中，flags参数控制该函数的行为：

![1568858617177](pic/1568858617177.png)

![1568858696231](pic/1568858696231.png)

# 六、高级I/O函数

- 用于创建文件米描述符的函数：pipe、dup/dup2函数
- 用于读写数据的函数：readv/writev、sendfile、mmap/munmap、splice和tee函数
- 用于控制I/O行为和属性的函数，fcntl函数

## 1.pipe

创建管道实现进程间通信，其中读写两头的文件描述符都有引用计数，管道容量的默认大小是65536字节，可以用fcntl函数修改管道容量。

![1568891108004](pic/1568891108004.png)

**创建双向管道：**这俩文件描述符既可读又可写

![1568891271649](pic/1568891271649.png)

## 2.dup和dup2

可以把标准输入重定向到文件，或者把标准输出重定向到一个网络连接

![1568891439485](pic/1568891439485.png)

dup函数创建一个新的文件描述符，该新文件描述符和原有文件描述符file_descriptor指向相同的文件、管道或者网络连接，并且返回的文件描述符总是当前系统可用最小的。

而dup2函数返回第一个不小于file_descriptor_two的整数值。

```c
//利用dup函数实现一个基本的CGI服务器
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main( int argc, char* argv[] )
{
    if( argc <= 2 )
    {
        printf( "usage: %s ip_address port_number\n", basename( argv[0] ) );
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi( argv[2] );

    struct sockaddr_in address;
    bzero( &address, sizeof( address ) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );

    int sock = socket( PF_INET, SOCK_STREAM, 0 );
    assert( sock >= 0 );

    int ret = bind( sock, ( struct sockaddr* )&address, sizeof( address ) );
    assert( ret != -1 );

    ret = listen( sock, 5 );
    assert( ret != -1 );

    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof( client );
    int connfd = accept( sock, ( struct sockaddr* )&client, &client_addrlength );
    if ( connfd < 0 )
    {
        printf( "errno is: %d\n", errno );
    }
    else
    {
        close( STDOUT_FILENO );
        dup( connfd );		//返回文件描述符1
        printf( "abcd\n" );	//输出的内容会发送到与客户连接对应的socket上
        close( connfd );
    }

    close( sock );
    return 0;
}
```

## 3.readv和wirtev

readv函数将文件描述符读到分散的内存块中，即分散读；writev函数将多块分散的内存数据一并写入到文件描述符中，即集中写。

![1568906497243](pic/1568906497243.png)

一个http请求包含1个状态行，多个头部字段，1个空行和文档的内容，其中前三行的内容可能被web服务器放在一块内存中，而文档的内容通常被读入到另外一块内存中。

```c
//web服务器上的集中写
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
/*定义两种HTTP状态码和状态信息*/
static const char* status_line[2] = { "200 OK", "500 Internal server error" };

int main( int argc, char* argv[] )
{
    if( argc <= 3 )
    {
        printf( "usage: %s ip_address port_number filename\n", basename( argv[0] ) );
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi( argv[2] );
	/*目标文件作为程序的第三个参数*/
    const char* file_name = argv[3];

    struct sockaddr_in address;
    bzero( &address, sizeof( address ) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );

    int sock = socket( PF_INET, SOCK_STREAM, 0 );
    assert( sock >= 0 );

    int ret = bind( sock, ( struct sockaddr* )&address, sizeof( address ) );
    assert( ret != -1 );

    ret = listen( sock, 5 );
    assert( ret != -1 );

    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof( client );
    int connfd = accept( sock, ( struct sockaddr* )&client, &client_addrlength );
    if ( connfd < 0 )
    {
        printf( "errno is: %d\n", errno );
    }
    else
    {
		/*用于保存HTTP应答的状态行，头部字段和一个空行的缓冲区*/
        char header_buf[ BUFFER_SIZE ];
        memset( header_buf, '\0', BUFFER_SIZE );
		/*用于存放目标文件内容的应用程序缓存*/
        char* file_buf;
		/*用于获取目标文件的属性，比如是否为目录，文件大小等*/
        struct stat file_stat;
		/*记录目标文件是否是有效文件*/
        bool valid = true;
		/*缓存区header_buf目前已经使用了多少字节的空间*/
        int len = 0;
        if( stat( file_name, &file_stat ) < 0 )			//目标文件不存在
        {
            valid = false;
        }
        else
        {
            if( S_ISDIR( file_stat.st_mode ) )			//目标文件是一个目录
            {
                valid = false;
            }
			/*当前用户有读取目标的权限*/
            else if( file_stat.st_mode & S_IROTH )
            {
				/*动态分配file_buf,并指定其大小为目标文件的大小
				file_stat.st_size加1，然后将目标文件读入缓存区file_buf中*/
                int fd = open( file_name, O_RDONLY );
                file_buf = new char [ file_stat.st_size + 1 ];
                memset( file_buf, '\0', file_stat.st_size + 1 );
                if ( read( fd, file_buf, file_stat.st_size ) < 0 )
                {
                    valid = false;
                }
            }
            else
            {
                valid = false;
            }
        }
        
		/*如果目标文件有效，则发送正常的HTTP应答*/
        if( valid )
        {
			//往header_buf里面填充内容
            ret = snprintf( header_buf, BUFFER_SIZE-1, "%s %s\r\n", "HTTP/1.1", status_line[0] );
            len += ret;
            ret = snprintf( header_buf + len, BUFFER_SIZE-1-len, 
                             "Content-Length: %d\r\n", file_stat.st_size );
            len += ret;
            ret = snprintf( header_buf + len, BUFFER_SIZE-1-len, "%s", "\r\n" );
			//利用writev将header_buf和file_buf的内容一并写出
            struct iovec iv[2];
            iv[ 0 ].iov_base = header_buf;			//内存起始地址
            iv[ 0 ].iov_len = strlen( header_buf );	//这块内存的长度
            iv[ 1 ].iov_base = file_buf;
            iv[ 1 ].iov_len = file_stat.st_size;
            ret = writev( connfd, iv, 2 );			//将这块内存的内容写到connfd中
        }
        else		//如果目标文件无效，则通知客户端服务器发生内部错误
        {
            ret = snprintf( header_buf, BUFFER_SIZE-1, "%s %s\r\n", "HTTP/1.1", status_line[1] );
            len += ret;
            ret = snprintf( header_buf + len, BUFFER_SIZE-1-len, "%s", "\r\n" );
            send( connfd, header_buf, strlen( header_buf ), 0 );
        }
        close( connfd );
        delete [] file_buf;
    }

    close( sock );
    return 0;
}
```

## 4.sendfile

sendfile函数在两个文件描述符中传递数据（完全在内核中操作），从而避免了内核缓冲区和用户缓冲区之间的数据拷贝，效率很高，成为零拷贝。

![1568966249251](pic/1568966249251.png)

in_fd：待读出内容的文件描述符，必须是一个支持类似mmap函数的文件描述符，必须指向真实的文件
out_fd：待写入内容的文件描述符，必须是一个socket

```c
//使用sendfile将服务器的一个文件传送到客户端
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sendfile.h>

int main( int argc, char* argv[] )
{
    if( argc <= 3 )
    {
        printf( "usage: %s ip_address port_number filename\n", basename( argv[0] ) );
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi( argv[2] );
    const char* file_name = argv[3];

    int filefd = open( file_name, O_RDONLY );
    assert( filefd > 0 );
    struct stat stat_buf;			//保存文件信息
    fstat( filefd, &stat_buf );		//获取文件信息

    struct sockaddr_in address;
    bzero( &address, sizeof( address ) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );

    int sock = socket( PF_INET, SOCK_STREAM, 0 );
    assert( sock >= 0 );

    int ret = bind( sock, ( struct sockaddr* )&address, sizeof( address ) );
    assert( ret != -1 );

    ret = listen( sock, 5 );
    assert( ret != -1 );

    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof( client );
    int connfd = accept( sock, ( struct sockaddr* )&client, &client_addrlength );
    if ( connfd < 0 )
    {
        printf( "errno is: %d\n", errno );
    }
    else
    {
        sendfile( connfd, filefd, NULL, stat_buf.st_size );
        close( connfd );
    }

    close( sock );
    return 0;
}
```

## 5.mmap和munmap

mmap函数用于申请一段内存空间，我们可以将这段内存作为进程间通信的共享内存，也可以将文件直接映射到其中。		munmap函数则释放有mmap创建的这段内存空间。

![1568969005017](pic/1568969005017.png)

start：用户使用某个特定的地址作为这段内存的起始地址，如果是NULL则系统自动分配一个地址。
prot：设置内存段的访问权限![1568969108251](pic/1568969108251.png)

flag：控制内存段内容被修改后程序的行为。![1568969154041](pic/1568969154041.png)

fd：被映射文件对应的文件描述符

## 6.splice

splice函数用于在两个文件描述符中**移动**数据，也是零拷贝操作。

![1568969232240](pic/1568969232240.png)

fd_in：是待输入数据的文件描述符，如果他是管道文件描述符，则off_in参数被设置成NULL，如果不是管道描述符，则off_in表示从何处开始读取数据，若他还是NULL就表示从当前偏移位置读入

![1568969382403](pic/1568969382403.png)

![1568969424808](pic/1568969424808.png)

```c
//splice回射服务器，服务器将客户端发送的数据原样发送给客户端
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main( int argc, char* argv[] )
{
    if( argc <= 2 )
    {
        printf( "usage: %s ip_address port_number\n", basename( argv[0] ) );
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi( argv[2] );

    struct sockaddr_in address;
    bzero( &address, sizeof( address ) );
    address.sin_family = AF_INET;
    inet_pton( AF_INET, ip, &address.sin_addr );
    address.sin_port = htons( port );

    int sock = socket( PF_INET, SOCK_STREAM, 0 );
    assert( sock >= 0 );

    int ret = bind( sock, ( struct sockaddr* )&address, sizeof( address ) );
    assert( ret != -1 );

    ret = listen( sock, 5 );
    assert( ret != -1 );

    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof( client );
    int connfd = accept( sock, ( struct sockaddr* )&client, &client_addrlength );
    if ( connfd < 0 )
    {
        printf( "errno is: %d\n", errno );
    }
    else
    {
        int pipefd[2];
        assert( ret != -1 );
        ret = pipe( pipefd );			//创建管道
		/*将connfd上流入的客户数据定向到管道写中*/
        ret = splice( connfd, NULL, pipefd[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE ); 
        assert( ret != -1 );
		/*将管道的读出数据到connfd客户连接的文件描述符，写回给客户端*/
        ret = splice( pipefd[0], NULL, connfd, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE );
        assert( ret != -1 );
        close( connfd );
    }

    close( sock );
    return 0;
}
```

## 7.tee

tee函数在两个管道文件描述符之间**复制**数据，也是零拷贝操作，不消耗数据，因此源文件描述符上的数据仍然可以用于后序的读操作。![1568970638514](pic/1568970638514.png)

```c
//Linux下tee程序：同时输出数据到终端和文件的程序
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main( int argc, char* argv[] )
{
	if ( argc != 2 )
	{
		printf( "usage: %s <file>\n", argv[0] );
		return 1;
	}
	int filefd = open( argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0666 );
	assert( filefd > 0 );

	int pipefd_stdout[2];
        int ret = pipe( pipefd_stdout );
	assert( ret != -1 );

	int pipefd_file[2];
        ret = pipe( pipefd_file );
	assert( ret != -1 );
	/*将标准输入内容输入管道pipe_stdout*/
	ret = splice( STDIN_FILENO, NULL, pipefd_stdout[1], NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE );
	assert( ret != -1 );
	//将管道pipe_stdout的读端输出复制到pipefd_file的写端
	ret = tee( pipefd_stdout[0], pipefd_file[1], 32768, SPLICE_F_NONBLOCK ); 
	assert( ret != -1 );
	ret = splice( pipefd_file[0], NULL, filefd, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE );
	assert( ret != -1 );
	ret = splice( pipefd_stdout[0], NULL, STDOUT_FILENO, NULL, 32768, SPLICE_F_MORE | SPLICE_F_MOVE );
	assert( ret != -1 );

	close( filefd );
    close( pipefd_stdout[0] );
    close( pipefd_stdout[1] );
    close( pipefd_file[0] );
    close( pipefd_file[1] );
	return 0;
}
```

## 8.fcntl

file control：提供对文件描述符的各种控制，另一个函数ioctl比fcntl能够执行更多的控制

![1568971309582](pic/1568971309582.png)

cmd是操作。

![1569141388029](pic/1569141388029.png)

![1569141402378](pic/1569141402378.png)

# 七、Linux服务器程序规范

## 1.日志

Linux提供一个守护进程来处理日志----syslogd，不过现在使用的额都是升级版----rsyslogd。该守护进程既能接收内核日志，又能接收用户进程输出日志，输出到/dev/log中

Linux日志体系：

![1569156929321](pic/1569156929321.png)

### syslog

应用程序使用syslog函数与rsyslog守护进程通信。采用可变参数来结构化输出。

![1569156974564](pic/1569156974564.png)

priority：设施值和日志级别的按位或，默认为LOG_USER，日志级别有如下几个：

![1569157055379](pic/1569157055379.png)

**openlog函数改变syslog的默认输出方式，进一步结构化日志内容：**

![1569157099553](pic/1569157099553.png)

ident：指定的字符串将添加到日志消息的日期和时间之后，通常被设置为程序的名字

logopt：对后序syslog调用的行为进行配置，取下列值按位或

![1569157554333](pic/1569157554333.png)

facility：用来修改syslog函数中的默认设施值

**setlogmask函数用来设施syslog的日志掩码：**maskpri指定日志掩码值

![1569157610229](pic/1569157610229.png)

使用完关闭日志功能：![1569157660886](pic/1569157660886.png)

## 2.用户信息

### 1.UID、EUID、GID和EGID

下面一组函数用来设置上面的这些ID：

![1569157754948](pic/1569157754948.png)

一个进程有俩用户ID：UID和EUID。EUID存在的目的是方便资源访问，它使得运行程序的用户拥有该程序的有效用户的权限，比如su程序，su程序的所有者就是root,有效进程为root的进程为特权进程。

### 2.切换用户

```c
//以root身份启动的进程切换为以一个普通用户身份运行
static bool switch_to_user( uid_t user_id, gid_t gp_id )
{
    //先确保目标用户不是root
    if ( ( user_id == 0 ) && ( gp_id == 0 ) )
    {
        return false;
    }

    //确保当前用户是合法用户
    gid_t gid = getgid();
    uid_t uid = getuid();
    if ( ( ( gid != 0 ) || ( uid != 0 ) ) && ( ( gid != gp_id ) || ( uid != user_id ) ) )
    {
        return false;
    }
	//如果不是root，则已经是目标用户
    if ( uid != 0 )
    {
        return true;
    }
	//切换到目标用户
    if ( ( setgid( gp_id ) < 0 ) || ( setuid( user_id ) < 0 ) )
    {
        return false;
    }

    return true;
}
```

## 3.进程间关系

### 1.进程组

Linux下每个进程都隶属于一个进程组，因此他们除了PID信息外还有进程组ID（PGID），用如下函数获取PGID：

![1569159882523](pic/1569159882523.png)

每个进程组都有一个首领进程，其PGID和PID相同，进程组一直存在，知道所有进程都退出。下面设置PGID：

![1569159959995](pic/1569159959995.png)

一个进程只能设置自己活其子进程的PGID，并且当子进程调用exec系列函数后，我们也不能再在父进程中对他设置PGID。

### 2.会话

一些关联的进程组形成一个会话，下面函数创建会话：

![1569160621229](pic/1569160621229.png)

该函数不能由进程组首领调用，否则会产生错误，其他进程调用后的效果：
	1.调用进程成为会话的首领，此时该进程是新会话的唯一成员
	2.新建一个进程组，其PGID就是调用进程PID，调用进程成为新组的首领
	3.调用进程将甩开终端

### 3.ps命令查看进程关系

![1569160951681](pic/1569160951681.png)

![1569160959173](pic/1569160959173.png)

## 4.系统资源限制

Linux系统资源的限制可以通过如下函数来读取和设置：

![1569200728978](pic/1569200728978.png)
![1569200738826](pic/1569200738826.png)

rlimit:是一个rlimit结构体类型的指针，结构体定义如下：![1569200782368](pic/1569200782368.png)

rlimit_t是一个整数类型来描述资源级别，rlimit_cur成员指定资源的软限制,rlimit_max指定资源的硬限制。

软限制是一个建议性的最好不要超过的限制，如果超越的话可能会向进程发送信号终止运行：
	当进程cpu时间超过软限制，系统向进程发送SIGXCPU信号。
	当文件尺寸超过软限制，发送SIGXFSZ信号。

![1569201137125](pic/1569201137125.png)

## 5.改变工作目录和根目录

一般来说，Web服务器的逻辑根目录并非文件系统的根目录“/“，而是站点的根目录（对于Linux的Web服务器一般来说是/var/www）。获取进程当前工作目录和改变进程工作目录的额函数分别是：

![1569201280696](pic/1569201280696.png)

buf：存储进程当前工作目录的绝对路径名，大小由size指定

改变根目录的函数：![1569201708511](pic/1569201708511.png)

## 6.服务器程序后台化

```c
//将服务器以守护进程的方式运行
bool daemonize()
{
    pid_t pid = fork();
    if ( pid < 0 )
    {
        return false;
    }
    else if ( pid > 0 )		//创建子进程，关闭父进程，这样可以让程序在后台运行
    {
        exit( 0 );
    }
	/*设置文件权限掩码，当进程创建新文件时，文件权限是mode&0777*/
    umask( 0 );
	/*创建新的会话，设置本进程为进程组的首领*/
    pid_t sid = setsid();
    if ( sid < 0 )
    {
        return false;
    }
	/*切换工作目录*/
    if ( ( chdir( "/" ) ) < 0 )
    {
        /* Log the failure */
        return false;
    }
	/*关闭各种设备*/
    close( STDIN_FILENO );
    close( STDOUT_FILENO );
    close( STDERR_FILENO );
	/*关闭其他已经打开的文件描述符，此处省略*/
	/*将标准输入输出都定向到/dev/null文件中*/
    open( "/dev/null", O_RDONLY );
    open( "/dev/null", O_RDWR );
    open( "/dev/null", O_RDWR );
    return true;
}
```

实际上，Linux提供了完成同样功能的库函数：![1569202668264](pic/1569202668264.png)

nochdir：用于指定是否改变工作目录，如果是0，则工作目录是“/“，否则继续使用当前工作目录
noclose：为0时标准设备都被输出重定向到/dev/null文件

# 八、高性能服务器程序框架

我们按照服务器的一般原理，解构为三个主要模块：

- I/O处理单元：本章介绍四种I/O模型和两种高效事件处理模式
- 逻辑单元：本章介绍逻辑单元的两种高效并发模式，以及高效处理方式---有限状态机
- 存储单元

## 1.服务器模型

### 1.C/S模型

![1569203144832](pic/1569203144832.png)

由于客户连接请求时随机到达的异步事件，所以服务器需要使用某种I/O模型来监听这一事件。

![1569203313260](pic/1569203313260.png)

该模型适合资源相对集中的场合，并且实现简单，但是缺点很明显，服务器是通信的核心，当访问量过大时，所有客户都会得到很慢的响应，P2P模型解决了这个问题。

### 2.P2P模型

点对点模型，云计算机群是一个P2P模型的典范，缺点是当用户间的传输请求过多时网络的负载加重。

![1569203500696](pic/1569203500696.png)

主机之间很难相互发现，所以需要一个发现服务器，使每个客户都能尽快找到自己需要的资源。每台主机既是服务器又是客户端。

## 2.服务器编程框架

基本框架：![1569203633652](pic/1569203633652.png)

该图既能来描述一台服务器，又能来描述一个服务器机群，各个部件的含义和功能如下：

![1569203726168](pic/1569203726168.png)
![1569203749907](pic/1569203749907.png)

负载均衡：从所有逻辑服务器中选取负荷最小的一台为新客户服务

## 3.I/O模型

socket在创建的时候默认是阻塞的，通过第二个参数SOCK_NONBLOCK标志，调用函数fcntl设置F_SETFL命令设置为非阻塞。我们称阻塞的文件描述符为阻塞I/O，非阻塞的文件描述符为非阻塞I/O。

非阻塞的I/O执行系统调用总是立即返回，不管事件是否发生，如果事件没有发生，都返回-1，非阻塞I/O要和其他通知机制一起使用，比如I/O复用和SIGIO信号。

**I/O复用：**指的是应用程序通过I/O复用函数向内核注册一组事件，内核通过I/O复用函数把其中就绪的时间通知给应用程序，Linux常用的I/O复用函数就是select，pool和epoll_wait，I/O复用函数本身是阻塞的，他们能提高程序效率的原因在于他们具有同时监听多个I/O事件的能力。

**SIGIO信号**：我们可以为一个目标文件描述符指定宿主进程，那么被指定的宿主进程将捕获到SIGIO信号，这样，当文件描述符上有事件发生时，SIGIO信号的信号处理喊出被触发，我们就可以在目标文件描述符指向非阻塞I/O

![1569288344376](pic/1569288344376.png)

## 4.两种高效的事件处理模式

服务器程序通常要处理三种事件：I/O事件，信号和定时事件。同步I/O模型常用于实现Reactor模式，异步I/O模型常用于Proactor模式。

### 1.Reactor模式

它要求主线程（I/O处理单元）只负责监听文件描述符上是否有事件发生，有的话就立即将该事件通知给工作线程，读写、接受新连接以及处理客户请求都在工作线程中完成。

使用**同步I/O模型**（epoll_wait为例）实现的Reactor模式的工作流程：
	1.主线程往epoll内核事件表中注册socket的读就绪事件
	2.主线程调用epoll_wait等待socket上有数据可读
	3.当socket上有数据可读时，epoll_wait通知主线程。主线程则将socket**可读事件放入请求队列**
	4.睡眠在请求队列上的某个工作线程被唤醒，它从socket读取数据，并处理客户请求，然后往epoll内核事件注册表中注册该socket上的写就绪事件
	5.主线程调用epoll_wait等待socket可写
	6.当socket可写时，epoll_wait通知主线程。主线程将socket**可写事件放入请求队列**
	7.睡眠在请求队列上的某个工作进程被唤醒，它从socket上写入服务器处理客户请求的结果

![1569291097118](pic/1569291097118.png)

### 2.Proactor模式

与Reactor模式不同，Proactor模式将所有的I/O操作都交给主线程和内核来处理，工作线程仅仅负责业务逻辑，更符合服务器编程框架。

使用**异步I/O模型**（以aio_read和aio_write为例）实现的Proactor模式的工作流程：
	1.主线程调用aio_read函数向内核注册socket上的读完成事件，并告诉内核用户读缓冲区的位置，以及读操作完成时如何通知应用程序
	2.主线程继续处理其他逻辑
	3.当socket上的数据被读入用户缓冲区后，内核将向应用程序发送一个信号，以通知应用程序数据可用
	4.应用程序预先定义好的信号处理函数选择一个工作线程来处理客户请求。工作线程处理完客户请求之后，调用aio_write函数向内核注册一个socket上的写完成事件，并告诉内核用户缓冲区写的位置，以及写操作完成时如何通知应用程序
	5.主线程继续处理其他逻辑
	6.当用户缓冲区的数据被写入socket之后，内核将向应用程序发送一个信号，以通知应用程序数据以及发送完毕
	7.应用程序预先定义好的信号处理函数选择一个工作线程来做善后处理，比如决定是否关闭socket

![1569291905993](pic/1569291905993.png)

主线程的epoll_wait调用仅能用来检测监听socket上的连接请求时间，而不能用来检测socket上的读写事件。socket上的读写事件是通过aio_read/aio_write向内核注册的，因此应用程序将通过信号来向应用程序报告连接socket上的读写事件。

### 3.模拟Proacator模式

原理：主线程执行数据读写操作，读写完成后，主线程向工作线程通知这一个“完成事件”，那么从工作线程的角度来看，他们就直接获得了数据读写的结果，接下来要做的就是对读写的结果进行逻辑处理。

使用同步I/O模型模拟出的Proactor模式的工作流程如下：
	1.主线程往epoll内核事件中注册socket上的读就绪事件
	2.主线程调用epoll_wait等待socket上有数据可读
	3.当socket上有数据可读时，epoll_wait通知主线程。主线程从socket循环读取数据直到没有更多数据可读，然后读取到的数据封装成一个请求对象并插入请求队列。
	4.睡眠在请求队列上的某个工作线程被唤醒，他获得请求对象并处理客户请求，然后往epoll内核事件表中注册socket上的写就绪事件
	5.主线程调用epoll_wait等待socket可写
	6.当socket可写时，epoll_wait通知主线程，主线程往socket上写入服务器处理客户请求的结果

![1569293184373](pic/1569293184373.png)

## 5.两种高效的并发模式

并发是为了让程序同时执行多个任务，让被阻塞I/O的执行线程主动放弃cpu并且将执行权转移到其他线程，这样一来cpu可以干其他事情，利用率显著提升。

并发模式是指I/O处理单元和多个逻辑单元之间协调完成任务的方法，服务器主要有两种并发编程模式：半同步/半异步模式和领导者/追随者模式。

### 1.半同步/半异步模式

在I/O模型中，同步和异步区分的是内核向应用进程通知的是何种事件（是读就绪事件还是完成事件），以及该由谁来完成读写（是应用程序还是内核）。

在并发模式中，同步指的是程序完全按照代码序列的顺序执行；异步指的是程序的执行需要由系统事件来驱动。常见的系统事件包括中断，信号等。

![1569308945594](pic/1569308945594.png)

