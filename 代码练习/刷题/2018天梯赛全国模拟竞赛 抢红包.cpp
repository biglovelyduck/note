//2018������ȫ��ģ�⾺�� ����� 
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
struct node{
	int id;
	double money;
	int num;	//	�����ĺ������ 
};
bool comp(node &a,node &b){
	if(a.money==b.money){
		if(a.num==b.num) return a.id<b.id;
		return a.num>b.num;
	}
	return a.money>b.money;
}
int main(){
	int N;
	cin>>N;
	double a[N+1]={0.0};	//a[i]��ʾ���Ϊi���˵�Ǯ ����ʼ��Ϊ0 
	int b[N+1]={0};	//b[i]��ʾ���Ϊi���������ĺ���ĸ��� 
	for(int i=1;i<=N;i++){	//ÿ���˷���� 
		int num;	//ÿ���˷��ĺ������
		cin>>num;
		double sum=0.0; 
		while(num--){
			int id;double money;
			cin>>id>>money;	//���Ϊid��������money��Ǯ 
			sum+=money;
			a[id]+=money;
			b[id]+=1; 
		} 
		a[i]-=sum;	//���Ϊi���˷���sumǮ�ĺ�� 
	}
	vector<node> v;
	node n;
	for(int i=1;i<=N;i++){
		n.id=i;
		n.money=a[i];
		n.num=b[i];
		v.push_back(n);
	}
	sort(v.begin(),v.end(),comp); 
	for(int i=0;i<N;i++)
		printf("%d %.2f\n",v[i].id,v[i].money/100);
	return 0;
}
