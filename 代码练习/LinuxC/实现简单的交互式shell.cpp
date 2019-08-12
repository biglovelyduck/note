//实现简单的交互式shell
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUF 512

int split(char input_str[],char *cmds[]);
void take_token(char cmd[],char *token[],char* file[]);
void exec(char cmd[]);

int main(){
	char input_str[BUF];	//输入的字符串
	char *cmds[10];			//分割后的指令字符串数组
	int fd[10][2];			//最多十条指令，就需要九个管道
	int i,pid,cmd_num;
	int save_stdin,save_stdout;
	
	save_stdin=dup(STDIN_FILENO);	//将标准输入复制一份
	save_stdout=dup(STDOUT_FILENO); 
	
	while(1){				//循环的不停的等待用户输入 
		printf("username:path$ ");
		fgets(input_str,BUF,stdin);	//stdin是标准输入的文件描述符
		cmd_num=split(input_str,cmds); 
		
		if(cmd_num>1){		//有一条以上的子命令，就要开始创建管道了 
			if(pipe(fd[0])<0){
				perror("pipe error.");
				exit(1);
			}
		}
		
		i=0;				//i表示的每一条子命令
		while(cmds[i]!=NULL){	
			//对于每一条子命令，都需要fork一个子进程来调用exec函数 	
			pid=fork();
			if(pid<0){
				perror("fork error.");
				exit(1);
			}
			//每个进程都是从上条管道读，给下条管道写
			else if(pid==0){//当前指令子进程 
				//若有上一条，读上一pipe并关闭它的写端
				if(i>0){
					close(fd[i-1][1]);
					dup2(fd[i-1][0],STDIN_FILENO);	//将标准输入定向给管道读端 
				} 
				//若有下一条，写当前pipe并关闭读端 
				if(cmds[i+1]!=NULL){
					close(fd[i][0]);
					dup2(fd[i][1],STDOUT_FILENO); 
				}
				//没有下一条指令，当前指令是最后一条，恢复标准输出 
				else{
					dup2(save_stdout,STDOUT_FILENO);
				}
				exec(cmds[i]); 		//自定义的exec函数命令解析功能 
			}
			//父进程
			else{
				if(cmds[i+1]!=NULL&&cmds[i+2]!=NULL){
					if(pipe(fd[i+1])<0){	//父进程开启下一个管道 
						perror("pipe error.");
						exit(1);
					}
				}
				waitpid(pid,NULL,0);	//父进程等待子进程执行完命令，然后继续下一个子进程
				//父进程关闭第n个管道的读写端，等在子进程执行完毕后我再关闭 
				if(i>0){
					close(fd[i-1][0]);
					close(fd[i-1][1]);
				}  
				i++;
			} 
		} 
	}
	return 0; 
} 

//拆分输入的字符串为各个子命令 
int split(char* input_str,char* cmds[]){
	int i=0;				//指令的个数
	char *str=NULL,*saveptr=NULL;
	char *enter=NULL;
	for(i=0,str=input_str;;i++,str=NULL){
		cmds[i]=strtok_r(str,"|",&saveptr);	//首次调用以后要把str设置为NULL 
		if(cmds[i]==NULL){
			enter=strrchr(cmds[i-1],'\n');
			*enter=' ';		//替换最末尾的换行符
			break; 
		}
	}
	return i;
}

void exec(char cmd[]) {
	char *tokens[100];
	char *str,*saveptr,*file;
	int i,mode;
	
	take_token(cmd,tokens,&file);
	
	execvp(tokens[0],tokens);
	perror(tokens[0]);
	return;
}

void take_token(char* cmd,char* token[],char **file){
	int i;
	char *op;
	char *str=NULL,*saveptr=NULL;
	int fd,std_fileno,file_mode;
	
	if((op=strrchr(cmd,'<'))!=NULL){
		std_fileno=STDIN_FILENO;
		file_mode=O_RDONLY;
	}
	else if((op=strrchr(cmd,'>'))!=NULL){
		std_fileno=STDOUT_FILENO;
		file_mode=O_WRONLY | O_CREAT | O_TRUNC;
	}
	
	//需要重定向文件 
	if(op){
		*op='\0';
		*file=strtok_r((op+1)," ",&saveptr);
		fd=open(*file,file_mode,0666);
		if(fd<0){
			perror("open file error.");
			exit(1);
		}
		dup2(fd,std_fileno);	//关键代码 
	}
	
	//往token数组里填充指令和参数 
	for(i=0,str=cmd,savestr=NULL;;i++,str=NULL) {
		token[i]=strtok_r(str," ",&saveptr);
		if(token[i]==NULL) break;
	}
	return ;	
}
