//2016������ģ���� ����ָ��
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	cin>>n;
	int result=1;
	for(int i=0;i<n;i++)
		result*=2;
	printf("2^%d = %d\n",n,result);
	return 0;
}
