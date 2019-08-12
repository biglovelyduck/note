/*Fence Repair(PKU3253)*/
//题意：给定N块长度为Li的木板，求分割成这样的木板的最小开销
typedef long long ll;
int N,L[MAX_N];
void solve(){
	ll ans=0;
	//声明一个从小到大取出数值的优先队列
	priority_queue<int,vector<int>,greater<int> > que;
	for(int i=0;i<N;i++){
		que.push(L[i]);
	}
	//循环到只剩下一块木板为止
	while(que.size()>1){
		//取出最短和次短木块
		int l1,l2;
		l1=que.top();l1.pop();
		l2=que.top();l2.pop();
		ans+=l1+l2;
		que.push(l1+l2); 
	}
	cout<<ans; 
} 

