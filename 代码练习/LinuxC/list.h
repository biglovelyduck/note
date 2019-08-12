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

//�����ڵ����� 
struct list* creat_list(){
	return calloc(sizeof(struct list),1); 
} 

//�������Ԫ�� 
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

//�޸�����Ԫ�� 
int change_list(struct list* ls,int id,char* src,char* dest,char *data){
	struct list* tmp=ls;
	tmp->id=id;
	strcpy(tmp->src,src);
	strcpy(tmp->dest,dest);
	strcpy(tmp->data,data);
	
	return 0;
}

//����������ӡ����
void show_list(struct list* ls){
	struct list* p=ls;
	while(p){
		printf("id=%d,src=%s,dest=%s,data=%s\n",p->id,p->src,p->dest,p->data);
		p=p->next;
	}
}

//ɾ�������Ԫ�� 
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

//����id��������û��Ĳ������������������յ������� 
int resolve(int id,struct list* im,struct list* login){
	int fdclient;
	
	switch(id){
	case 1:	//��¼��Ϣ
		add_list(login,im->id,im->src,im->data);
		if(mkfifo(im->src,0644)<0)	//�������������û�֮��ͨ�ŵĹܵ� 
			sys_err("mkfifo.");
		break;
	case 2://�����
		if(find_list(login, im->dest) <0) {     //����������ǲ����û��Ƿ�����
			//������ 
            printf("The user is not login\n");
        	if((fdclient = open(im->src, O_WRONLY)) < 0) //������ڣ��ʹ򿪶Է��Ĺܵ��ļ�
            	sys_err("open userfifo");
        	write(fdclient, "Don't have this user\n", 21);
        	close(fdclient);
            return -1;  //��������߾ͷ���-1
        }
        char buff[105] = {0};
        if((fdclient = open(im->dest, O_WRONLY)) < 0) //������ڣ��ʹ򿪶Է��Ĺܵ��ļ�
            sys_err("open userfifo");
        sprintf(buff, "%s:%s\n", im->src, im->data);    //��Ҫ�����Է�������д��buff��
        if((write(fdclient, buff, strlen(buff))) < 0)    //��buffд��Է��Ĺܵ��ļ��У��ȴ��Է���ȡ
            sys_err("write userfifo");
        close(fdclient);
        break;
    case 4: //�˳�
        unlink(im->src);    //�˳������û��Ĺܵ��ļ�ɾ��
        del_list(login, im->src);   //ɾ������Ԫ��
        im->id = 0; //�޸�Э��ţ���֤�´���û���û�����������Ҳ�����ظ�ɾ�������¶δ���
        break;
    }
    return 0;		
} 

//�����û������룬�ж��û�������Ȼ�������ת����im�ṹ������
int comm_client(struct list* im,int fdserver){
	char buff[100] = {0};
    char dest_tmp[100];
    char *dest_name;
    int flags;
    int len;

    if((len = read(STDIN_FILENO, buff, sizeof(buff))) < 0) { //���û����������
        if(errno != EAGAIN)
            sys_err("read user input");
    }
    else  {   //���len��С��0��˵�������ݣ���������ݾͰ����ݷ�װ���ṹ����ȥ
        if((strcmp(buff, "quit\n")) == 0||(strcmp(buff,"exit\n") == 0)) { //����û�����quit��exit�������������һ��idΪ4�İ������˳���¼��Ϣ
            im->id = 4; //��id��Ϊ4
            write(fdserver, im, sizeof(struct list)); //��������������Ϣ
            return 0;
        }
        len = strlen(buff);
        if((len < 4) && (len > 0))
            return -1;

        if(strlen((dest_name = strtok(buff, ":"))) > 4) //�ж��û����û����������ĸ��ֽ�
            return -1;
        //���û���������ݲ��������⼸�֣��ǾͰ����������û����ݰ�����
        im->id = 2; //Ȼ���id��Ϊ2��˵��������������
        strcpy(im->dest, dest_name);    //�ѶԷ����û����ŵ�dest����ṹ��Ԫ����ȥ
        dest_name = strtok(NULL, ":");  //ð�ź��������ݣ��ŵ�data���Ԫ������ȥ
        strcpy(im->data, dest_name);
        printf("im->src = %s, im->dest = %s, im->data = %s\n", im->src, im->dest, im->data);
        write(fdserver, im, sizeof(struct list)); //��������������Ϣ

    }
	return 0; 
} 

//���ҵ�¼���û����Ƿ�������û�����
int find_list(struct list* ls,char *name){
	show_list(ls);
	struct list* login=ls;
	while(login){
		if((strcmp(login->src,name))==0)
			return 0;	//���ڷ���0
		login=login->next; 
	}
	return -1;	//�����ڷ���-1 
}

//���û��Լ���fifo�ļ���ȡ���������͹���������
void read_client(char *client_fifo){
	int len;
    char buff[100] = {0};
    struct list *tmp = creat_list();
    int fdclient;

    if((fdclient = open(client_fifo,O_RDONLY|O_NONBLOCK)) < 0)   //�����Լ����������Ĺܵ��ļ�
        sys_err("open userfifo");
    if((len = read(fdclient, buff, sizeof(buff))) < 0) {    //���ܵ��е�
        if(errno != EAGAIN)
            sys_err("read data");
    }
    else
        write(STDIN_FILENO, buff, strlen(buff));    //��ӡ����Ļ��
    return;
}

//���ļ�����Ϊ������
void be_noblock(int fd){
	int flags;
    if((flags = fcntl(fd, F_GETFL)) < 0)	//��ȡ���еı�־λ 
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
