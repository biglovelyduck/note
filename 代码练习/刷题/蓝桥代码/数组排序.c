#include <stdio.h>
#include <stdlib.h>
#define N 10001
/*����һ������Ϊn�����У���������а���С�����˳�����С�1<=n<=200
�����ʽ
������һ��Ϊһ������n��
�����ڶ��а���n��������Ϊ�����������ÿ�������ľ���ֵС��10000��
�����ʽ
�������һ�У�����С�����˳��������������С�
��������
5
8 3 6 4 9
�������
3 4 6 8 9*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	int a[N]; 
	int i,j,temp;
    scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
		if(a[j]>a[j+1]){
			temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
		}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	return 0;
}
