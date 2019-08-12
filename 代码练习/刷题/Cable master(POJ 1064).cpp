//���ֲ��ң��ж�һ�����Ƿ����
//��N�����ӣ����ȷֱ�ΪLi,��������и��K��������ͬ�����ӣ���ÿ���?
//1<=N,K<10000    1<=Li<=100000 
//C(x)=(floor(Li/x)���ܺ��Ƿ���ڻ��ߵ���K)

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib> 
using namespace std;
const int MAX_N=10000+1;
int INF;
int N,K;
double L[MAX_N];
//�ж�ÿ������x�Ƿ���������
bool C(double x){
	int num=0;
	for(int i=0;i<N;i++){
		num+=(int)(L[i]/x);
	}
	return num>=K;
} 

void solve(){
	//��ʼ����ķ�Χ
	double lb=0,ub=INF;
	//�ظ�ѭ����ֱ����ķ�Χ�㹻С
	for(int i=0;i<100;i++){
		double mid=(lb+ub)/2;
		if(C(mid)) lb=mid;
		else ub=mid;
	}
	cout<<floor(ub*100)/100;
}

int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>L[i];
	}
	sort(L,L+N);
	INF=L[N-1];
	solve();
	return 0;
}
