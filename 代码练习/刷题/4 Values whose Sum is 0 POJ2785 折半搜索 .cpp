//4 Values whose Sum is 0 POJ2785 �۰����� 
/*��������n ���������ĸ�����A��B��C��D��Ҫ��ÿ�������и�ȡ��1 ������ʹ�ĸ����ĺ�Ϊ
0�������������ϵĸ�������һ���������ж����ͬ������ʱ����������Ϊ��ͬ�����ֿ�����
��������
. 1 �� n �� 4000
. |(���ֵ�ֵ)| �� 228s*/
/*˼·����ʱ������Ĺ�ģ�ϴ��޷�ö������Ԫ�ص���ϣ����ܹ�ö��һ��Ԫ�ص���ϡ���ʱ������
���������ֱ�ö�٣��ٺϲ����ǵĽ����һ���������ǳ���Ч��*/
#include <iostream>
#include  <algorithm>
using namespace std;
const int MAX_N=4001;
int n;
int A[MAX_N],B[MAX_N],C[MAX_N],D[MAX_N]; 
int CD[MAX_N*MAX_N];		//C��D�����ֵ���Ϸ��� 

void solve(){
	//ö�ٴ�C��D��ȡ�����ֵ����з���
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			CD[i*n+j]=C[i]+D[j];	//��ͬ����Ϸ��� 
		}
	} 
	sort(CD,CD+n*n);
	
	long long res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int cd=-(A[i]+B[j]);
			//ȡ��C��D�к�Ϊcd�Ĳ���
			res+=upper_bound(CD,CD+n*n,cd)-lower_bound(CD,CD+n*n,cd);
		}
	}
	cout<<res<<endl;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		cin>>B[i];
	for(int i=0;i<n;i++)
		cin>>C[i];
	for(int i=0;i<n;i++)
		cin>>D[i];
	solve();
	return 0;
}
