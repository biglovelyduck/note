//�ͻ���
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "list.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

//��¼����id=1����½��
//�������id=2��src��dest��data
//�ͻ������ߣ�id=3
//�˳���¼:id=4 

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
	
	//��ָ��������Ĺܵ��ļ�
	if((fdserver=open("server",O_WRONLY))<0)
		sys_err("open fdserver.");
	change_list(im,1,argv[1],"0","0"); 	//��¼��,��д�õ�һ�η��͸�����˵���Ϣim 
	
	if(write(fdserver,im,sizeof(struct list))<0)	//�ѵ�¼��Ϣд��ܵ�fdserver 
		sys_err("write login information.");
		
	//�ѱ�׼�����Ϊ����������
	be_noblock(STDIN_FILENO);
	
	while(1){
		//������˷�����Ϣ
		if(comm_client(im,fdserver)) 
			printf("invalid input\n");
		
		sleep(1);
		
		//�˳� 
		if(im->id==4){
			close(server);
			printf("see you\n");
			return 0;
		} 
		//���շ���˵���Ϣ 
		read_client(argv[1]);
	} 
	return 0;
} 
