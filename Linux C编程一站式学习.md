#第17章 计算机体系结构基础

### 2.CPU

CPU总是周而复始的做同一件事：不停的从内存取指令，然后解释执行它。最核心的功能单元：

* 寄存器：是cpu内部的告诉存储器，eip做程序计数器
* 程序计数器（特殊的寄存器）：保存着cpu取下一条指令的地址，cpu按保存的地址去内存中取指令然后执行
* 指令译码器：cpu取上来的指令由若干字节（内存地址，寄存器编号，操作）组成
* 算术逻辑单元：给运算指令做运算
* 地址和数据总线：cpu和内存之间用地址总线，数据总线和控制总线连接起来，每条线有0和1两种状态

**访问内存读取的过程**:

![1560561293973](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560561293973.png)

1. CPU内部将寄存器对接到数据总线上，使寄存器的每一位对接到一条数据线，等待接收数据。
2. CPU通过控制线发一个读请求，并且将内存地址通过地址线发给内存。
3. 内存收到地址和读请求之后，将相应的内存单元对接到数据总线的另一端，这样，内存单元每一位的1或0状态通过一条数据线到达CPU寄存器中相应的位，就完成了数据传送。

**cpu的取指执行过程**：

![1560561757693](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560561757693.png)

1. eip寄存器指向地址0x80483a2，CPU从这里开始取一条5个字节的指令，然后 eip 寄存器指向下一条指令的起始地址0x80483a7。`
2. CPU对这5个字节译码，得知这条指令要求从地址0x804a01c开始取4个字节保存到 eax 寄存器。
3. 执行指令，读内存，取上来的数是3，保存到 eax 寄存器。注意，地址0x804a01c~0x804a01f里存储的四个字节不能按地址从低到高的顺序看成0x03000000，而要按地址从高到低的顺序看成0x00000003。也就是说，对于多字节的整数类型，低地址保存的是整数的低位，这称为小端（Little Endian）字节序（Byte Order）。x86平台是小端字节序的，而另外一些平台规定低地址保存整数的高位，称为大端（Big Endian）
  字节序。
4. CPU从 eip 寄存器指向的地址取一条3个字节的指令，然后 eip 寄存器指向下一条指令的起始地址0x80483aa。
5. CPU对这3个字节译码，得知这条指令要求把 eax 寄存器的值加1，结果仍保存到 eax 寄存器。
6. 执行指令，现在 eax 寄存器中的数是4。
7. CPU从 eip 寄存器指向的地址取一条5个字节的指令，然后 eip 寄存器指向下一条指令的起始地址0x80483af。
8. CPU对这5个字节译码，得知这条指令要求把 eax 寄存器的值保存到从地址0x804a018开始的4个字节。

9. 执行指令，把4这个值保存到从地址0x804a018开始的4个字节（按小端字节序保存）。

### 3.设备

cpu通过内存映射IO或端口IO访问响应的总线控制器，通过总线控制器再去访问挂在总线上的设备。

当设备需要主动通知cpu时就引发一个中断信号，cpu正在执行的指令就会被打断，程序计数器指向某个固定的地址，于是cpu从这个地址开始取指令，执行终端服务程序。

### 4.MMU

MMU是内存管理单元

**物理地址**：

![1560562759338](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560562759338.png)

如果处理器没有MMU，或者有MMU但没有启用，CPU执行单元发出的内存地址将直接传到芯片引脚上，被内存芯片（以下称为物理内存，以便与虚拟内存区分）接收，这称为物理地址（Physical Address，以下简称PA）

![1560562801404](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560562801404.png)

如果处理器启用了MMU，CPU执行单元发出的内存地址将被MMU截获，从CPU到MMU的地址称为虚拟地址（Virtual Address，以下简称VA），而MMU将这个地址翻译成另一个地址发到CPU芯片的外部地址引脚上，也就是将VA映射成PA



# 第18章 x86汇编程序基础

### 4.寻址方式

直接寻址，变址寻址，间接寻址，基址寻址。立即数寻址，寄存器寻址

### 5.ELF文件

可重定位的目标文件，可执行文件，共享库

文件和加载地址的对应关系：

![1560589549282](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560589549282.png)



# 第19章 汇编与C之间的关系

### 1.函数调用

函数栈帧：

![1560589918494](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560589918494.png)

esp始终指向栈顶，ebp是在堆栈中寻址用的。

调用一个函数时，先将堆栈原先的基址（EBP）入栈，以保存之前任务的信息。然后将栈顶指针的值赋给EBP，将之前的栈顶作为新的基址（栈底），然后再这个基址上开辟相应的空间用作被调用函数的堆栈。函数返回后，从EBP中可取出之前的ESP值，使栈顶恢复函数调用前的位置；再从恢复后的栈顶可弹出之前的EBP值，因为这个值在函数调用前一步被压入堆栈。这样，EBP和ESP就都恢复了调用前的位置，堆栈恢复函数调用前的状态。

**注意函数调用和返回过程中的这些规则：**

1. 函数参数压栈传递，并且是从右向左依次压栈。

2. ebp总是指向当前栈帧的栈底 ，而esp指向栈顶，在函数执行过程中esp随着压栈和出栈操作随时变化，而ebp是不动的，函数的参数和局部变量都是通过ebp的值加上一个偏移量来访问

### 2.main函数和启动历程

编译一个程序三步：![1560592116312](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560592116312.png)

1.生成汇编代码	2.生成目标文件	3.生成可执行文件

![1560592187546](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560592187546.png)

gcc main.o -o main 其实是调用 ld 做链接的，相当于这样的命令：

```
$ ld /usr/lib/crt1.o /usr/lib/crti.o main.o -o main -lc -dynamic-linker /lib/ld-linux.so.2
```

**为什么汇编程序的入口是_start，而C程序的入口是main函数呢？**

Gcc只是一个外壳而不是真正的编译器，真正的c编译器是：/uer/lib/gcc/i486-gun/4.3.2/ccl;同样，ld的连接器是/uer/lib/gcc/i486-gun/4.3.2/collect2。编译链接具体步骤如下：

（1）main.c被ccl编译成汇编程序/tmp/ccRGDpua.s

（2）这个汇编被as汇编成目标文件/tmp/ccidnZ1d.o

（3）这个目标文件连同另外几个目标文件（crt1.o, crti.o, crtbegin.o, crtend.o, crtn.o）一起链接成可执行文件main。

**即可执行文件main是由main.o和编译器提供的另外几个目标文件一起链接生成的。**

```
$ nm  /usr/lib/crt1.o
00000000  R    _IO_stdin_used
00000000  D  __data_start
           U  __libc_csu_fini
           U  __libc_csu_init
           U  __libc_start_main

00000000  R   _fp_hw
00000000  T  _start
00000000  W  data_start
           U  main
```

U main这一行表示main这个符号在crt1.o中用到了，但是没有定义（U表示Undefined），因此需要别的目标文件提供一个定义并且和crt1.o链接在一起。

C程序的入口其实是crt1.o提供的 _start,它首先做一些初始化工作（启动例程），然后调用我们编写的main函数。所以，_start 才是真正的入口点，而main函数是被 _start调用的。

 

由于main函数是被**启动例程**调用的，所以main函数return时就返回到启动例程中，main的返回值被启动例程得到，如果将启动例程表示成等价代码：

                        exit( main(argc,argv) )

**即启动例程得到main的返回值后，立刻用它做参数调用 _exit函数,成为进程的退出状态。**

番：如果声明一个函数的返回值类型是int ，如果缺了return则返回值不确定，编译器通常是会报警告的，但如果某个分支控制流程调用了exit或_exit而不写return，编译器是允许的，因为它都没有机会返回了，指不指定返回值也就无所谓了。

### 3.变量的存储布局

```c
#include <stdio.h>
	const int A = 10;
	int a = 20;
	static int b = 30;
	int c;
int main(void)
{
	static int a = 40;
	char b[] = "Hello world";
	register int c = 50;
	printf("Hello world %d\n", c);
	return 0;
}
```

**.bass** : 用于存放程序中*未初始化的全局变量*的一块内存区域（未手动初始化），但不分配空间，只记录所需空间 （不在可执行文件中）

**.data** : 用于存放程序中*已初始化的全局变量*的一块内存区域（手动初始化），分配空间，数据保存在目标文件中

**.rodata** : 存放C中字符串和#define定义的常量

**.text** : 存放程序执行代码的一块内存区域

一个程序本质上是由**bass data text**段组成的

 

**3.1标识符的链接属性**

**外部链接**：如果最终的可执行文件由多个程序文件链接而成，在任意程序文件中即使声明多次也都代表同一个变量或函数。例如上例中 main 函数外面的 a 和 c ， main 和 printf 也算

**内部链接：**Linkage），如果一个标识符在某个程序文件中即使声明多次也都代表同一个变量或函数，则这个标识符具有Internal Linkage。例如上例中 main 函数外面的 b 。如果有另一个 foo.c 程序和 main.c 链接在一起，在 foo.c 中也声明一个 static int b; ，则那个 b 和这个 b 不代表同一个变量

**无链接**：以上情况之外

**3.2 存储类修饰符**

**static**：用它修饰的变量的存储空间是静态分配的，用它修饰的文件作用域的变量或函数具有Internal Linkage。

**auto**：用它修饰的变量在函数调用时自动在栈上分配存储空间，函数返回时自动释放（auto可以省略不写 ）

**register**：编译器对于用register修饰的变量会尽可能分配一个专门的寄存器来存储 （现用的少）

**extern：**用于多次声明同一个标识符

**类型限定符：**const,restrict,volatile



### 4.结构体和联合体

一个结构体里几个变量中间有填充（padding）：使得地址对齐，效率高

gcc提供了一种扩展语法可以消除结构体中的填充字节：

```c
struct {
	char a;
	short b;
	int c;
	char d;
} __attribute__((packed)) s;		//除非有特殊理由，否则不推荐
```



### 5.C内联汇编

gcc提供了一种扩展语法可以在C代码中使用内联汇编（Inline Assembly）。最简单的格式是 __asm__("assembly code") 。

### 6.volatile限定符

为什么要用volatile？

为了防止编译器把设备寄存器当成普通的内存单元而给优化掉，防止不按自己的想法优化。

番：普通的内存单元，只要程序不去改写它，它就不会变，如果对一个普通的内存单元连续做三次写操作，只有最后一次的值会保存到内存单元中，所以前两次写操作是多余的，可以优化掉 。

设备寄存器往往具有以下特性： 

（1）设备寄存器中的数据不需要改写就可以自己发生变化，每次读上来的值都可能不一样。
（2）连续多次向设备寄存器中写数据并不是在做无用功，而是有特殊意义的

volatile修饰变量，告诉编译器，即使在编译时制定了优化选项，每次读这个变量都要老老实实的从内存读取，每次这个变量也仍然要老老实实写回内存，不能省略任何步骤

**当一个全局变量被同一进程中的多个控制流程访问时也要用 volatile 限定，比如信号处理函数和多线程。**



# 第20章 链接详解

### 3.静态库

![1560939241102](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560939241102.png)

![1560939250914](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560939250914.png)

ar:打包的作用

r：将后面的文件列表添加到文件包，如果文件包不存在就创建它

s:用于生成静态库的

![1560939487400](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560939487400.png)

-L:告诉编译器去哪里找需要的库文件。-L表示在当前目录找

-lstack:告诉编译器要链接libstack库

-I:告诉编译器去哪里找头文件

**链接共享库和链接静态库的区别：**

在链接 libc 共享库时只是指定了动态链接器和该程序所需要的库文件，并没有真的做链接，可执行文件 main 中调用的 libc 库函数仍然是未定义符号，要在**运行时做动态链接**。而在链接静态库时，链接器会把静态库中的目标文件取出来和可执行文件真正链接在一起。

**静态库的好处：**使用静态库的一个好处，链接器可以从静态库中只取出需要的部分来做链接。如果是直接把那些目标文件和 main.c 编译链接在一起：$ gcc main.c stack.o push.o pop.o is_empty.o -Istack -o main则没有用到的函数也会链接进来。当然另一个好处就是使用静态库只需写一个库文件名，而不需要写一长串目标文件名。

### 4.共享库

概念：共享库以.so结尾. (so ==share object) 在程序的链接时候并不像静态库那样在拷贝使用函数的代码，而只是作些标记。然后在程序开始启动运行的时候，动态地加载所需模块。所以，应用程序在运行的时候仍然需要共享库的支持。 共享库链接出来的文件比静态库要小得多。

一般一个共享库的有三个名字：soname,real-name, linker-name。

![1560940179906](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1560940179906.png)

-f:后面接一些编译选项，PIC表示生成位置无关代码

共享库是位置无关代码，在运行时可以加载到任意地址，其加载地址只有在动态链接时才能确定

ldd命令：模拟一遍函数,查看可执行文件依赖哪些库



**共享路径的搜索顺序：**

1. 首先在环境变量 LD_LIBRARY_PATH 所记录的路径中查找。
2. 然后从缓存文件 /etc/ld.so.cache 中查找。这个缓存文件由 ldconfig 命令读取配置文件 /etc/ld.so.conf 之后生成
3. 如果上述步骤都找不到，则到默认的系统路径中查找，先是/usr/lib然后是/lib。

**共享库的创建:**

$gcc -fpic/fPIC -c source.c -o source.o$

$gcc -shared -Wl,-soname,your_soname -o library_name file_list library_list$

**说明**: -fpic或者-fPIC表明创建positionindependent code，这通常是创建共享库必须的。
-Wl 表明给链接器传送参数，所以这里-soname,library_name 为给链接器的参数。
-shared 表明是使用共享库

**下面是使用a.c和b.c创建共享库的示例**：
gcc -fPIC -g -c -Wall a.c
gcc -fPIC -g -c -Wall b.c
gcc -shared -Wl,-soname, libmyab.so.1 -o libmyab.so.1.0.1 a.o b.o -lc
说明: lc == libc

###5.虚拟内存管理

/proc 目录中的文件并不是真正的磁盘文件，而是由内核虚拟出来的文件系统，当前系统中运行的每个进程在 /proc 下都有一个子目录，目录名就是进程的id，查看目录下的文件可以得到该进程的相关信息

![1561017215399](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561017215399.png)

**虚拟内存管理的作用：**

1. 虚拟内存管理可以控制物理内存的访问权限
2. 虚拟内存管理最主要的作用是让每个进程有独立的地址空间

进程的地址空间是独立的：

![1561017558901](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561017558901.png)

由于每个进程都有自己的一套VA到PA的映射表，整个地址空间中的任何VA都在每个进程自己的映射表中查找相应的PA，因此不可能访问到其它进程的地址，也就没有可能意外改写其它进程的数据。

3.   VA到PA的映射会给分配和释放内存带来方便，物理地址不连续的几块内存可以映射成虚拟地址连续的一块内存

**不连续的PA可以映射为连续的VA**

![1561017974675](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561017974675.png)

​	4.一个系统如果同时运行着很多进程，为各进程分配的内存之和可能会大于实际可用的物理内存，虚拟内存管理使得这种情况下各进程仍然能够正常运行

**系统中可分配的内存总量 = 物理内存的大小 + 交换设备的大小**

![1561018276081](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1561018276081.png)

第一张图是换出，将物理页面中的数据保存到磁盘，并解除地址映射，释放物理页面。第二张图是换入，从空闲的物理页面中分配一个，将磁盘暂存的页面加载回内存，并建立地址映射。



#第21章 预处理

### 2.宏定义

#### 2.1函数式宏定义：

```c
#define MAX(a, b) ((a)>(b)?(a):(b))
k = MAX(i&0x0f, j&0x0f)
```

1、函数式宏定义的参数没有类型，预处理器只负责做形式上的替换，而不做参数类型检查，
所以传参时要格外小心。

2、代码中出现的每次调用编译生成的指令都相当于一个函数体，而不是（真正函数调用）简单的几条传参指令和 call 指令，所以，使用函数式宏定义编译生成的目标文件会比较大。

3、宏定义外层的括号是不能省的

4、例如 MAX(++a, ++b),要展开成 k = ((++a)&gt;(++b)?(++a):(++b)) ， a 和 b 就不一定是增加一次还是两次了.

5、即使实参没有Side Effect（副作用），使用函数式宏定义也往往会导致较低的代码执行效率。



**在定义之中有空白和没有空白被认为是不同的，所以这样的重复定义是不允许的**：

```c
#define OBJ_LIKE (1 - 1)
#define OBJ_LIKE (1-1)
```

如果需要重新定义一个宏，和原来的定义不同，可以先用 #undef 取消原来的定义，再重新定义，例如：

```c
#define X 3
... /* X is 3 */
#undef X
... /* X has no definition */
#define X 2
... /* X is 2 */
```

#### 2.3 # 、##运算符和可变参数

在函数式宏定义中， # 运算符用于创建字符串， # 运算符后面应该跟一个形参（中间可以有空格或Tab），例如：

```c
#define STR(s) # s
STR(hello world)
```

'#'运算符通知预处理器根据函数STR的参数s创建一个字符串字面量，并且实参中的连续多个空白字符被替换成一个空格。注意如果实参中包含字符常量或字符串，则宏展开之后字符串的界定符 " 要替换成 \" ，字符常量或字符串中的 \ 和 " 字符要替换成 \\ 和 \" 。

在宏定义中可以用 ## 运算符把前后两个预处理Token连接成一个预处理Token，和 # 运算符不同， ## 运算符不仅限于函数式宏定义，变量式宏定义也可以用，例如：

```c
#define CONCAT(a, b) a##b
CONCAT(con, cat)				//预处理之后是concat
```

```c
#define DEBUGP(format, ...) printk(format, \## __VA_ARGS__)
//当 __VA_ARGS 是空参数时， ## 运算符把它前面的 , 号“吃”掉了。
```

### 4.其他处理特性

C标准规定了几个特殊的宏，在不同的地方使用可以自动展开成不同的值

\__FILE__ 展开为当前源文件的文件名，是一个字符串， \__LINE__ 展开为当前代码行的行号，是一个整数



# 第22章 Makefile基础

### 1.基本规则

#### 1.1设置clean是伪目标：

```shell
clean:
@echo "cleanning project"
-rm main *.o
@echo "clean completed"
.PHONY: clean
```

可以防止有特殊的文件名叫clean引起冲突。

#### 1.2约定俗称的目标名字：

***all** ，执行主要的编译工作，通常用作缺省目标。
***install** ，执行编译后的安装工作，把可执行文件、配置文件、文档等分别拷到不同的安装目录。
***clean** ，删除编译生成的二进制文件。
***distclean** ，不仅删除编译生成的二进制文件，也删除其它生成的文件，例如配置文件和格式转换后的文档，执行 make distclean 之后应该清除所有这些文件，只留下源文件。

### 2.隐含规则和模式规则

```makefile
# default
OUTPUT_OPTION = -o $@
# default
CC = cc
# default
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
%.o: %.c
# commands to execute (built-in):
	$(COMPILE.c) $(OUTPUT_OPTION) $<
```

\$@ 和 \$\&lt; 是两个特殊的变量， **\$@ 的取值为规则中的目标**，**\ \&lt; 的取值为规则中的第一个条件。​**
%.o: %.c 是一种特殊的规则，称为模式规则（Pattern Rule）
$CFLAGS 表示用于 C 编译器的选项,定义成一些编译选项，例如 -o 、 -g 等.
\$CPPLAGS 表示用于 C++ 编译器的选项,[详解](https://blog.csdn.net/m0_37170593/article/details/78892913), 定义成一些预处理选项，例如 -D 、 -I 等

\$@ : 表示目标文件
$^ : 表示所有的依赖文件，所有条件，组成一个列表，用空格分离
\$<:  表示第一个依赖文件
\$?  :表示比目标还要新的条件，组成一个列表，用空格分离；有时候希望只对更新过的条件进行操作

### 3.变量

**:=运算符：**可以让make 在遇到变量定义时立即展开
**？=运算符：**例如 foo ?= \$(bar) 的意思是：如果 foo 没有定义过，那么 ?= 相当于 = ，定义 foo 的值是 $(bar) ，但不立即展开；如果先前已经定义了 foo ，则什么也不做，不会给 foo 重新赋值。
**+=运算符：**可以给变量追加值

以下列举一些常用的变量：

AR：静态库打包命令的名字，缺省值是 ar 。
ARFLAGS：静态库打包命令的选项，缺省值是 rv 。
AS：汇编器的名字，缺省值是 as 。
ASFLAGS：汇编器的选项，没有定义。
CC：C编译器的名字，缺省值是 cc 。
CFLAGS：C编译器的选项，没有定义。
CXX：C++编译器的名字，缺省值是 g++ 。
CXXFLAGS：C++编译器的选项，没有定义。
CPP：C预处理器的名字，缺省值是 \$(CC) -E 。
CPPFLAGS：C预处理器的选项，没有定义。
LD：链接器的名字，缺省值是 ld 。
LDFLAGS：链接器的选项，没有定义。
TARGET_ARCH：和目标平台相关的命令行选项，没有定义。
OUTPUT_OPTION:输出的命令行选项，缺省值是 -o \$@ 。
LINK.o:把 .o 文件链接在一起的命令行，缺省值是 \$(CC) \$(LDFLAGS) ​\$(TARGET_ARCH) 。
LINK.c:把 .c 文件链接在一起的命令行，缺省值是 ​\$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) .
LINK.cc:把 .cc 文件（C++源文件）链接在一起的命令行，缺省值是 $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH) 。
COMPILE.c：编译 .c 文件的命令行，缺省值是 $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c 。
COMPILE.cc：编译 .cc 文件的命令行，缺省值是 $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c 。
RM：删除命令的名字，缺省值是 rm -f 。

### 4.自动处理头文件的依赖关系

gcc 的 -M 选项自动生成目标文件和源文件的依赖关系

```shell
$ gcc -M main.c
main.o: main.c /usr/include/stdio.h /usr/include/features.h \
/usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
/usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
```

-M 选项把 stdio.h 以及它所包含的系统头文件也找出来了，如果我们不需要输出系统头文件的依赖关系，可以用 -MM 选项：

```SHELL
$ gcc -MM *.c
main.o: main.c main.h stack.h maze.h
maze.o: maze.c maze.h main.h
stack.o: stack.c stack.h main.h
```

```shell
set -e; rm -f maze.d; \
cc -MM maze.c > maze.d.$$; \
sed 's,\(maze\)\.o[ :]*,\1.o maze.d : ,g' < maze.d.$$ > maze.d; \
rm -f maze.d.$$
```

1. set -e 命令设置当前Shell进程为这样的状态：如果它执行的任何一条命令的退出状态非零则立刻终止，不再执行后续命令。
2. 把原来的 maze.d 删掉。
3. 重新生成 maze.c 的依赖关系，保存成文件 maze.d.1234 （假设当前Shell进程的id是1234）。注意，在Makefile中 $ 有特殊含义，如果要表示它的字面意思则需要写两个$，所以Makefile中的四个$传给Shell变成两个$，两个$在Shell中表示当前进程的id，一般用它给临时文件起名，以保证文件名唯一。
4. 这个 sed 命令比较复杂，就不细讲了，主要作用是查找替换。 maze.d.1234 的内容应该是 maze.o: maze.c maze.h main.h ，经过 sed 处理之后存为 maze.d ，其内容是 maze.o maze.d: maze.c maze.h main.h 。
5. 最后把临时文件 maze.d.1234 删掉。

### 5.常用的make命令行选项

-n 选项只打印要执行的命令，而不会真的执行命令，这个选项有助于我们检查Makefile写得是否正确

-C 选项可以切换到另一个目录执行那个目录下的Makefile，比如先退到上一级目录再执行我们的Makefile



# 第23章 指针

