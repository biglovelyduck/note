#include <iostream>
using namespace std;
int n,m,k;//nö�ڵ���ÿ�㻤�ܿ��Գ���m���˺���k�㻤�� 
int a[100000]; //a[i]��ʾ��i���ڵ����˺�ֵ
bool crash(int t){//�ж�tʱ�����ܷ�ݻ����л��� 
	int c=m,cnt=0;//c��ʾ��ǰ���ܵ�HP��cnt��ʾ��ǰ�����Ļ��ܲ���
	for(int i=0;i<n;i++){//n���ڵ� 
		if(a[i]>=c){//���� 
			cnt++;
			c=m;
		}
		else{//δ���������Իظ�HP 
			c=c-a[i]+t;
			if(c>=m) c=m; 
		} 
	}
	return cnt>=k; 
} 

int main(){
	cin>>n>>m>>k;
	int count=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>=m) count++;
	}
	if(count>=k){
		cout<<-1<<endl;
		return 0;
	}
	int l=1,r=m;
	int ans=m;
	while(l<=r){
		int t=l+(r-l)/2;
		if(crash(t)){//������ 
			l=t+1;
		}
		else{//�ҵ����̵�ʱ�� 
			ans=t;
			r=t-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
