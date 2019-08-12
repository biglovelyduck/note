//2018天梯赛全国模拟竞赛 功夫传人 
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
	int par[N];	//存放编号为i的人的师傅的编号 
	double gongli[N]={0};	//初始化存放编号为i的人的功力值 
	gongli[0]=Z;	//祖师爷的功力值 
	//gongli[1]=Z*(1-r)*0.01;
	vector<int> v;	//存放所有得道者的编号 
	vector<vector<int> > vec(N);
	for(int i=0;i<N;i++){
		int K,n,B;
		cin>>K;	//徒弟的数量 
		if(K==0){
			cin>>B;
			vec[i]=
			v.push_back(i);
		}
		else{
			for(int j=0;j<K;j++){
				cin>>n;		//	每个徒弟的编号 
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
struct Node{	//链表结构体的定义 
	int Data;	//存放徒弟编号 
	struct Node* Next;	//指向自下一个己结构体的指针 
};
struct Head{
	int x;	//得道者放大倍数，非得道者0 
	struct Node* FirstEdge;	//指向链表结点的指针 
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
	//创建n个链表头结点结构体的数字
	struct Head *head=(struct Head*)malloc(sizeof(struct Head)*n) ;
	//初始化链表头结点结构体数组，全部为0
	memset(head,0,sizeof(*head));
	r/=100;
	for(int i=0;i<n;i++){
		cin>>t;		//建立t条边 
		BuildGraph(head,t,i);
	} 
	DFS(head,0,z);
	cout<<int(sum);
	return 0;
}	//答案来自网上 
