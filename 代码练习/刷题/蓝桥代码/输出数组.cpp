/*6 �������Ԫ�أ�15 �֣�
����Ҫ���д���򣬶�˳������n��������˳�μ�������ǰ��֮�����ÿ������Ԫ�صĸ�ʽ��������

�����ʽ��

����ĵ�һ�и���������n��1<n��10�������һ�и���n������������Կո�ָ���

�����ʽ��

˳�μ�������ǰ��֮�����ÿ������Ԫ�صĸ�ʽ�����������ּ��һ����ĩ�����ж���ո�

����������

10
5 1 7 14 6 36 4 28 50 100
���������

-4 6 7
-8 30 -32
24 22 50*/
#include <cstdio>
#include <cstdlib>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,j;
	scanf("%d",&n);
	int a[10];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(j=1;j<n;j++){
		int del=a[j]-a[j-1];
		if(j+1%3==0) printf("%d",del);
		else printf("%d ",del);
		if(j%3==0&&j!=8) printf("\n");
	}
	return 0;
}
