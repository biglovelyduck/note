#include <iostream>
using namespace std;
int ans=0;
int a[8];
bool attack(int x0,int y0,int x1,int y1){//��ʾ����λ���Ƿ���Թ������Ƿ���true 
	if(x0==x1||y0==y1) return true;
	if(x0+y0==x1+y1||x0-y0==x1-y1) return true;
	return false;
} 
void dfs(int x){//�ӵ�x�п�ʼ 
	if(x==8){
		ans++;
		return;
	} 
	for(int i=0;i<8;i++){//������̽ 
		bool ok=true;
		for(int j=0;j<x;j++){//���֮ǰ���� 
			if(attack(j,a[j],x,i)){
				ok=false;
				break;//��һ�в�����,����һ�� 
			} 
		}
		if(ok){
			a[x]=i;//��һ�з��� 
			dfs(x+1);//�ݹ����� 
		} 
	}
}
int main(){
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
