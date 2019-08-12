/*应该是错误写法 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl/h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>

void sys_err(char *str){
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{   
	int fdin,fdout;
	void *src,*dst;
	struct stat sbuf;	//存放文件信息状态 
	offset_t fsz=0;
	int len;
	pid_t pid;
    //1. 指定创建子进程的个数
	if(argc!=4)
		sys_err("Please input as ./a.out src dst n");
    //2. 打开源文件
    if((fdin=open(argv[1],O_RDONLY))<0)
    	sys_err("can't open file for reading.");
    //3. 打开目的文件, 不存在则创建
    if((fdout=open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0644))<0)
    	sys_err("can't open file for writing.")
    //4. 获取文件大小
    if(fstat(fdin,&buf)<0)
    	sys_err("fstat error");
    //5. 根据文件大小拓展目标文件
    if(ftruncate(fdout,sbuf.st_size)<0)
    	sys_err("ftruncate error");
    //6. 为源文件创建映射
    if((src=mmap(0,4096,PROT_READ,MAP_SHARED,fdin,fsz))==MAP_FAILED)
    	sys_err("mmap error for input.");
    //7. 为目标文件创建映射
    if((dst=mmap(0,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fdout,fsz))==MAP_FAILED)
    	sys_err("mmap error for output.");
    //8. 求出每个子进程该拷贝的字节数
	len=sbuf.st_size;
	int size=len/n;
	int last_size=len/n+len%n;
    //9. 创建N个子进程
    int i;
	for(i=0;i<n;i++){
		pid=fork();
		if(pid==0) break;	
	}
    //10. 子进程完成分块拷贝(注意最后一个子进程拷贝起始位置)
	if(i==n-1){
		if((src=mmap(0,last_size,PROT_READ,MAP_SHARED,fdin,fsz+i*size)==MAP_FAILED)
    		sys_err("mmap error for input.");
    	if((dst=mmap(0,last_size,PROT_READ|PROT_WRITE,MAP_SHARED,fdout+i*size,fsz))==MAP_FAILED)
    		sys_err("mmap error for output.");
	}
	else{
		if((src=mmap(0,size,PROT_READ,MAP_SHARED,fdin,fsz+i*size)==MAP_FAILED)
    		sys_err("mmap error for input.");
    	if((dst=mmap(0,size,PROT_READ|PROT_WRITE,MAP_SHARED,fdout+i*size,fsz))==MAP_FAILED)
    		sys_err("mmap error for output.");
	}
    //11. 释放映射区
	munmap(src, copysz);
    munmap(dst, copysz);
    //12.回收子进程
	if(i==n){
		wait(NULL);
	} 
    return 0;
}*/

#include<stdio.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>
 
int main(){
	
	int o_fd,f_fd,c_fd,len,ret,i;
 
	//read file
	if(!access("master_bitcoin.pdf",F_OK)){	//判断文件是否具有读权限 
		o_fd=open("master_bitcoin.pdf",O_RDWR);
		if(o_fd==-1){
			perror("open o_fd error");
		}
	}
	len=lseek(o_fd,0,SEEK_END);	//获取文件大小的方法，死记 
 
	void *ptr_r=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,o_fd,0);//读文件的映射区 
	if(ptr_r==MAP_FAILED){
		perror("mmap ptr_r error");
	}
	//write file
	c_fd=open("copy.pdf",O_RDWR|O_CREAT,0777);
	if(c_fd==-1){
		perror("open o_fd error");
	}
 
	ret=ftruncate(c_fd,len);
	if(ret==-1){
		perror("ftruncate error");
	}
 
	void *ptr_w=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,c_fd,0);
	if(ptr_w==MAP_FAILED){
		perror("mmap ptr_w error");
	}
 
	//multi-process copy
	for(i=0;i<4;i++){
		f_fd=fork();
		if(f_fd==0){//son
			break;
		}
		else if(f_fd==-1){
			perror("fork error");
		}
		else{
			continue;
		}
	}
	//操作映射区就跟操作文件一样 
	if(i==4){//parent process
		memcpy(ptr_w+4*len/5,ptr_r+4*len/5,len-4*len/5);
		printf("parent copy 5st distinct,over!\n");
	}
	if(i==0){//1st son 
		memcpy(ptr_w,ptr_r,len/5);
		printf("son_1 copy 1st distinct,over!\n");
	}
 
	if(i==1){//2st son 
		memcpy(ptr_w+len/5,ptr_r+len/5,len/5);
		printf("son_2 copy 2st distinct,over!\n");
	}
 
	if(i==2){//3st son 
		memcpy(ptr_w+2*len/5,ptr_r+2*len/5,len/5);
		printf("son_3 copy 3st distinct,over!\n");
	}
 
	if(i==3){//4st son 
		memcpy(ptr_w+3*len/5,ptr_r+3*len/5,len/5);
		printf("son_4 copy 4st distinct,over!\n");
	}
	close(o_fd);
	close(c_fd);
	munmap(ptr_r,len);
	munmap(ptr_w,len);
}
