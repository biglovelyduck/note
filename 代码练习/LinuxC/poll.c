//poll,select的升级版 
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "wrap.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 80
#define SERV_PORT 8000
#define OPEN_MAX 1024

int main(int argc,char* avg[]){
	int i,j,maxi,listenfd,connfd,sockfd;
	struct sockaddr_in cliaddr,servaddr;
	ssize_t n; 
	socklen_t clielen;
	struct pollfd client[OPEN_MAX];
	char buf[MAXLINE],str[INET_ADDRSTRLEN];
	int nready;			//接收poll的返回值，记录满足监听事件的fd个数
	listenfd=Socket(AF_INET,SOCK_STREAM,0); 
	
	int opt=1;
	setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));	//SO_REUSEADDR 允许在bind()过程中本地地址可重复使用

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htol(INADDR_ANY);
	servaddr.sin_port=htos(SERV_PORT);
	
	Bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	Listen(listenfd,128); 
	
	client[0].fd=listenfd;		//要监听的第一个文件描述符，存入到client[0]
	client[0].events=POLLIN;	//listenfd监听普通读事件
	
	for(i=1;i<OPEN_MAX;i++)
		client[i].fd=-1;		//初始化client[]中剩下的元素
	
	maxi=0;
	
	while(true){
		nready=poll(client,maxi+1,-1);	//阻塞监听是否有客户端连接请求
		
		if(client[0].revents&POLLIN){	//listenfd有读事件就绪 
			clilen=sizeof(cliaddr);
			connfd=Accept(listenfd,(struct sockaddr*)&cliaddr,&clielen);//接收客户端请求，不会阻塞 
			printf("received from %s at PORT %d\n",
                    inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
                    ntohs(cliaddr.sin_port));
                    
            for(i=1;i<OPEN_MAX;i++){	//找到client[]中空闲的位置，存放accept返回的connfd 
            	if(client[i].fd<0){
            		client[i].fd=connfd;
            		break;
				} 
			}
			
			if(i==OPEN_MAX)	perr_exit("too many clients.");	//达到了最大客户端数
			
			client[i].events=POLLIN;	//设置刚刚返回的connfd，监控读事件
			if(i>maxi)	maxi=i;
			if(--nready<=0)	continue; 
		} 
		
		for(i=1;i<=maxi;i++){	//前面的if没满足，说明listenfd没满足，检测client[]看看是哪个要发送数据
			if((sockfd=client[i].fd)<0)	continue;
			if(client[i].revents&POLLIN){
				if((n=Read(sockfd,buf,MAXLINE))<0){
					//connection reset by client
					if(errno==ECONNRESET){	//收到RST标志 
						printf("client[%d] aborted connection\n", i);
						Close(sockfd);
						client[i].fd=-1;
					}
					else
						perr_exit("read error.");
				}
				else if(n==0){	//说明客户端先关闭连接 
					printf("client[%d] closed connection\n", i);
                    Close(sockfd);
                    client[i].fd = -1;
				}
				else {
                    for (j = 0; j < n; j++)
                        buf[j] = toupper(buf[j]);
                    Writen(sockfd, buf, n);
                }
                if (--nready <= 0)
                    break;
			}	
		}
	} 
	
	return 0;
}
