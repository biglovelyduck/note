//POJ 2139 Six Degrees of Cowvin Bacon
/*���ȿռ䣺Ϊ�������ȷָ����κ�һ��İ����֮����������˲��ᳬ��������¾���
��ţ�Ǿ�����һϵ�е�Ӱ�������������ȿռ䡷��Nͷţ������M����Ӱ��ͬһ����Ӱ�еĴ�Ǿ���1��
����С����֮�͡�*/
//Floyed_Warshall�㷨
#include <iostream>
#include <algorithm>
#include <iomanip> //�������ʽ�й� 
#include <cstring>

using namespace std;

#define MAX_V 300+16
int d[MAX_V][MAX_V];	//d[u][v]��ʾ��e=(u,v)��Ȩֵ�������ڵ�ʱ�������������d[i][i] = 0
int V;
int x[MAX_V];	//���ÿһ�е�ţ 

void floyed_warshall(){
	for(int k=0;k<V;k++)
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

int main(){
	int M;
	cin>>V>>M;
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<V;i++)
		d[i][i]=0;
	while(M--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>x[i];
			--x[i];	//ת��Ϊ�����±� 
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				d[x[i]][x[j]]=d[x[j]][x[i]]=1;	//˫����ͨ 
			}
		}
	}
	floyed_warshall();
	int ans=0x3f3f3f3f;
	for(int i=0;i<V;i++){
		int sum=0;
		for(int j=0;j<V;j++){
			sum+=d[i][j];
		}
		ans=min(ans,sum); 
	}
	cout<<100*ans/(V-1)<<endl;
	return 0;
} 
