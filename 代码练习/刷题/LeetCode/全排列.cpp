//全排列
//1.DFS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;
const int N=13;	//n的最大值
int d[N];	//记录解
int v[N];	//记录每个节点是否被访问过
int n; 
int cmp1(const void *a,const void*b){
    char *s1=(char *)a;
    char *s2=(char *)b;
    return strcmp(s1,s2);
}
void dfs(int depth){
	if(depth>=n){
		for(int i=0;i<n;i++){
			cout<<d[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){	//每个数开始当头 
		if(v[i]==0) {
			v[i]=1;
			d[depth]=i;
			dfs(depth+1);
			v[i]=0;
		}
	}
}

//2.递归
void perm(int list[],int k,int m){
	if(k>m){
		copy(list,list+k,ostream_iterator<int>(cout," "));
		cout<<endl;
		return;
	}
	for(int i=k;i<=m;i++){			
		swap(list[k],list[i]);	//每个当前节点可以的取指 
		perm(list,k+1,m);
		swap(list[k],list[i]);
	}
} 

//3.算法
void permutation(char *str,int length){
	//cout<<*(str+1)<<endl;
	qsort(str,3,sizeof(char)*length,cmp1);
	cout<<" ok"<<endl;
	do{
		//cout<<"jinliale"<<endl;
		for(int i=0;i<length;i++)
			cout<<str[i]<<" ";
		cout<<endl;
	}while(next_permutation(str,str+length));
} 
int main(){
	cin>>n;
	memset(v,0,n);
	dfs(0);
	int list[]={1,2,3,4};
	perm(list,0,sizeof(list)/sizeof(int)-1);
	cout<<"---------------------------"<<endl;
	char* str="bac";
	//sort(str,str+strlen(str),cmp);
	//cout<<*str<<endl;
	permutation(str,3);
	return 0;
} 
