//2019天梯赛模拟题集  链表去重 
#include <algorithm> 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
/*
const int N=1e5+1;
struct node{
	int value;
	int next;
}list[N];
int main(){
	int head,n;
	bool visited[N]={false};
	int ans[N],res[N],k1=0,k2=0;
	cin>>head>>n;
	while(n--){
		int id;
		cin>>id;
		cin>>list[id].value>>list[id].next;
	}
	int p=head;
	while(p!=-1){
		int m=abs(list[p].value);
		if(!visited[m]){
			ans[k1++]=p;
			visited[m]=true;
		}
		else{
			res[k2++]=p;
		}
		p=list[p].next;
	}
	printf("%05d", head);
    for(int i = 1; i < k1; i++)
    {
        printf(" %d %05d\n%05d", list[ans[i-1]].value, ans[i], ans[i]);
    }
    printf(" %d -1\n", list[ans[k1-1]].value);
    if(k2 > 0)
    {
        printf("%05d", res[0]);
        for(int i = 1; i < k2; i++)
        {
            printf(" %d %05d\n%05d", list[res[i-1]].value, res[i], res[i]);
        }
        printf(" %d -1", list[res[k2-1]].value);
    }

	return 0; 
}*/
const int N=1e5+1;
struct node{
	int v;
	int n;
}list[N];
int main(){
	int head,n;
	cin>>head>>n;
	while(n--){
		int id;
		cin>>id;
		cin>>list[id].v>>list[id].n;
	}
	int p=head;
	vector<int> v1,v2;
	bool visited[N]={false};
	while(p!=-1){
		int m=abs(list[p].v);
		if(!visited[m]){
			v1.push_back(p);
			visited[m]=true;
		}
		else{
			v2.push_back(p);
		}
		p=list[p].n;
	}
	printf("%05d",head);
	for(int i=1;i<v1.size();i++){
		printf(" %d %05d\n%05d",list[v1[i-1]].v,v1[i],v1[i]);
	}
	printf(" %d -1\n",list[v1[v1.size()-1]].v);
	if(v2.size()>0){
		printf("%05d",v2[0]);
		for(int i=1;i<v2.size();i++){
			printf(" %d %05d\n%05d",list[v2[i-1]].v,v2[i],v2[i]); 
		}
		printf(" %d -1\n",list[v2[v2.size()-1]].v);
	}
	return 0;
}
