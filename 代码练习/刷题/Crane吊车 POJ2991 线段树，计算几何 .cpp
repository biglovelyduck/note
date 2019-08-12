//Crane���� POJ2991 �߶��������㼸�� 
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10001
#define MAX_C 10001
//ÿ���ڵ��ʾһ�������߶εļ��� 
const int ST_SIZE=(1<<15)-1;	//�ڵ�����ֵ 
//���� 
int N,C;	//N���߶Σ�C��ָ��
int L[MAX_N];	//�߶�����
int S[MAX_C],A[MAX_N];
//�߶�����ά��������
double vx[ST_SIZE],vy[ST_SIZE];	//�����ڵ������ 
double ang[ST_SIZE];	//���ڵ�ĽǶ� 
//Ϊ�˲�ѯ�Ƕȵı仯������ĵ�ǰ�Ƕȵ�����
double prv[MAX_N];

//��ʼ���߶���,k�ǽڵ�ı�ţ�l,r��ʾ��ǰ�ڵ���ά������[l.r)���� 
void init(int k,int l,int r){
	ang[k]=vx[k]=0.0;		//�Ҷ���ת���ĽǶ� ���ڵ��k�������ĺ����� 
	
	if(r-l==1){
		//�����Ҷ�ӽ�㣬��ǰ�ڵ���ά����ֻʣ��һ���߶��� 
		vy[k]=L[l]; 		//�ڵ�k�������������� 
	}
	else{
		//��Ҷ�ӽڵ� ���ڵ��Ŵ�0��ʼ 
		int chl=k*2+1,chr=k*2+2;//���������Ľڵ��� 
		init(chl,l,(l+r)/2);	//�ݹ�ĳ�ʼ�� 
		init(chr,(l+r)/2,r); 	//��ʼ���������� 
		vy[k]=vy[chl]+vy[chr];
	} 
}

//��s��s+1�ĽǶȱ�Ϊa
//v�ǽڵ�ı�ţ�s���߶εı�ţ�l,r��ʾ��ǰ�ڵ�ά������[l,r)����
void change(int s,double a,int v,int l,int r){
	if(s<=l) return;	//�߶β��ڽڵ�ά���������� 
	else if(s<r){		
		int chl=v*2+1,chr=v*2+2;
		int m=(l+r)/2;			//�����е� 
		change(s,a,chl,l,m);	//ÿ�������䶼Ҫת��a�Ƕ� 
		change(s,a,chr,m,r);
		if(s<=m) ang[v]+=a;		//�ڵ�ת���ĽǶ� 
		
		double s=sin(ang[v]),c=cos(ang[v]);
		vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
		vy[v]=vy[chl]+(s*vx[chr]+c*vy[chr]);
	}
} 

void solve(){
	//��ʼ��
	init(0,0,N); 	//�ӵ�0���ڵ㿪ʼ��ʼ�� 
	for(int i=1;i<N;i++) prv[i]=M_PI;
	
	//�������
	for(int i=0;i<C;i++){
		int s=S[i];
		double a=A[i]/360.0*2*M_PI;	//�ѽǶȻ���ɻ���
		
		change(s,a-prv[s],0,0,N);
		prv[s]=a;
		
		printf("%.2f %.2f",vx[0],vy[0]); 
	} 
}

int main(){
	return 0;
}
