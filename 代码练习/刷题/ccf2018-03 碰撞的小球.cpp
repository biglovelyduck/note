//ccf2018-03 ��ײ��С�� 
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=100+1;	//n,t
const int MAX_L=1000+1;	//L
int n,L,t;	//n����,L���ȣ�tʱ�� 
int a[MAX_N],v[MAX_N];
typedef long long ll;	
int main(){
	cin>>n>>L>>t;
	for(int i=0;i<n;i++){
		cin>>a[i];	//��ʼʱn��С���λ�ã�a[i]��ֵλ��0��L֮�� 
		v[i]=1;	//ÿ��λ�õ��ٶ�
		if(a[i]==L) v[i]=-1; 
	}
	while(t--){
		for(int i=0;i<n;i++){	//����ÿ��С�� 
			a[i]+=v[i];
			for(int j=0;j<n&&j!=i;j++){
				if(a[i]==a[j]){
					v[i]=-v[i];
					v[j]=-v[j];
				}
			}
			if(a[i]==L||a[i]==0)
				v[i]=-v[i];
		}
	}
	for(int i=0;i<n;i++)	cout<<a[i]<<" ";
}
