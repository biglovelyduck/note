/*��������
����n�������ҳ���n���������ֵ����Сֵ���͡�

�����ʽ
��һ��Ϊ����n����ʾ���ĸ�����

�ڶ�����n������Ϊ������n������ÿ�����ľ���ֵ��С��10000��

�����ʽ
������У�ÿ��һ����������һ�б�ʾ��Щ���е����ֵ���ڶ��б�ʾ��Щ���е���Сֵ�������б�ʾ��Щ���ĺ͡�
��������
5
1 3 -2 4 5
�������
5
-2
11
���ݹ�ģ��Լ��
1 <= n <= 10000��*/ 
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,max,min,sum;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]); 
	}	
	max=a[0];
	min=a[0];
	sum=a[0];
	for(i=1;i<n;i++){
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
		sum+=a[i];
	}
	printf("%d\n%d\n%d",max,min,sum);
	return 0;
}
