
/*��3��Ӳ�ң��ֱ���3,4,5
��������ȡӲ�ҡ�
ÿ��ÿ��ֻ�ܴ�ĳһ����ȡ����������
������Ȩ��
ȡ�����һöӲ�ҵ�ΪӮ�ҡ�

����ȡӲ��һ�����ޱ�ʤ���з���*/

#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// ��ķ�ѵ�ģ2��(���)�ⷨ
/*
10
101
1100
1110
--------
0101
*/

	void f3(int* a,int len)
	{
		int sum = 0;
		int i; 
		for ( i = 0; i<len; i++)
		{
			sum ^= a[i];//���ĺ� 
		}
		if (sum == 0)
		{
			printf("����\n");
			return;
		}
		for ( i = 0; i<len; i++)
		{
			int x = sum ^ a[i];
			if (x < a[i])
				printf("%d --> %d\n", a[i], x);
		}
	}

	void main3()
	{
		int a[] = { 2, 5, 12, 14 };
		f3(a,4);
	}
