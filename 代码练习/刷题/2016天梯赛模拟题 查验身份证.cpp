//2016天梯赛模拟题 查验身份证
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
int main(){
	int W[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[11]={'1' ,'0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	int n;
	cin>>n;
	string a[n];
	vector<string> v;	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=0;j<17;j++){
			sum+=(a[i][j]-'0')*W[j];
		}
		int mod=sum%11;
		if(a[i][17]!=M[mod])
			v.push_back(a[i]);
	}
	if(v.empty()) cout<<"All passed"<<endl;
	else{
		for(vector<string>::iterator it=v.begin();it!=v.end();it++)
			cout<<*it<<endl;
	}
	return 0;
}
