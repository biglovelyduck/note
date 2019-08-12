//2018 天梯赛题集分享码  小字辈
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
/* 为什么自己写的会有错误？套你猴子 
const int MAX_N=100001;
int N;
int p[MAX_N],r[MAX_N];
int cs[MAX_N];
void init(int n){
	for(int i=1;i<=N;i++){
		p[i]=i;
		r[i]=1;
	}
}
int find(int x){
	if(p[x]==x) return x;
	else return p[x]=find(p[x]);
}
int find2(int x,int root){	//找到根的向上查找的次数 
	int num=0;
	 while(p[x]!=root){
	 	num++;
	 	x=p[x];
	 }
	 return num;
}
void unite(int x,int y){
	x=find(x); 
	y=find(y);	//找到各自的根
	if(x==y) return;	//根相同无需合并
	if(r[x]<r[y]){
		p[x]=y;
	}
	else{
		p[y]=x;
		if(r[x]==r[y]) r[x]++;
	} 
}
void unite1(int x,int y){
	//x为父，y为子
	r[x]=r[y]+1; 
}
bool same(int x,int y){
	return find(x)==find(y);
}
int main(){
	cin>>N;
	init(N);
	int root;
	for(int i=1;i<=N;i++){
		cin>>p[i];
		if(p[i]!=-1)
			unite1(p[i],i);
		else root=i;
	}
	cout<<r[root]<<endl;
	vector<int> v;
	for(int i=1;i<=N;i++){
		if(i!=root&&2==find2(i,root)) v.push_back(i);
	}
	for(int i=0;i<v.size();i++){
		if(i==v.size()-1) cout<<v[i];
		else cout<<v[i]<<" ";
	}
	return 0;
} */

/*参考柳婼大神的代码：
分析：广度优先搜索最长路径问题（深搜可能会超时），老祖宗的父母即root的id用0表示 ，
队列中的结构体成员分别是，人的编号和所处层数。 */

struct peo{
	int id,level;
};
int main(){
	int n,temp,maxlevel=-1;
	queue<peo> q;
	vector<peo> ans;
	cin>>n;
	vector<vector<int> > v(n+1);
	for(int i=1;i<=n;i++){
		cin>>temp;
		if(temp==-1) temp=0;
		v[temp].push_back(i);
	}
	q.push({0,0});
	while(!q.empty()){
		peo p=q.front();
		int id=p.id,level=p.level;
		if(p.level>maxlevel) maxlevel=p.level;
		ans.push_back(p);
		q.pop();
		for(int i=0;i<v[id].size();i++)
			q.push({v[id][i],level+1});
	}
	cout<<maxlevel<<endl;
	for(int i=0;i<ans.size();i++){
		if(ans[i].level==maxlevel){
			cout<<ans[i].id;
			if(i!=ans.size()-1) cout<<" ";
		}
	}
	return 0;
}
