/*1、服务器端要有一个公共的共享的管道，用来实现用户到服务器之间的通信，并创建一个链表，用于存储用户登录信息。 
2、服务器端要跟每一个用户建立一个管道用于服务器与用户之间的通信，并且进行用户数据转发，当用户退出之后，这条管道自动删除。 
3、数据包的格式，首先是协议号，源id，目标id，数据内容

服务端思路 
1.先创建一个公共管道，接收客户端的消息 
2.根据用户登陆后发出的第一个包来创建以用户名命名的管道文件 
3.用一个链表来存储用户的登录列表，随时增添 
4.根据用户发送数据包的id号来判定将要执行什么操作，1是登录，2是聊天，4.是退出登录 
5.转发数据包，是直接发以目标用户名命名的管道文件，但首先要确认登录列表里面有没有目标用户。 
6.随着用户发出退出登录的包，把用户的登陆信息，管道文件删掉

客户端思路 
1.登陆的时候输入用户名 
2.随着用户登录打开公共信道，向服务器发送登录消息， 
3.一边接受服务器发来的消息，一遍等待用户输入信息 
4.把用户的信息自动封装成数据包的格式发给服务器
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "list.h"

int main(void){
	int fdserver;
	int len;
	char buff[100]={0};
	struct list* im=creat_list();		//用于接收用户发过来的信息 
	im->next=NULL;
	struct list* login=creat_list();	//用于存储登录的用户的列表
	login->next=NULL;
	
	//以不阻塞的方式打开服务器共享管道 
	if((fdserver=open("server",O_RDONLY | O_NONBLOCK))<0)
		sys_err("open fdserver.");
	
	while(1){
		//读取用户发送到服务器端的数据，存放到im结构体中 
		if((len=read(fdserver,im,sizeof(struct list)))<0){	 
			if(errno!=EAGAIN)
				sys_err("read fdserver.");
		}
		else
			resolve(im->id,im,login); 	//解析这个数据报，根据协议号工作 
		sleep(1);
	} 
	close(fdserver);
	
	return 0;
}
