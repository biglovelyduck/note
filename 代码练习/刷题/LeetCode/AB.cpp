//AB
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
void count(int a,int b,int p,int q,vector<int> &res,int sum){
	if(a<b&&p<b){
		a+=p;
		sum+=1;
		count(a,b,p,q,res,sum);
		a-=p;
		p*=q;
		count(a,b,p,q,res,sum);
	}
	else{
		 res.push_back(sum);
		 //cout<<"´ËÊ±a£º"<<a<<"  b:"<<b<<"   p£º"<<p<<endl;
		 //return;
	}
}
int main(){
//	int a,b,p,q;
//	cin>>a>>b>>p>>q;	
//	int sum=0;
//	while(a+p*q<b){
//		p*=q;
//		a+=p;
//		sum++;
//	}
//	sum++;
//	while(a+p<b){
//		a+=p;
//		sum++;	
//	}
//	cout<<sum+1<<endl;	
	vector<int> res;
	count(1,8,2,3,res,0);
	for(auto i:res) cout<<i<<" ";
	return 0;
}
