#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char ** f(char * s);

int main(int argc, char *argv[]) {
	char arr[]={'A','B','C'};
	printf("%s",f(arr)); 
	return 0;
}

char ** f(char * s){
	int i,k,index=0,index2=0;
	char ** s1=(char **)malloc(sizeof(char)*10);//��������µ����� 
	char ** t=(char **)malloc(sizeof(char*)*10);//��������Ӵ����� 
	
	if(strlen(s)==1)
	    
	    return s;
	
	char *s_zuo=(char *)malloc(sizeof(char)*3);//��������Ӵ�����Ϳ�ͷ�������Ӵ� 
	char *s_you=(char *)malloc(sizeof(char)*3);
	for(i=0;i<strlen(s);i++){
		char c=s[i];//ȡ��������Ϊ��ͷ���ַ� 
		strncpy(s_zuo,s,i);
		strncpy(s_you,s+i+1,strlen(s));
		strcat(s_zuo,s_you);
		t[index++]=f(s_zuo);
        s1[index2++][1]=c;
        for(k=0;k<strlen(*t);k++)
            strcat(s1[index2-1],t[k]);
	} 
	return s1;
	
}
