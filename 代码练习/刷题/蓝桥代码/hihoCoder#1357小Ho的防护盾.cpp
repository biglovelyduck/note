#include <iostream>
using namespace std;
int n,m,k;//n枚炮弹，每层护盾可以承受m点伤害，k层护盾 
int a[100000]; //a[i]表示第i个炮弹的伤害值
bool crash(int t){//判断t时间间隔能否摧毁所有护盾 
	int c=m,cnt=0;//c表示当前护盾的HP，cnt表示当前击穿的护盾层数
	for(int i=0;i<n;i++){//n个炮弹 
		if(a[i]>=c){//击穿 
			cnt++;
			c=m;
		}
		else{//未击穿，可以回复HP 
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
		if(crash(t)){//被打爆了 
			l=t+1;
		}
		else{//找到更短的时间 
			ans=t;
			r=t-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
