#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*����ԭ�ͣ�extern char *strchr(char *str,char character)
����˵����strΪһ���ַ�����ָ�룬characterΪһ���������ַ���
        
���ڿ�����#include <string.h>
  
�������ܣ����ַ���str��Ѱ���ַ�character��һ�γ��ֵ�λ�á�
  
����˵��������ָ���һ�γ����ַ�characterλ�õ�ָ�룬���û�ҵ��򷵻�NULL��

����˵��������һ�ָ�ʽchar *strchr( const char *string, int c )�������ַ�������int�͸����ġ�*/
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
	printf("�����갡\n");
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
			int p=c-a[i];//��ȡj��Ӧ���ַ�λ�� 
			if(a[i][p]=='I') sum+=1; 
			if(a[i][p]=='V') sum+=5;
			if(a[i][p]=='X') sum+=10;
			if(a[i][p]=='L') sum+=50;
			if(a[i][p]=='C') sum+=100;
			if(a[i][p]=='D') sum+=500;
			if(a[i][p]=='M') sum+=1000;
			
			//����
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