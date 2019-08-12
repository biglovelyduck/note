//ccf2017-12 ×îÐ¡²îÖµ 
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=1001;
int main(){
	int n;
	cin>>n;
	vector<int> v(n); 
//	for(int i=0;i<v.size();i++)
//		cout<<v[i]<<" ";
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int min=*(v.end()-1)-v.front();
	//cout<<"min:"<<min<<endl;
	for(int i=1;i<n;i++){
		if((v[i]-v[i-1])<=min) min=v[i]-v[i-1];
	}
	cout<<min<<endl;
}*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int main()
{
	int n,k;
	queue<int> q;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	q.push(i);
	int t=1,u=1;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(t%k==0||t%10==k);
		else q.push(u);
		t++;
	}
	printf("%d\n",u);
	return 0;
}

