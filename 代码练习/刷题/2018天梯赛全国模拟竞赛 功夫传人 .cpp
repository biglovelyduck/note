//2018������ȫ��ģ�⾺�� ������ 
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
/*
int main(){

	int N;
	double Z,r;
	cin>>N>>Z>>r;
	int par[N];	//��ű��Ϊi���˵�ʦ���ı�� 
	double gongli[N]={0};	//��ʼ����ű��Ϊi���˵Ĺ���ֵ 
	gongli[0]=Z;	//��ʦү�Ĺ���ֵ 
	//gongli[1]=Z*(1-r)*0.01;
	vector<int> v;	//������еõ��ߵı�� 
	vector<vector<int> > vec(N);
	for(int i=0;i<N;i++){
		int K,n,B;
		cin>>K;	//ͽ�ܵ����� 
		if(K==0){
			cin>>B;
			vec[i]=
			v.push_back(i);
		}
		else{
			for(int j=0;j<K;j++){
				cin>>n;		//	ÿ��ͽ�ܵı�� 
				par[n]=i;
			}
		}
	}
	double sum=0;
	for(int i=0;i<v.size();i++)
		sum+=gongli[v[i]];;
	cout<<floor(sum)<<endl;
	return 0;
	
} */
double r,sum=0;
struct Node{	//����ṹ��Ķ��� 
	int Data;	//���ͽ�ܱ�� 
	struct Node* Next;	//ָ������һ�����ṹ���ָ�� 
};
struct Head{
	int x;	//�õ��߷Ŵ������ǵõ���0 
	struct Node* FirstEdge;	//ָ���������ָ�� 
};
void BuildGraph(struct Head H[],int t,const int i){
	if(t==0) cin>>H[i].x;
	else{
		struct Node *head,*p;
		head=(struct Node*)malloc(sizeof(struct Node));
		cin>>head->Data;
		p=head;
		H[i].FirstEdge=head;
		while(--t){
			struct Node *s=(struct Node*)malloc(sizeof(struct Node));
			cin>>s->Data;
			p->Next=s;
			p=s;
		}
		p->Next=NULL;
	} 
}
void DFS(struct Head H[],const int i,double z){
	if(H[i].x!=0) sum+=z*H[i].x;
	else{
		struct Node* p;
		for(p=H[i].FirstEdge;p!=NULL;p=p->Next)
			DFS(H,p->Data,z-z*r); 
	}
}
int main(){
	int i,n,t,k;
	double z;
	cin>>n>>z>>r;
	//����n������ͷ���ṹ�������
	struct Head *head=(struct Head*)malloc(sizeof(struct Head)*n) ;
	//��ʼ������ͷ���ṹ�����飬ȫ��Ϊ0
	memset(head,0,sizeof(*head));
	r/=100;
	for(int i=0;i<n;i++){
		cin>>t;		//����t���� 
		BuildGraph(head,t,i);
	} 
	DFS(head,0,z);
	cout<<int(sum);
	return 0;
}	//���������� 
