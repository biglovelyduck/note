/*��������
����������ֳ�Pascal�����Σ����ĵ�i+1����(a+b)i��չ��ʽ��ϵ����

����
����һ����Ҫ�����ǣ��������е�ÿ�����ֵ����������ϵ�������ӡ�

����
�����������������ε�ǰ4�У�

����
   1

����
  1 1

����
 1 2 1

����
1 3 3 1

����
����n���������ǰn�С�

�����ʽ
�������һ����n��

�����ʽ
�����������ε�ǰn�С�ÿһ�д���һ�еĵ�һ������ʼ����������м�ʹ��һ���ո�ָ����벻Ҫ��ǰ���������Ŀո�
��������
4
�������
1
1 1
1 2 1
1 3 3 1
���ݹ�ģ��Լ��
1 <= n <= 34��*/

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int level,i,j,length=0;
	scanf("%d",&level);
	for(i=0;i<level;i++){
		for(j=0;j<=length;j++){
			printf("%d ",f(i,j));
		if(length==level){
			break;
		}
		}
		length=length+1;
		printf("\n");
	}
	
	return 0;
}
int f(int m,int n){
	if(m==0) return 1;
	if(m==n||n==0) return 1;
	return f(m-1,n)+f(m-1,n-1);
} 
