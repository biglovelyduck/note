#include <stdio.h>
#include <stdlib.h>//包含对堆内存的操作 
#include <string.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char * children;

char * f(char *s);
char * get_children(char * string,int index);

int main(int argc, char *argv[]) {
	char * string="abcde";
	printf("%s",f(string));	
	return 0;
}
char * f(char *s){
	if(strlen(s)<=1) return s;
	char s1[]={s[0],'\0'};
	return strcat(f(get_children(s,1)),s1);
} 
char * get_children(char * string,int index){	
	strncpy(children,string+index,strlen(string));
	children[strlen(string)]='\0';
	return children;
}
