
/*��������
������һ����ΪN(1<=��<=10)�ĵذ壬�������ֲ�ͬ��ש��һ�ֳ���Ϊ1����һ�ֳ���Ϊ2����Ŀ���ޡ�Ҫ���������ΪN�ĵذ�������һ���ж����ֲ�ͬ���̷���
�������磬����Ϊ4�ĵ���һ��������5���̷���
����4=1+1+1+1
����4=2+1+1
����4=1+2+1
����4=1+1+2
����4=2+2
��������õݹ�ķ�������������⡣
�����ʽ
����ֻ��һ����N������ذ�ĳ���
�����ʽ
�������һ�������������в�ͬ�Ĵ�ש�̷ŷ���������
��������*/
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int n;
	scanf("%d",&n);
	printf("%d",putBrick(n));
	return 0;
}

int putBrick(int n){
	if(n<1) return 0;
	if(n==1) return 1;
	if(n==2) return 2;
	return putBrick(n-1)+putBrick(n-2);
} 
