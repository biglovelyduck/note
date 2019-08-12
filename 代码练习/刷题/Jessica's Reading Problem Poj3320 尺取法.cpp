//Jessica's Reading Problem Poj3320 尺取法 
/*为了准备考试，Jessica 开始读一本很厚的课本。要想通过考试，必须把课本中所有的知识点
都掌握。这本书总共有P 页，第i 页恰好有一个知识点ai（每个知识点都有一个整数编号）。
全书中同一个知识点可能会被多次提到，所以她希望通过阅读其中连续的一些页把所有的知
识点都覆盖到。给定每页写到的知识点，请求出要阅读的最少页数。
限制条件
. 1 ≤ P ≤ 106*/ 
#include <bits/stdc++.h>
using namespace std;
const int MAX_P=1e6+1;
int P,a[MAX_P];
void solve(){
	set<int> all;
	//统计出不同知识点的总个数 
	for(int i=0;i<P;i++){
		all.insert(a[i]);
	}
	int n=all.size();
	
	//尺取法求解
	int s=0,t=0,num=0;
	map<int,int> count;//知识点->出现的次数
	int res=P;
	for(;;){
		while(t<P&&num<n){ 
			if(count[a[t++]]++==0)
				//出现新的知识点 
				num++;
		}
		if(num<n) break;
		res=min(res,t-s);
		if(--count[a[s++]]==0)
			//某个知识点出现的次数变成0了
			num--; 
	} 
	cout<<res<<endl;
}
int main(){
	cin>>P;
	for(int i=0;i<5;i++)
		cin>>a[i];
	solve();
	return 0;
}
