//ʵ�ּ򵥵Ľ���ʽshell
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
	char input_str[BUF];	//������ַ���
	char *cmds[10];			//�ָ���ָ���ַ�������
	int fd[10][2];			//���ʮ��ָ�����Ҫ�Ÿ��ܵ�
	int i,pid,cmd_num;
	int save_stdin,save_stdout;
	
	save_stdin=dup(STDIN_FILENO);	//����׼���븴��һ��
	save_stdout=dup(STDOUT_FILENO); 
	
	while(1){				//ѭ���Ĳ�ͣ�ĵȴ��û����� 
		printf("username:path$ ");
		fgets(input_str,BUF,stdin);	//stdin�Ǳ�׼������ļ�������
		cmd_num=split(input_str,cmds); 
		
		if(cmd_num>1){		//��һ�����ϵ��������Ҫ��ʼ�����ܵ��� 
			if(pipe(fd[0])<0){
				perror("pipe error.");
				exit(1);
			}
		}
		
		i=0;				//i��ʾ��ÿһ��������
		while(cmds[i]!=NULL){	
			//����ÿһ�����������Ҫforkһ���ӽ���������exec���� 	
			pid=fork();
			if(pid<0){
				perror("fork error.");
				exit(1);
			}
			//ÿ�����̶��Ǵ������ܵ������������ܵ�д
			else if(pid==0){//��ǰָ���ӽ��� 
				//������һ��������һpipe���ر�����д��
				if(i>0){
					close(fd[i-1][1]);
					dup2(fd[i-1][0],STDIN_FILENO);	//����׼���붨����ܵ����� 
				} 
				//������һ����д��ǰpipe���رն��� 
				if(cmds[i+1]!=NULL){
					close(fd[i][0]);
					dup2(fd[i][1],STDOUT_FILENO); 
				}
				//û����һ��ָ���ǰָ�������һ�����ָ���׼��� 
				else{
					dup2(save_stdout,STDOUT_FILENO);
				}
				exec(cmds[i]); 		//�Զ����exec��������������� 
			}
			//������
			else{
				if(cmds[i+1]!=NULL&&cmds[i+2]!=NULL){
					if(pipe(fd[i+1])<0){	//�����̿�����һ���ܵ� 
						perror("pipe error.");
						exit(1);
					}
				}
				waitpid(pid,NULL,0);	//�����̵ȴ��ӽ���ִ�������Ȼ�������һ���ӽ���
				//�����̹رյ�n���ܵ��Ķ�д�ˣ������ӽ���ִ����Ϻ����ٹر� 
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

//���������ַ���Ϊ���������� 
int split(char* input_str,char* cmds[]){
	int i=0;				//ָ��ĸ���
	char *str=NULL,*saveptr=NULL;
	char *enter=NULL;
	for(i=0,str=input_str;;i++,str=NULL){
		cmds[i]=strtok_r(str,"|",&saveptr);	//�״ε����Ժ�Ҫ��str����ΪNULL 
		if(cmds[i]==NULL){
			enter=strrchr(cmds[i-1],'\n');
			*enter=' ';		//�滻��ĩβ�Ļ��з�
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
	
	//��Ҫ�ض����ļ� 
	if(op){
		*op='\0';
		*file=strtok_r((op+1)," ",&saveptr);
		fd=open(*file,file_mode,0666);
		if(fd<0){
			perror("open file error.");
			exit(1);
		}
		dup2(fd,std_fileno);	//�ؼ����� 
	}
	
	//��token���������ָ��Ͳ��� 
	for(i=0,str=cmd,savestr=NULL;;i++,str=NULL) {
		token[i]=strtok_r(str," ",&saveptr);
		if(token[i]==NULL) break;
	}
	return ;	
}
