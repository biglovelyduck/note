//2016������ģ����  �Ƚϴ�С 
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a[3];
	for(int i=0;i<3;i++)
		cin>>a[i];
	sort(a,a+3);
	for(int i=0;i<3;i++){
		if(i==2) cout<<a[i];
		else cout<<a[i]<<"->" ;
	}
	return 0;
} 
