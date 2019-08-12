//Crane吊车 POJ2991 线段树，计算几何 
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10001
#define MAX_C 10001
//每个节点表示一段连续线段的集合 
const int ST_SIZE=(1<<15)-1;	//节点的最大值 
//输入 
int N,C;	//N条线段，C条指令
int L[MAX_N];	//线段数组
int S[MAX_C],A[MAX_N];
//线段树所维护的数据
double vx[ST_SIZE],vy[ST_SIZE];	//各个节点的向量 
double ang[ST_SIZE];	//各节点的角度 
//为了查询角度的变化而保存的当前角度的数组
double prv[MAX_N];

//初始化线段树,k是节点的编号，l,r表示当前节点所维护的是[l.r)区间 
void init(int k,int l,int r){
	ang[k]=vx[k]=0.0;		//右儿子转过的角度 ，节点点k的向量的横坐标 
	
	if(r-l==1){
		//如果是叶子结点，当前节点所维护的只剩下一条线段了 
		vy[k]=L[l]; 		//节点k的向量的纵坐标 
	}
	else{
		//非叶子节点 ，节点编号从0开始 
		int chl=k*2+1,chr=k*2+2;//左右子树的节点编号 
		init(chl,l,(l+r)/2);	//递归的初始化 
		init(chr,(l+r)/2,r); 	//初始化各个子树 
		vy[k]=vy[chl]+vy[chr];
	} 
}

//把s和s+1的角度变为a
//v是节点的编号，s是线段的编号，l,r表示当前节点维护的是[l,r)区间
void change(int s,double a,int v,int l,int r){
	if(s<=l) return;	//线段不在节点维护的区间内 
	else if(s<r){		
		int chl=v*2+1,chr=v*2+2;
		int m=(l+r)/2;			//区间中点 
		change(s,a,chl,l,m);	//每个子区间都要转动a角度 
		change(s,a,chr,m,r);
		if(s<=m) ang[v]+=a;		//节点转过的角度 
		
		double s=sin(ang[v]),c=cos(ang[v]);
		vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
		vy[v]=vy[chl]+(s*vx[chr]+c*vy[chr]);
	}
} 

void solve(){
	//初始化
	init(0,0,N); 	//从第0个节点开始初始化 
	for(int i=1;i<N;i++) prv[i]=M_PI;
	
	//处理操作
	for(int i=0;i<C;i++){
		int s=S[i];
		double a=A[i]/360.0*2*M_PI;	//把角度换算成弧度
		
		change(s,a-prv[s],0,0,N);
		prv[s]=a;
		
		printf("%.2f %.2f",vx[0],vy[0]); 
	} 
}

int main(){
	return 0;
}
