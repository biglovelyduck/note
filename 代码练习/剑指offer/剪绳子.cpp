//������
/* 
�����
������������
����һ������Ϊn�����ӣ�������Ӽ���m�� (m��n����������n>1����m>1)ÿ�����ӵĳ��ȼ�Ϊk[0],k[1],...,k[m].����k[0]*k[1]*...*k[m]���ܵ����˻��Ƕ��٣�
��Ҫ�� 
���������롿���ӳ��ȣ�һ��������n(n>1)
����������������Ӽ���m�κ�, ���ܵ����˻�����Ҳ��һ��������
���������롿 
���ӵĳ���n=9
����������� 
���ǰ������ɳ��ȷֱ�Ϊ3,3,3�����Σ���ʱ�õ������˻���3*3*3=27 */

#include <bits/stdc++.h>
using namespace std;

//��̬�滮�㷨 
int max(int n){
	if(n<2) return 0;
	if(n==2) return 1;
	if(n==3) return 2;
	int* a=new int[n+1];
	a[0]=0;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	for(int i=4;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			a[i]=max(a[j]*a[i-j],a[i]);
		}
	}
	int m=a[n];
	delete[] a;
	return m;
}

//̰���㷨ʵ��
int max1(int n){
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	if(n==3)
		return 2;
	//�����ܶ�ļ�ȥ����Ϊ3�����Ӷ�
	int timesOf3=n/3;
	//������ʣ�����ĳ���Ϊ4ʱ��������ȥ��ȥ����Ϊ3������
	if(n-timesOf3*3==1)
		timesOf3-=1;
	int timesOf2 =(n-timesOf3*3)/2;
	return (int)(pow(3,timesOf3*))*(int)(pow,2,timesOf2);tt 
} 
int main(){
	int n;
	cin>>n;
	cout<<max(n)<<endl;
}
