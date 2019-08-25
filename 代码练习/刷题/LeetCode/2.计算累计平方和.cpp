//2.计算累计平方和
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int func(int num){
	vector<int> v;
	while(num){
		v.push_back(num%10);
		num=num/10;
	}	
	int res=0;
	for(int i=0;i<v.size();i++)
		res+=v[i]*v[i];
	return res;
}
int main(){
	int m;
	cin>>m;
	bool flag=false;
	while(m--){
		bool sss=false;
		map<int,int> mp;
		int num;
		cin>>num;
		if(func(num)==1||func(num)==10||func(num)==100
		||func(num)==1000||func(num)==10000||func(num)==1000000
		||func(num)==10000000){
			cout<<"true";
			sss=true;
			//break;
		}
		if(!sss){
		
			while(func(num)!=1){
			if(func(num)==1||func(num)==10||func(num)==100
		||func(num)==1000||func(num)==10000||func(num)==1000000
		||func(num)==10000000){
				//cout<<"true";
				flag=true;
				break;	
			}
			//cout<<"res:"<<func(num)<<endl;
			if(mp.count(func(num))>0){
				flag=false;
				break;
			}
			else
				mp[func(num)]=1;
			num=func(num);
			}
			if(flag) cout<<"true";
			else cout<<"false"; 
	}
	}
	return 0;
} 
