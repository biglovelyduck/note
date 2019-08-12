//2018天梯赛全国模拟竞赛 链表去重 
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

const int N=1e5+3;

struct node{
	int data;
	int next;
}list[N];

int main(){
	int head,n;	//头结点的地址和结点个数 
	cin>>head>>n;
	while(n--){
		int id;
		cin>>id;
		cin>>list[id].data>>list[id].next;
	}
	int ans[N],k1=0;
	int res[N],k2=0;
	bool vis[N];
	memset(vis,0,sizeof(vis));
	int p=head;
	while(p!=-1){
		int m=abs(list[p].data);
		if(!vis[m]){
			ans[k1++]=p;
			vis[m]=true;
		}
		else{
			res[k2++]=p;
		}
		p=list[p].next;
	}
	printf("%05d", head);
    for(int i = 1; i < k1; i++)
    {
        printf(" %d %05d\n%05d", list[ans[i-1]].data, ans[i], ans[i]);
    }
    printf(" %d -1\n", list[ans[k1-1]].data);
    if(k2 > 0)
    {
        printf("%05d", res[0]);
        for(int i = 1; i < k2; i++)
        {
            printf(" %d %05d\n%05d", list[res[i-1]].data, res[i], res[i]);
        }
        printf(" %d -1", list[res[k2-1]].data);
    }

	return 0;
}
