//2016天梯赛模拟题集 N个数求和
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
struct node{
	ll a;	//分子
	ll b;	//分母 
	node(){
	}
	node(ll a,ll b):a(a),b(b){
	}
};
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
node tongfen(node n){
	int gys;
	if(n.a<0)
		gys=gcd(-n.a,n.b);
	else 
		gys=gcd(n.a,n.b);
	return node(n.a/gys,n.b/gys);
}
int main(){
	int n;
	cin>>n;
	node a[n];
	for(int i=0;i<n;i++)
		scanf("%lld/%lld",&a[i].a,&a[i].b);
	node temp=a[0];
	for(int i=1;i<n;i++){
		ll fz1=temp.a*a[i].b;	
		ll fz2=a[i].a*temp.b;
		ll fz=fz1+fz2;
		ll fm=temp.b*a[i].b;
		temp=tongfen(node(fz,fm));
		//cout<<"temp:"<<temp.a<<"/"<<temp.b<<endl;
	}
	ll zs=temp.a/temp.b;
	if(zs==0)
		cout<<temp.a<<"/"<<temp.b<<endl;
	else if(zs!=0&&temp.a%temp.b!=0)
		cout<<zs<<" "<< temp.a%(temp.b)<<"/"<<temp.b<<endl;
	else
		cout<<zs<<endl;
	return 0;
}


