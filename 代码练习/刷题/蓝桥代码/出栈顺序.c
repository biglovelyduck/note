
/*X�����ر𽲾��������е�·���ǵ����ߡ�
һ���׿ǳ泵�ӣ���16���������ձ���Ⱥ󷢳����������������У�����ǰ�С�

·���и�����ͬ��ֻ����һ����ͨ��������ʱ�ļ��վ����ͼ��ʾ��
X����̫���壬Ҫ��ÿ��·���ĳ����������վ��Ҳ���ܲ����ͷ��У�Ҳ������ϸ��顣
�������������վ���뿪�Ĵ���������⽻����ô���ó����ٴ���·�󣬿��ܵĴ����ж����֣�

Ϊ�˷��������������վ����������������������
��Ȼ���������ֻ��1���������ܴ���1�֣�2�������ܴ���2�֣�3�������ܴ���5�֡�*/
 
#include <stdio.h>
#include <stdlib.h>

int f(int a,int b);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	for(i=1;i<=10;i++){
		printf("%d\n",f(i,0));
	}
	return 0;
}

//a:�ȴ���ջ��Ԫ��
//b��ջ�е�Ԫ�� 
int f(int a,int b){
	if(a==0) return 1;
	if(b==0) return f(a-1,1);
	return f(a-1,b+1)+f(a,b-1);
} 
