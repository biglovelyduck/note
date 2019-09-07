//散步
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
using namespace std; 
int main(){
	int N,M;
	cin>>N>>M;
	int D[M];
	set<int> s;
	for(int i=0;i<M;i++){
		cin>>D[i];
	}
	for(int i=0;i<N;i++){				//遍历每个顶点 
		int step=0;			
		for(int j=0;j<M;j++){			//遍历所有步数的组合 
			int a=0; 
			for(int k=0;k<2;k++){
				if(k==0) a=abs(D[i]);
				else a=-abs(D[i]);
			}
			if(i+step>=0&&i+step<N){
				s.insert(i);
			}			
		}		
	}
	cout<<s.size();
	return 0;
} 
