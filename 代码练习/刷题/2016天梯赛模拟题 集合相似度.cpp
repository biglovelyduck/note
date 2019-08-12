//2016天梯赛模拟题 集合相似度 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)

set<int >s[55];	//s[i]表示集合i ，从1开始编号 
 
int main()
{
	int n,m,t,tmp,i,j,a,b;
	cin>>t;	//集合数 ，t也就是集合编号 
	for(i=1;i<=t;i++)	
	{
		cin>>n;	//每个集合的元素个数 
		for(j=0;j<n;j++)
		{
			cin>>tmp;
			s[i].insert(tmp);
		}
	}
	cin>>m;	//测试的组数 
	while(m--)
	{
		cin>>a>>b;	//；两个集合的编号 
		int a1=s[a].size(),b1=s[b].size(),sum=0;	//sum是相同的元素 
		set<int>::iterator it;
		for (it = s[a].begin(); it != s[a].end(); ++it)    
		{
		    if(s[b].find(*it)!=s[b].end())    //查询s[b]中是否含有元素*it,如果不含有则返回迭代器地址s[b].end()
		    	sum++;
		}
		//cout<<sum<<" "<<a1<<" "<<b1<<endl;
		printf("%.2lf%\n",(double)sum/(a1+b1-sum)*100);
	}
	return 0;
}

