//���߳̿����ļ� �������ж�δд 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define T_NUM 5;
#define ITEMS 50 

void err_sys(void *str){
	perror(str);
	exit(1);
}

void err_usr(char *str){
	pfuts(str,stderr);
	exit(1);
}

typedef struct{
	int off,size,t_no;
}arg_t;

int n=T_NUM;		//ָ���������߳��� 
char *s,*d;			//sָ���ļ���mmapӳ�� 
int *done; 			//ÿ���߳���������ֽ��� 

//arg{off,size,t_no}���߳̿����ļ��ĺ��� 
void *tfn(void* arg){
	arg_t *arg_p ;int i;
	char *p,*q;
	
	arg_p=(arg_t*)arg;
	p=s+arg_p.off,q=d+arg_p.off;
	for(i=0;i<arg_p->size;i++){		//���ֽڿ��� 
		*q++=*p++,done[arg_p->t_no]++;
		usleep(10);			//�Ѷ�Ӧ���̹߳���һ��ʱ�䣬��λms 
	}
	return NULL; 
}

void* display(void *arg){
	int size,interval,draw,sum,i,j;		
	
	size=(int)arg;						//�ļ��ܴ�С
	interval=size/(ITEMS-1); 			//interval:���
	draw=0;
	while(draw<ITEMS){
		for(i=0,sum=0;i<n;i++)
			sum+=done[i];
		j=sum/interval+1;				//��ǰ�ܹ���Ҫ�����ĵȺŸ��� 
		for(;j>draw;draw++)
			putchar('=');
		fflush(stdout);
	}
	putchar('\n');
	return NULL;
}

int main(int argc,char* argv[]){
	int src,dst;
	struct stat statbuf;
	pthread_t *tid;				//����̵߳����� 
	arg_t *arr;					//ÿ���̵߳��������� 
	if(argc!=3&&argc!=4)
		err_usr("usage:cp src dst [thread_no]\n");
	if(argc=4)
		n=atoi(argv[3]);
	
	src=open(argv[1],O_RDONLY);
	dst=open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644);
	fstat(src,&statbuf);	//��ȡ�ļ�����Ϣ
	lseek(dst,statbuf.st_size-1,SEEK_SET);	//����dst�ļ��Ĵ�С 
	write(dst,"a",1);		//��һ��������
	
	s=(char*)mmap(NULL,statbuf.st_size,PROT_READ,MAP_PRIVATE,src,0);
	d=(char*)mmap(NULL,statbuf.st_size,PROT_WRITE,MAP_SHARED,dst,0);
	
	close(src);	close(dst);
	 
	tid=(pthread_t*)malloc(sizeof(pthread_t)*(n+1));
	
	done=(int*)calloc(sizeof(int),n);		//done[n]
	
	arr=(arg_t *)malloc(sizeof(arg_t)*n); 	//arr[n]
	
	len=statbuf.st_size/n,off=0;			//�����߳��������飬��������
	for(int i=0;i<n;i++,off+=len)
		arr[i].off=off,arr[i].size=len,arr[i].t_no=i;
	arr[n-1].size+=(statbuf.st_size%n);
	
	for(i=0;i<n;i++)						//����ִ�п���������� 
		pthread_create(&tid[i],NULL,tfn,(void*)&arr[i]); 
		
	pthread_create(&tid[n],NULL,display,(void*)statbuf.st_size);	//�������Ƚ���
	
	for(i=0;i<n+1;i++)						//�����߳� 
		pthread_join(tid[i],NULL);	

#if 1
	munmap(s,statbuf.st_size);
	munmap(d,statbuf.st_size);
#endif
	free(tid);free(done);free(arr); 
}
