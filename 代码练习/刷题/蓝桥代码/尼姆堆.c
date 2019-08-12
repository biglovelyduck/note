
/*有3堆硬币，分别是3,4,5
二人轮流取硬币。
每人每次只能从某一堆上取任意数量。
不能弃权。
取到最后一枚硬币的为赢家。

求先取硬币一方有无必胜的招法。*/

#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// 尼姆堆的模2加(异或)解法
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
			sum ^= a[i];//异或的和 
		}
		if (sum == 0)
		{
			printf("输了\n");
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
