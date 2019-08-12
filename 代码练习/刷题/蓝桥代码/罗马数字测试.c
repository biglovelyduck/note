#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*函数原型：extern char *strchr(char *str,char character)
参数说明：str为一个字符串的指针，character为一个待查找字符。
        
所在库名：#include <string.h>
  
函数功能：从字符串str中寻找字符character第一次出现的位置。
  
返回说明：返回指向第一次出现字符character位置的指针，如果没找到则返回NULL。

其它说明：还有一种格式char *strchr( const char *string, int c )，这里字符串是以int型给出的。*/
int main(int argc, char *argv[]) {
	int n;
	int i,j;
	int num=0;
	//char a[100][100];
	//scanf("%d",&n);	
	//getchar();
	char b[1000];
	int sum=0;
	gets(b);
	for(i=0;i<strlen(b);i++){
		//printf("%c",b[i]);
		if(b[i]=='I') sum+=1;
		if(b[i]=='V') sum+=5;
		if(b[i]=='X') sum+=10;
		if(b[i]=='L') sum+=50;
		if(b[i]=='C') sum+=100;
		if(b[i]=='D') sum+=500;
		if(b[i]=='M') sum+=1000;
	}
	printf("%d",sum);
	/*while(n--){
	    gets(a[num++]);
		//scanf("%s",a[num++]);
	}
	printf("曹尼玛啊\n");
	for(i=0;i<num;i++){
		for(j=0;j<strlen(a[i]);j++){
		
		//	puts(a[i]);
			//printf("%s",a[i]);
			printf("%c",a[i][j]);
			printf("magebi\n");
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<strlen(a[i]);j++){
			int sum=0;
			char *c=strchr(a[i],a[i][j]);
			int p=c-a[i];//获取j对应的字符位置 
			if(a[i][p]=='I') sum+=1; 
			if(a[i][p]=='V') sum+=5;
			if(a[i][p]=='X') sum+=10;
			if(a[i][p]=='L') sum+=50;
			if(a[i][p]=='C') sum+=100;
			if(a[i][p]=='D') sum+=500;
			if(a[i][p]=='M') sum+=1000;
			
			//补偿
			if(strstr(a[i],"IV")) sum-=2;
			if(strstr(a[i],"IX")) sum-=2;
			if(strstr(a[i],"XL")) sum-=20;
			if(strstr(a[i],"XC")) sum-=20; 
			if(strstr(a[i],"CD")) sum-=200;
			if(strstr(a[i],"CM")) sum-=200;
		}
	}*/
	return 0;
}