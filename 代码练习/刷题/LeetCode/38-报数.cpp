//38-±¨Êý
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
struct Node{
	int data;
	Node* left;
	Node* right;
};
void fun1(Node *&n){
	printf("%d\n",n);
}
class Solution {
	vector<string> v={"1","11","21","1211","111221"};
public:
    string countAndSay(int n) {
         if(n<=5) return v[n-1];
         for(int i=6;i<=n;i++){
         	string pre=v[v.size()-1];
         	string s=""+97; 			//cout<<s<<endl;		
			for(int j=0;j<pre.size();j++){
				int count=1;
				while(j<pre.size()-1&&pre[j]==pre[j+1]){
					count++;
					j++;
				}
				s+=to_string(count)+pre[j];		//cout<<"count:"<<count<<" s:"<<s<<endl;
			} 
			v.push_back(s);			
		 }
		 return v[n-1];
    }
}; 

int main(){
	Solution s;
//	for(int i=1;i<=30;i++){
//		cout<<s.countAndSay(i)<<endl;
//	}
	cout<<s.countAndSay(6)<<endl;
	return 0;
}
