/*������۹������˻Ի͵����������������ǵ����ֱ�ʾ����ȷ��Щ�����������ڱ�ʾ������ʱ�����ڿ�������ֱ�������ܣ��������ִ�����ʹ���ˡ�
֮����������������Ϊ������ʾ�����˵����������⣬������Ϊһ���ڽ̵�ԭ�򣬵�ʱ���ڽ̽�ֹ�������г���0�ĸ��
�������ֵı�ʾ��Ҫ�������¼����������ţ�

I --> 1
V --> 5
X --> 10
L --> 50
C --> 100
D --> 500
M --> 1000

�������ֻ����һ��1000���ڵ����ֵı�ʾ����
���������ظ����ٴΣ��ͱ�ʾ���ٱ�������ظ�3�Ρ�
���磺CCC��ʾ300  XX��ʾ20����150������LLL��ʾ����������������I X C M��

������ڼ���Ĵ�λ���ң�С��λ���󣬱�ʾ��λ�п۳�С��λ��
���磺IX��ʾ9  IV��ʾ4  XL��ʾ40 
49 = XLIX
    
�����ʾ���μ��±����ҵ���������    
I = 1 
II = 2
III = 3
IV = 4
V = 5
VI = 6
VII = 7
VIII = 8
IX = 9 
X = 10
XI = 11
XII = 12
XIII = 13
XIV = 14
XV = 15
XVI = 16
XVII = 17
XVIII = 18
XIX = 19
XX = 20
XXI = 21
XXII = 22
XXIX = 29
XXX = 30
XXXIV = 34
XXXV = 35
XXXIX = 39
XL = 40
L = 50
LI = 51
LV = 55
LX = 60
LXV = 65
LXXX = 80
XC = 90
XCIII = 93
XCV = 95
XCVIII = 98
XCIX = 99
C = 100
CC = 200
CCC = 300
CD = 400
D = 500
DC = 600
DCC = 700
DCCC = 800
CM = 900
CMXCIX = 999

����Ŀ��Ҫ���ǣ����д�������û��������ɸ��������ִ������������Ӧ��ʮ���Ʊ�ʾ��

�����ʽ�ǣ���һ��������n,��ʾ��������n����������(n<100)��
�Ժ�ÿ��һ���������֡��������ִ�С������999��
Ҫ��������n�У������������ֶ�Ӧ��ʮ�������ݡ�

���磬�û����룺
3
LXXX
XCIII
DCCII

�����Ӧ�������
80
93
702*/
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
	int sum[1000];
	scanf("%d",&n);	
	getchar();
	int num=0;
	char a[100][100];
	char b[1000];
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
	
	for(i=0;i<n;i++){
		for(j=0;j<strlen(a[i]);j++){
			
			//char *c=strchr(a[i],a[i][j]);
			//int p=c-a[i];//��ȡj��Ӧ���ַ�λ�� 
			if(a[i][j]=='I') sum[i]+=1; 
			if(a[i][j]=='V') sum[i]+=5;
			if(a[i][j]=='X') sum[i]+=10;
			if(a[i][j]=='L') sum[i]+=50;
			if(a[i][j]=='C') sum[i]+=100;
			if(a[i][j]=='D') sum[i]+=500;
			if(a[i][j]=='M') sum[i]+=1000;
			
			//����
			if(strstr(a[i],"IV")) sum[i]-=2;
			if(strstr(a[i],"IX")) sum[i]-=2;
			if(strstr(a[i],"XL")) sum[i]-=20;
			if(strstr(a[i],"XC")) sum[i]-=20; 
			if(strstr(a[i],"CD")) sum[i]-=200;
			if(strstr(a[i],"CM")) sum[i]-=200;
		}
	}
	for(i=0;i<num;i++){
		
			//puts(a[i]);
			printf("%d",sum[i]);
			printf("\n");
		
	}*/ 
	return 0;
}
