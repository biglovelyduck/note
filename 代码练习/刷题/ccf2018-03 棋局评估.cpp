//ccf2018-03 棋局评估 
/*状态压缩+博弈+搜索
我先把棋局按照3进制压缩为一个整数，用这个整数作为参数去搜索，比较简便
两个人都要按最优策略来，就是博弈，这道题就简单的标记下当前是哪个人走
是Alice就递归的选择接下来能得到的最大分数，Bob就是最小分数*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int p[12];	//三进制状态压缩的棋盘 
int judge(int d){
	int a[10],t=0;	//t为空格数 
	for(int i=8;i>=0;i--){
		a[i]=d%3;
		d/=3;
		if(a[i]==0) t++;
	}
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==1||
        a[3]==a[4]&&a[4]==a[5]&&a[5]==1||        
		a[6]==a[7]&&a[7]==a[8]&&a[8]==1||        
		a[0]==a[3]&&a[3]==a[6]&&a[6]==1||        
		a[1]==a[4]&&a[4]==a[7]&&a[7]==1||        
		a[2]==a[5]&&a[5]==a[8]&&a[8]==1||        
		a[0]==a[4]&&a[4]==a[8]&&a[8]==1||        
		a[2]==a[4]&&a[4]==a[6]&&a[6]==1)        
		return t+1;    
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==2||        
		a[3]==a[4]&&a[4]==a[5]&&a[5]==2||        
		a[6]==a[7]&&a[7]==a[8]&&a[8]==2||        
		a[0]==a[3]&&a[3]==a[6]&&a[6]==2||        
		a[1]==a[4]&&a[4]==a[7]&&a[7]==2||        
		a[2]==a[5]&&a[5]==a[8]&&a[8]==2||        
		a[0]==a[4]&&a[4]==a[8]&&a[8]==2||        
		a[2]==a[4]&&a[4]==a[6]&&a[6]==2)        
		return -t-1;    
	return 0;

}
int dfs(int d,int f){
	int ret=judge(d);	//返回当前棋盘的得分
	if(ret!=0) return ret;	//结束了返回结果
	//下棋还没有结束
	int t=d,num=0; 		//d只是传进来的参数d,t来暂时保存并操作t,num计算出当前棋盘的空格数 
	for(int i=0;i<9;i++){
		if(t%3==0) num++;
		t/=3;
	} 
	if(!num) return 0;	//平局
	if(f>0){	//表示轮到Allice下棋 
		int t=d;
		ret=-10;
		for(int i=0;i<9;i++){
			if(t%3==0) ret=max(ret,dfs(d+p[i],-f));
			t/=3;
		}
	}
	else{		//f<0表示轮到Bob下棋 
		int t=d;
		ret=10;
		for(int i=0;i<9;i++){
			if(t%3==0) ret=min(ret,dfs(d+2*p[i],-f));
			t/=3;
		}
	}
	return ret;	 
}
int main(){
	p[0]=1;
	for(int i=1;i<10;i++){
		p[i]=3*p[i-1];	//p1=3,p2=9,p3=27	初始化棋盘 
	}
	int T;	//测试数据的组数 
	cin>>T;   
	while(T--){
		int a,d=0;
		for(int i=0;i<9;i++){
			cin>>a;
			d=d*3+a;	// 
		}
		cout<<dfs(d,1);		
	} 
	return 0;
}
