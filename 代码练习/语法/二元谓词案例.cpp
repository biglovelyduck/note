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
	vector<int> v(10);//10����С��vector���� 

	for (int i=0; i<10; i++)
	{
		v[i] = rand() % 100;//����0-100����� 
	}
//for_eachţ�ƣ� 
	for_each(v.begin(), v.end(), current);//��ÿһ��Ԫ��ִ��current���� 
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

