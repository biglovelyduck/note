//2016������ģ���� �������ƶ� 
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

set<int >s[55];	//s[i]��ʾ����i ����1��ʼ��� 
 
int main()
{
	int n,m,t,tmp,i,j,a,b;
	cin>>t;	//������ ��tҲ���Ǽ��ϱ�� 
	for(i=1;i<=t;i++)	
	{
		cin>>n;	//ÿ�����ϵ�Ԫ�ظ��� 
		for(j=0;j<n;j++)
		{
			cin>>tmp;
			s[i].insert(tmp);
		}
	}
	cin>>m;	//���Ե����� 
	while(m--)
	{
		cin>>a>>b;	//���������ϵı�� 
		int a1=s[a].size(),b1=s[b].size(),sum=0;	//sum����ͬ��Ԫ�� 
		set<int>::iterator it;
		for (it = s[a].begin(); it != s[a].end(); ++it)    
		{
		    if(s[b].find(*it)!=s[b].end())    //��ѯs[b]���Ƿ���Ԫ��*it,����������򷵻ص�������ַs[b].end()
		    	sum++;
		}
		//cout<<sum<<" "<<a1<<" "<<b1<<endl;
		printf("%.2lf%\n",(double)sum/(a1+b1-sum)*100);
	}
	return 0;
}

