#include <stdio.h>
#include <stdlib.h>
#define N 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	char a1[N],b1[N]; 
	for(i=0;i<100;i++) {
		int a=i*i*i;
		int b=a*i;
		
		//itoa(num_int, str_int, 10);  //������num_intת���ַ���str_int
		//����+��0�� ת��Ϊ�ַ�
//�� itoa()��������ֵת��Ϊ�ַ�����
//�� ltoa()����������ֵת��Ϊ�ַ�����
//�� ultoa()�����޷��ų�����ֵת��Ϊ�ַ�����
//�� gcvt()������������ת��Ϊ�ַ�����ȡ�������롣
//�� ecvt()����˫���ȸ�����ֵת��Ϊ�ַ�����ת������в�����ʮ����С���㡣
//�� fcvt()��ָ��λ��Ϊת�����ȣ�����ͬecvt()�� 

//�� atof()�����ַ���ת��Ϊ˫���ȸ�����ֵ��
//�� atoi()�����ַ���ת��Ϊ����ֵ��
//�� atol()�����ַ���ת��Ϊ������ֵ��
//�� strtod()�����ַ���ת��Ϊ˫���ȸ�����ֵ�������治�ܱ�ת��������ʣ�����֡�
//�� strtol()�����ַ���ת��Ϊ����ֵ�������治�ܱ�ת��������ʣ�����֡�
//�� strtoul()�����ַ���ת��Ϊ�޷��ų�����ֵ�������治�ܱ�ת��������ʣ�����֡�
        //�����ַ�-'0 'Ϊ���� 
        itoa(a,a1,10);
        itoa(b,b1,10);
        if(strlen(a1)==4&&strlen(b1)==6) 
        printf("%d= %d%d\n",i,a,b);
	}
	return 0;
}
