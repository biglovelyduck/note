#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/*
�ⲻ������
97x + 127y = 1

ŷ����ö��� ---- շת�����  gcd
��չŷ����ö���
Ax + By = gcd(A,B)
���ۻ����� gcd(A,B) == gcd(B,A%B)

����ؽ��ͨ��ܺñ�ʾ

Ax + By = gcd(A,B)
Ax + By = gcd(B,A%B)
B(A/B x + y) + (A%B)x = gcd(B,A%B)
�Աȣ�
A/B x + y = ��x
x = ��y
*/


	// �������Լ��
	// xy: ˳������xy
	int e_gcd(int A, int B, int* xy,int len)
	{
		if (B == 0)
		{
			xy[0] = 1;
			xy[1] = 0;
			return A;
		}

		int ans = e_gcd(B, A%B, xy,len);
		int t = xy[0];
		xy[0] = xy[1];
		xy[1] = t - A / B * xy[0];
		return ans;
	}

	void main5()
	{
		int* xy =(int *) malloc(sizeof(int)*2);
		int a = e_gcd(97, 127, xy,2);
		printf("%d \n", a);
		printf("%d " " %d \n", xy[0], xy[1]);
	}
