//�����ָ��
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
	/*
	int a[4][4]={
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	int b[2][2]={1,2,3,4};
	int *p1=a[0];
	int *p2=&a[0][0];
	cout<<*p1<<endl;
	cout<<*p1++<<endl;
	cout<<*p1<<endl; 
	*p1++=*p2++;
	cout<<*(p1-1)<<endl;
	cout<<*p1<<endl;
	
//	cout<<*p1<<endl;
//	cout<<*p2<<endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
			cout<<b[i][j]<<" ";
	}*/
	//char str[6] = "abcxyz";			//sizeof��ȷ�����󲻳� 
	char *str1=new char[5];
	char *str2="bbbbbbbbbbbbb";
	char str3[5]={'a','b','\0','a','a'};
	//*str2='a';
	//strcpy(str1,str2);
	cout<<"------------------"<<endl;
	cout<<strlen(str1)<<endl;
	cout<<sizeof(str1)<<endl; 	//���������ָ�룬�����ָ��ռ�м����ֽ� 
	/*
	1. strlen �Ǻ�����sizeof ���������

	2. strlen ���������ַ���ʵ�ʳ��ȣ���'\0' ��������sizeof ���������ַ��ķ����С��*/
	char str4[20]="hello";
	cout<<strlen(str4)<<endl;
	cout<<sizeof(str4)<<endl;
	*str1='a';
	*(str1+1)='\0';
	printf("%s\n",str1);
	fprintf(stdout,"�����%s\n",str1);
	cout<<'%20'<<endl;
}
 
