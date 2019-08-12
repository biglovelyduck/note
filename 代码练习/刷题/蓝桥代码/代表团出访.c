/*
X星球要派出一个5人组成的观察团前往W星。
其中：
A国最多可以派出4人。
B国最多可以派出2人。
C国最多可以派出2人。
D国最多可以派出1人。
E国最多可以派出1人。
F国最多可以派出3人。
那么最终派往W星的观察团会有多少种国别的不同组合呢？*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	//a：可取最大个数的限定
	//k: 当前考虑位置,当前国 
	//n: 目标名额
	//s: 已经决定的代表团成员 
	void fk(int*a,int num1, int k, int n, char *s,int num2)//从k位置输出当前数组的最多组合 
	{
		int i; 
		if (k == num1){//k=num1=0
			if (n == 0) 
				printf("%s\n",s);
			return;
		}
		char *s2 = malloc(sizeof(char)*num2);
		strcpy(s2, s);//s2暂时存储决定的组合 

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
