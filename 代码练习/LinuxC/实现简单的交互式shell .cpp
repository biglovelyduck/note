//ʵ�ּ򵥵Ľ���ʽshell 
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
    char *in, *out;	//���룬����ض����ļ� 
} cmd_t;

int parse(char *buf, cmd_t *cmdp)	//����ַ��� 
{
    char *tmp = buf, *curcmd;
    int cmdnum = 0, i = 0, j = 0;
		
    if ((cmdp[cmdnum].argv[0] = strtok(tmp, "|"))) {	  //strsep
		puts(cmdp[cmdnum].argv[0]);		//������������������Ļ				
        cmdnum++;
	}
    while ((cmdp[cmdnum].argv[0] = strtok(NULL, "|"))) {	
        cmdnum++;										
	}
    for (i = 0; i < cmdnum; i++) {	//�������ÿ�������� ls -l | wc -l 
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
            curcmd++;	//ls��sֱ�ӽ�����һ�� 
        }
        cmdp[i].argv[j] = NULL;
        j = 0;
    }

    return cmdnum;
}

//��ʱֻ����ʵ��ֻ��һ���ܵ�,ʹ�����ӽ���
void my_pipe(cmd_t *my_order,int cmdnum){
	int fd[2];
	int ret=pipe(fd);
	if(-1==ret){
		perror("pipe error.");
		exit(1);
	}
	int i;
	for(i=0;i<cmdnum-1;i++){
		//ʹ�����ӽ���
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
        fgets(buf, MAX, stdin);	//����Ļ�е����ݴ�ŵ�buf�У�����ȡMAX�ֽ� 

        if (buf[strlen(buf) - 1] == '\n')	//�����س��ַ��������	
            buf[strlen(buf) - 1] = '\0';
        //�Ƚ����ַ����Ĳ���,�Ƚ�ʱ���Զ����Դ�Сд�Ĳ��졣 
        if (strcasecmp(buf, "exit") == 0 || strcasecmp(buf, "quit") == 0 
           ||strcasecmp(buf, "EXIT") == 0 || strcasecmp(buf, "bye") == 0)	
            break;

        cmdnum = parse(buf, cmd);	//cmd���Դ����ʷ�������ͨ��|��ֺ�������ĸ��� 
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
    char input_str[BUFF];  // ����ָ���ַ���
    char *cmds[10];        // �ָ����ָ���ַ���
    int fd[10][2];         // �ܵ�
    int i, pid, cmd_num;
    int save_stdin, save_stdout;
    
    save_stdin = dup(STDIN_FILENO);
    save_stdout = dup(STDOUT_FILENO);
    
    while (1) {
        printf("username:path$ ");
        fgets(input_str, BUFF, stdin);
        cmd_num = split(input_str, cmds);	//���ݹܵ���|���и�ɶ���ָ������cmds�� 
        
        if (cmd_num > 1) {	//��һ�����ϵ������� 
            if (pipe(fd[0]) < 0) {   // ��ǰpipe
                perror("pipe");
                exit(1);
            }
        }
        
        i = 0;	//i��ʾ��ÿһ�������� 
        while (cmds[i] != NULL) {
/*             printf("%s\n", cmds[i]);
            i++; */
            pid = fork();
            //��ÿ��ָ�forkһ���ӽ��̲�����exec������������
            if (pid < 0) {
                perror("fork");
                exit(1);
            } 
			//ÿ�����̶��Ǵ������ܵ������������ܵ�д 
			else if (pid == 0) {   // ��ǰָ���ӽ���
                /* printf("1\n"); */
                if (i > 0) {         // ������һ��������һpipe���ر�����д��
                    /* printf("2\n"); */
                    close(fd[i-1][1]);
                    dup2(fd[i-1][0], STDIN_FILENO);
                }
                if (cmds[i+1] != NULL) {     // ������һ����д��ǰpipe���رն���
                    close(fd[i][0]);
                    dup2(fd[i][1], STDOUT_FILENO);
                } else {   // ��ǰָ�������һ�����ָ���׼���
                    dup2(save_stdout, STDOUT_FILENO);
                }
                exec(cmds[i]);
            } else {                 // ��ǰָ�����
                if (cmds[i+1] != NULL && cmds[i+2] != NULL) {
                    if (pipe(fd[i+1]) < 0) {   // ��ǰpipe
                        perror("pipe");
                        exit(1);
                    }
                }
                //�����̹رյ�n���ܵ��Ķ�д�� 
                if (i > 0) {         // ����fork��ر���һ��ָ��ĸ�����pipe��д
                    close(fd[i-1][0]); // ˳��fork��1,fork��2,�رո���д
                    close(fd[i-1][1]); // ���if��д��i++����������ӽ��̡���
                }
                waitpid(pid, NULL, 0);           // �ȴ�ָ��ִ�н���
                i++;

            }
        }
    }
    return 0;
}

int split(char input_str[], char *cmds[])
{
    int i = 0; // ָ�����
    char *str = NULL, *saveptr = NULL;
    char *enter = NULL;
    
    for (i=0, str=input_str; ; i++, str=NULL){
        cmds[i] = strtok_r(str, "|", &saveptr);
        if (cmds[i] == NULL) {
            enter = strrchr(cmds[i-1], '\n');
            *enter = ' ';   // �滻��ĩβ���з�
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

