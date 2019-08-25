//poll,select�������� 
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
	int nready;			//����poll�ķ���ֵ����¼��������¼���fd����
	listenfd=Socket(AF_INET,SOCK_STREAM,0); 
	
	int opt=1;
	setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));	//SO_REUSEADDR ������bind()�����б��ص�ַ���ظ�ʹ��

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htol(INADDR_ANY);
	servaddr.sin_port=htos(SERV_PORT);
	
	Bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	Listen(listenfd,128); 
	
	client[0].fd=listenfd;		//Ҫ�����ĵ�һ���ļ������������뵽client[0]
	client[0].events=POLLIN;	//listenfd������ͨ���¼�
	
	for(i=1;i<OPEN_MAX;i++)
		client[i].fd=-1;		//��ʼ��client[]��ʣ�µ�Ԫ��
	
	maxi=0;
	
	while(true){
		nready=poll(client,maxi+1,-1);	//���������Ƿ��пͻ�����������
		
		if(client[0].revents&POLLIN){	//listenfd�ж��¼����� 
			clilen=sizeof(cliaddr);
			connfd=Accept(listenfd,(struct sockaddr*)&cliaddr,&clielen);//���տͻ������󣬲������� 
			printf("received from %s at PORT %d\n",
                    inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
                    ntohs(cliaddr.sin_port));
                    
            for(i=1;i<OPEN_MAX;i++){	//�ҵ�client[]�п��е�λ�ã����accept���ص�connfd 
            	if(client[i].fd<0){
            		client[i].fd=connfd;
            		break;
				} 
			}
			
			if(i==OPEN_MAX)	perr_exit("too many clients.");	//�ﵽ�����ͻ�����
			
			client[i].events=POLLIN;	//���øոշ��ص�connfd����ض��¼�
			if(i>maxi)	maxi=i;
			if(--nready<=0)	continue; 
		} 
		
		for(i=1;i<=maxi;i++){	//ǰ���ifû���㣬˵��listenfdû���㣬���client[]�������ĸ�Ҫ��������
			if((sockfd=client[i].fd)<0)	continue;
			if(client[i].revents&POLLIN){
				if((n=Read(sockfd,buf,MAXLINE))<0){
					//connection reset by client
					if(errno==ECONNRESET){	//�յ�RST��־ 
						printf("client[%d] aborted connection\n", i);
						Close(sockfd);
						client[i].fd=-1;
					}
					else
						perr_exit("read error.");
				}
				else if(n==0){	//˵���ͻ����ȹر����� 
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
