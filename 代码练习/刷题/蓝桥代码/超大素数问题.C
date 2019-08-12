#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
筛到第x个素数，需要数组准备多大?
素数分布定理：不大于n的素数的个数为：n / ln(n)
double t = 100;
while(t / Math.log(t) < x) t *= 1.1;
System.out.println(t);

第1个素数是2，第2个素数是3，...
求第100002（十万零二）个素数

*/

	int  main()
	{
		int N = 1500 * 1000;//N为要测试的数 
		int x = 100002;
		int i;

		int* a = (int *)malloc(N*sizeof(int));	//0为素数，1为非素数 
		memset(a, 0, N*sizeof(int));//初始全为素数 
		for ( i = 2; i<N / 2; i++)
		{
			if (a[i] == 1) 
				continue; //越过已经找到的合数
			for (int k = 2; k <= N / i; k++)
			{
				if (i*k<N) 
					a[i*k] = 1;
			}
		}

		int m = 0;//存放找到的素数的个数 

		for ( i = 2; i<N; i++)
		{
			if (a[i] == 0)
			{
				m++;
				if (m == x) 
					printf("%d \n",i);
			}
		}


		printf("m= %d" , m);
		return 0;
	}


