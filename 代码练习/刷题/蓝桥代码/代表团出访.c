/*
X����Ҫ�ɳ�һ��5����ɵĹ۲���ǰ��W�ǡ�
���У�
A���������ɳ�4�ˡ�
B���������ɳ�2�ˡ�
C���������ɳ�2�ˡ�
D���������ɳ�1�ˡ�
E���������ɳ�1�ˡ�
F���������ɳ�3�ˡ�
��ô��������W�ǵĹ۲��Ż��ж����ֹ���Ĳ�ͬ����أ�*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	//a����ȡ���������޶�
	//k: ��ǰ����λ��,��ǰ�� 
	//n: Ŀ������
	//s: �Ѿ������Ĵ����ų�Ա 
	void fk(int*a,int num1, int k, int n, char *s,int num2)//��kλ�������ǰ����������� 
	{
		int i; 
		if (k == num1){//k=num1=0
			if (n == 0) 
				printf("%s\n",s);
			return;
		}
		char *s2 = malloc(sizeof(char)*num2);
		strcpy(s2, s);//s2��ʱ�洢��������� 

		for (i = 0; i <= a[k]; i++)
		{
			fk(a, num1, k + 1, n - i, s2, num2);
			
			char x=k + 'A';
			char arr[10] = { 0 };
			arr[0] = x;
			strcat(s2, arr);			
			num2++;
		}
	}

	void main()
	{
		int a[] = { 4, 2, 2, 1, 1, 3 };

		fk(a,6, 0, 5, "",0);
	}
