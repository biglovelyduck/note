/*С���μ���ѧУ��Ȥζ�˶��ᣬ���е�һ����Ŀ�ǣ������ӡ�
���ϻ���һЩ���ӣ�ÿ��������дһ���֣�������ʾ����Ҳ�ɲμ���ͼ��

����������
����������
����������
�������л�

����ʱ����վ�����Ͻǵ�д�š��ӡ��ֵĸ�������Ժ���������������ڵĸ���������������Խǵĸ��ӻ�����λ�á�һֱҪ�����������ֽ�����

Ҫ��������·�߸պù��ɡ��������������л�����仰��
�������С����һ����һ���ж����ֿ��ܵ���Ծ·���أ�*/ 

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int f(int x,int y); 

int main(int argc, char *argv[]) {
	printf("%d",f(5,4)); 
	return 0;
}
//��ĳ��λ����һ���ж������߷�
 
int f(int x,int y){
	if(x==1||y==1) return 1;
	return f(x-1,y)+f(x,y-1);
}
