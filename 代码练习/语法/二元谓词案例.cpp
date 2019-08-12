#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
void current(int &v)
{
	cout << v << " ";
}

bool MyCompare(const int &a, const int &b)
{
	return a < b;
}
int  main()
{
	vector<int> v(10);//10个大小的vector数组 

	for (int i=0; i<10; i++)
	{
		v[i] = rand() % 100;//生成0-100随机数 
	}
//for_each牛逼！ 
	for_each(v.begin(), v.end(), current);//对每一个元素执行current函数 
	printf("\n");
	sort(v.begin(), v.end(), MyCompare );

	printf("\n");
	for (int i=0; i<10; i++)
	{
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;
}

