#ifndef _LIST_H_
#define _LSIT_H_

#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct list{
	int id;
	char scr[5];
	char dest[5];
	char data[100];
	struct list* next;
};

//创建节点链表 
struct list* creat_list(){
	return calloc(sizeof(struct list),1); 
} 

//添加链表元素 
int add_list(struct list* ls,int id,char *src,char* data){
	struct list* p=ls;
	while(p->next){
		p=p->next;
	}
	struct list* tmp=creat_list();
	
	tmp->next=p->next;
	p->next=tmp;
	tmp->id=id;
	strcpy(tmp->src,src);
	strcpy(tmp->data,data);
	
	return 0; 
}

//修改链表元素 
int change_list(struct list* ls,int id,char* src,char* dest,char *data){
	struct list* tmp=ls;
	tmp->id=id;
	strcpy(tmp->src,src);
	strcpy(tmp->dest,dest);
	strcpy(tmp->data,data);
	
	return 0;
}

//遍历链表，打印出来
void show_list(struct list* ls){
	struct list* p=ls;
	while(p){
		printf("id=%d,src=%s,dest=%s,data=%s\n",p->id,p->src,p->dest,p->data);
		p=p->next;
	}
}

//删除链表的元素 
int del_list(struct list* login,char *src){
	struct list* p=login;
	while(strcmp(p->next->src,src))
		p=p->next;
	struct list* tmp=p->next;
	if(p->next->next==NULL)
		p->next=NULL;
	else
		p->next=p->next->next;
	free(tmp);
	
	return 0; 
}

//分析id号来辨别用户的操作，解析服务器接收到的数据 
int resolve(int id,struct list* im,struct list* login){
	int fdclient;
	
	switch(id){
	case 1:	//登录信息
		add_list(login,im->id,im->src,im->data);
		if(mkfifo(im->src,0644)<0)	//创建服务器和用户之间通信的管道 
			sys_err("mkfifo.");
		break;
	case 2://聊天包
		if(find_list(login, im->dest) <0) {     //聊天包首先是查找用户是否在线
			//不在线 
            printf("The user is not login\n");
        	if((fdclient = open(im->src, O_WRONLY)) < 0) //如果存在，就打开对方的管道文件
            	sys_err("open userfifo");
        	write(fdclient, "Don't have this user\n", 21);
        	close(fdclient);
            return -1;  //如果不在线就返回-1
        }
        char buff[105] = {0};
        if((fdclient = open(im->dest, O_WRONLY)) < 0) //如果存在，就打开对方的管道文件
            sys_err("open userfifo");
        sprintf(buff, "%s:%s\n", im->src, im->data);    //把要发给对方的数据写入buff内
        if((write(fdclient, buff, strlen(buff))) < 0)    //把buff写入对方的管道文件中，等待对方读取
            sys_err("write userfifo");
        close(fdclient);
        break;
    case 4: //退出
        unlink(im->src);    //退出，把用户的管道文件删除
        del_list(login, im->src);   //删除链表元素
        im->id = 0; //修改协议号，保证下次在没有用户输入的情况下也不会重复删除，导致段错误
        break;
    }
    return 0;		
} 

//接收用户的输入，判断用户的输入然后把输入转换到im结构体里面
int comm_client(struct list* im,int fdserver){
	char buff[100] = {0};
    char dest_tmp[100];
    char *dest_name;
    int flags;
    int len;

    if((len = read(STDIN_FILENO, buff, sizeof(buff))) < 0) { //读用户输入的数据
        if(errno != EAGAIN)
            sys_err("read user input");
    }
    else  {   //如果len不小于0，说明有数据，如果有数据就把数据封装到结构体中去
        if((strcmp(buff, "quit\n")) == 0||(strcmp(buff,"exit\n") == 0)) { //如果用户输入quit或exit就向服务器发送一个id为4的包，是退出登录信息
            im->id = 4; //把id改为4
            write(fdserver, im, sizeof(struct list)); //给服务器发送信息
            return 0;
        }
        len = strlen(buff);
        if((len < 4) && (len > 0))
            return -1;

        if(strlen((dest_name = strtok(buff, ":"))) > 4) //判断用户的用户名不超过四个字节
            return -1;
        //当用户输入的内容不是上述这几种，那就按照正常的用户数据包发出
        im->id = 2; //然后把id置为2，说明是正常的数据
        strcpy(im->dest, dest_name);    //把对方的用户名放到dest这个结构体元素中去
        dest_name = strtok(NULL, ":");  //冒号后面是内容，放到data这个元素里面去
        strcpy(im->data, dest_name);
        printf("im->src = %s, im->dest = %s, im->data = %s\n", im->src, im->dest, im->data);
        write(fdserver, im, sizeof(struct list)); //给服务器发送信息

    }
	return 0; 
} 

//查找登录的用户中是否有这个用户存在
int find_list(struct list* ls,char *name){
	show_list(ls);
	struct list* login=ls;
	while(login){
		if((strcmp(login->src,name))==0)
			return 0;	//存在返回0
		login=login->next; 
	}
	return -1;	//不存在返回-1 
}

//从用户自己的fifo文件读取服务器发送过来的数据
void read_client(char *client_fifo){
	int len;
    char buff[100] = {0};
    struct list *tmp = creat_list();
    int fdclient;

    if((fdclient = open(client_fifo,O_RDONLY|O_NONBLOCK)) < 0)   //打开以自己名字命名的管道文件
        sys_err("open userfifo");
    if((len = read(fdclient, buff, sizeof(buff))) < 0) {    //读管道中的
        if(errno != EAGAIN)
            sys_err("read data");
    }
    else
        write(STDIN_FILENO, buff, strlen(buff));    //打印到屏幕上
    return;
}

//把文件设置为非阻塞
void be_noblock(int fd){
	int flags;
    if((flags = fcntl(fd, F_GETFL)) < 0)	//获取已有的标志位 
        sys_err("fcntl");
    flags |= O_NONBLOCK;
    if((fcntl(fd, F_SETFL, flags)) < 0)
        sys_err("fcntl");
}

void sys_err(const char* str){
	perror(str);
	exit(1);
}

#endif 
