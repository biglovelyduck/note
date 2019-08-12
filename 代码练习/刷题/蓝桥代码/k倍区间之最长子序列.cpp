#include <iostream>
#include <unordered_map>
using namespace std;
const int maxn=100000;
int a[maxn+1],s[maxn+1];
int n,k,maxAns;
unordered_map<int,int> lmost,rmost; //����һ��ǰ׺��������������ҵ��±�
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=0;
	s[0]=0;
	for(int i=0;i<k;i++){
		lmost[i]=n+1;
		rmost[i]=-1;
	}
	lmost[0]=rmost[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=(s[i-1]+a[i])%k;
		if(lmost[s[i]]>i) lmost[s[i]]=i;
		if(rmost[s[i]]<i) rmost[s[i]]=i;
	}
	maxAns=0;
	for(int i=0;i<k;i++){
		if(rmost[s[i]]-lmost[s[i]]>maxAns) maxAns=rmost[s[i]]-lmost[s[i]];	
	}
	cout<<maxAns;
	return 0;
}
