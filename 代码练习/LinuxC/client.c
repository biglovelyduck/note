//客户端
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "list.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

//登录包：id=1，登陆者
//聊天包：id=2，src，dest，data
//客户不在线：id=3
//退出登录:id=4 

int main(int argc,char *argv[]){
	int fdserver;
	struct list* im=creat_list();
	im->next=NULL;
	char buff[100]={0};
	
	if(argc<2){
		printf("./client username\n");
		exit(1);
	}
	if(strlen(argv[1])>4){
		printf("username is to long,4 Bytes\n");
		exit(1);
	}
	
	//打开指向服务器的管道文件
	if((fdserver=open("server",O_WRONLY))<0)
		sys_err("open fdserver.");
	change_list(im,1,argv[1],"0","0"); 	//登录包,填写好第一次发送给服务端的信息im 
	
	if(write(fdserver,im,sizeof(struct list))<0)	//把登录信息写入管道fdserver 
		sys_err("write login information.");
		
	//把标准输入改为非阻塞属性
	be_noblock(STDIN_FILENO);
	
	while(1){
		//给服务端发送消息
		if(comm_client(im,fdserver)) 
			printf("invalid input\n");
		
		sleep(1);
		
		//退出 
		if(im->id==4){
			close(server);
			printf("see you\n");
			return 0;
		} 
		//接收服务端的信息 
		read_client(argv[1]);
	} 
	return 0;
} 
