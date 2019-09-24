//2.求询问次数 
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
long long myPow(int x,long long n){
		long long ans=1;
		long long current_product=x;
		for(long long i=n;i;i/=2){
			if(i%2) ans=ans*current_product;
			current_product=current_product*current_product;
		}
		return ans;
}
int main(){
	long long n;
	cin>>n;
	long long Max=myPow(2,n);
	vector<long long> v;
	long long a=1;	
	while(a<Max){
		v.push_back(a);
		a*=2;
	}
	//for(auto i:v) cout<<i<<endl;
	long long count=0;
	do{
		count++;
//		for(auto i:v) cout<<i<<" ";	
//		cout<<endl;
	}while(next_permutation(v.begin(),v.end()));
	cout<<count%(1000003)<<endl;
	return 0;
}
