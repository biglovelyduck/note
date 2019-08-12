#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/*
解不定方程
97x + 127y = 1

欧几里得定理 ---- 辗转相除法  gcd
扩展欧几里得定理
Ax + By = gcd(A,B)
理论基础： gcd(A,B) == gcd(B,A%B)

求出特解后，通解很好表示

Ax + By = gcd(A,B)
Ax + By = gcd(B,A%B)
B(A/B x + y) + (A%B)x = gcd(B,A%B)
对比：
A/B x + y = 新x
x = 新y
*/


	// 返回最大公约数
	// xy: 顺便解出的xy
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
