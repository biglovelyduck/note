//1.Ä©Î²µÄÊý
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
long long fun(int n){
	if(n==1) return 1;
	return n*fun(n-1);
}
/*
int main(){
	int n;
	cin>>n;
	long long num=fun(n);
	//cout<<num;
	while(num%10==0) num=num/10;
	cout<<num%10<<endl;
	return 0;
} */
int main(){
	int a[20001];			
	int temp,digit,n;
	cin>>n;
	a[0]=1;
	digit=1;
	for(int i=2;i<=n;i++)
	{
		int num=0;
		for(int j=0;j<digit;j++) 
		{
			temp=a[j]*i+num;
			a[j]=temp%10;
			num=temp/10;
		}
		while(num)
		{
			a[digit]=num%10;
			num=num/10;
			digit++;
		}
	}
	for(int i=0;i<digit;i++)
		if(a[i]!=0){
			cout<<a[i];
			break;
		} 
}
	

