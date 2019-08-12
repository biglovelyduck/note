//实现简单的交互式shell 
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h> 

#define MAXARG 8			
#define MAX 1024		
#define MAXCMD 16	

typedef struct command {
    char *argv[MAXARG];		  //ls -l -F -a -R   
    char *in, *out;	//输入，输出重定向文件 
} cmd_t;

int parse(char *buf, cmd_t *cmdp)	//拆分字符串 
{
    char *tmp = buf, *curcmd;
    int cmdnum = 0, i = 0, j = 0;
		
    if ((cmdp[cmdnum].argv[0] = strtok(tmp, "|"))) {	  //strsep
		puts(cmdp[cmdnum].argv[0]);		//将命令的名字输出到屏幕				
        cmdnum++;
	}
    while ((cmdp[cmdnum].argv[0] = strtok(NULL, "|"))) {	
        cmdnum++;										
	}
    for (i = 0; i < cmdnum; i++) {	//继续拆分每个子命令 ls -l | wc -l 
        curcmd = cmdp[i].argv[0];		
        cmdp[i].in = cmdp[i].out = NULL;

        while (*curcmd) {
            if (*curcmd == ' ') {				
                *curcmd++ = '\0';			
                continue;
            }
            if (*curcmd == '<') {				
                *curcmd = '\0';				
                while (*(++curcmd) == ' ')	
                    ;
                cmdp[i].in = curcmd;		
                if (*curcmd == '\0')
                    return -1;				
                continue;
            }
            if (*curcmd == '>') {				
                *curcmd = '\0';
                while (*(++curcmd) == ' ')
                    ;
                cmdp[i].out = curcmd;
                if (*curcmd == '\0')
                    return -1;
                continue;
            }
            if (*curcmd != ' ' && ((curcmd == cmdp[i].argv[0]) || *(curcmd - 1) == '\0')) {
                cmdp[i].argv[j++] = curcmd++;	
                continue;					
            }
            curcmd++;	//ls的s直接进行这一步 
        }
        cmdp[i].argv[j] = NULL;
        j = 0;
    }

    return cmdnum;
}

//暂时只是先实现只有一个管道,使用俩子进程
void my_pipe(cmd_t *my_order,int cmdnum){
	int fd[2];
	int ret=pipe(fd);
	if(-1==ret){
		perror("pipe error.");
		exit(1);
	}
	int i;
	for(i=0;i<cmdnum-1;i++){
		//使用俩子进程
		int i;
		for(i=0;i<2;i++){
			if(!(pid=fork())){
				break;
			}
		}
	}
} 
 
void show(cmd_t *cmdp, int cmdnum)    
{
    int i, j;

    for (i = 0; i < cmdnum; i++) {
        printf("cmd-show:%s,", cmdp[i].argv[0]);

        for(j = 1; cmdp[i].argv[j]; j++)
            printf("argv:%s,", cmdp[i].argv[j]);

        printf("in:%s, out:%s\n", cmdp[i].in, cmdp[i].out);
    }
}

int main(void)
{
    char buf[MAX];		
    int cmdnum;
    cmd_t cmd[MAXCMD];   

    while (1) {
        printf("sh%%");
        fflush(stdout);				
        fgets(buf, MAX, stdin);	//将屏幕中的数据存放到buf中，最多读取MAX字节 

        if (buf[strlen(buf) - 1] == '\n')	//遇到回车字符输入结束	
            buf[strlen(buf) - 1] = '\0';
        //比较俩字符串的差异,比较时会自动忽略大小写的差异。 
        if (strcasecmp(buf, "exit") == 0 || strcasecmp(buf, "quit") == 0 
           ||strcasecmp(buf, "EXIT") == 0 || strcasecmp(buf, "bye") == 0)	
            break;

        cmdnum = parse(buf, cmd);	//cmd可以存放历史命令，返回通过|拆分后子命令的个数 
        show(cmd, cmdnum);
		my_pipe(cmd,cmdnum);		
    }

    return 0;
}*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#define BUFF 512

int split(char input_str[], char *cmds[]);
void take_token(char cmd[], char *token[], char *file[]);
void exec(char cmd[]);

/* test:
cat < file1|wc -c > file1
cat<file1 | wc -c > file1
cat     < file1| wc -c>file1
cat < file1 | wc -c > file1     
ls -l -R > file1
ls -l -R>   file1
ls -l -R >file1   
*/

int main()
{
    char input_str[BUFF];  // 输入指令字符串
    char *cmds[10];        // 分割完的指令字符串
    int fd[10][2];         // 管道
    int i, pid, cmd_num;
    int save_stdin, save_stdout;
    
    save_stdin = dup(STDIN_FILENO);
    save_stdout = dup(STDOUT_FILENO);
    
    while (1) {
        printf("username:path$ ");
        fgets(input_str, BUFF, stdin);
        cmd_num = split(input_str, cmds);	//根据管道（|）切割成多条指令，存放在cmds中 
        
        if (cmd_num > 1) {	//有一条以上的子命令 
            if (pipe(fd[0]) < 0) {   // 当前pipe
                perror("pipe");
                exit(1);
            }
        }
        
        i = 0;	//i表示的每一条子命令 
        while (cmds[i] != NULL) {
/*             printf("%s\n", cmds[i]);
            i++; */
            pid = fork();
            //对每条指令，fork一个子进程并调用exec函数处理它。
            if (pid < 0) {
                perror("fork");
                exit(1);
            } 
			//每个进程都是从上条管道读，从下条管道写 
			else if (pid == 0) {   // 当前指令子进程
                /* printf("1\n"); */
                if (i > 0) {         // 若有上一条，读上一pipe并关闭它的写端
                    /* printf("2\n"); */
                    close(fd[i-1][1]);
                    dup2(fd[i-1][0], STDIN_FILENO);
                }
                if (cmds[i+1] != NULL) {     // 若有下一条，写当前pipe并关闭读端
                    close(fd[i][0]);
                    dup2(fd[i][1], STDOUT_FILENO);
                } else {   // 当前指令是最后一条，恢复标准输出
                    dup2(save_stdout, STDOUT_FILENO);
                }
                exec(cmds[i]);
            } else {                 // 当前指令父进程
                if (cmds[i+1] != NULL && cmds[i+2] != NULL) {
                    if (pipe(fd[i+1]) < 0) {   // 当前pipe
                        perror("pipe");
                        exit(1);
                    }
                }
                //父进程关闭第n个管道的读写端 
                if (i > 0) {         // 两次fork后关闭上一条指令的父进程pipe读写
                    close(fd[i-1][0]); // 顺序：fork子1,fork子2,关闭父读写
                    close(fd[i-1][1]); // 这个if块写在i++后面会阻塞子进程。。
                }
                waitpid(pid, NULL, 0);           // 等待指令执行结束
                i++;

            }
        }
    }
    return 0;
}

int split(char input_str[], char *cmds[])
{
    int i = 0; // 指令个数
    char *str = NULL, *saveptr = NULL;
    char *enter = NULL;
    
    for (i=0, str=input_str; ; i++, str=NULL){
        cmds[i] = strtok_r(str, "|", &saveptr);
        if (cmds[i] == NULL) {
            enter = strrchr(cmds[i-1], '\n');
            *enter = ' ';   // 替换最末尾换行符
            break;
        }
    }
    return i;
}

void take_token(char cmd[], char *token[], char *file[]) {
    int i;
    char *op;
    char *str = NULL, *saveptr = NULL;
    int fd, std_fileno, file_mode;
    
    if ((op = strrchr(cmd, '<')) != NULL) {
        std_fileno = STDIN_FILENO;
        file_mode = O_RDONLY;
    }
    else if ((op = strrchr(cmd, '>')) != NULL) {
        std_fileno = STDOUT_FILENO;
        file_mode = O_WRONLY | O_CREAT | O_TRUNC;
    }
    

    if (op) {
        *op = '\0';
        *file = strtok_r((op+1), " ", &saveptr);
        fd = open(*file, file_mode, 0666);
        if (fd < 0) {
            perror("open");
            exit(1);
        }

        dup2(fd, std_fileno);

        //printf("[[%s]]", *file);
    }

    for (i=0, str=cmd, saveptr = NULL; ; i++, str=NULL) {
        token[i] = strtok_r(str, " ", &saveptr);
        if (token[i] == NULL)
            break;
    }
    return ;
}

void exec(char cmd[])
{
    char *tokens[100];
    char *str, *saveptr, *file;
    int i, mode;
    
    take_token(cmd, tokens, &file);

    execvp(tokens[0], tokens);
    perror(tokens[0]);
    return ;
}

