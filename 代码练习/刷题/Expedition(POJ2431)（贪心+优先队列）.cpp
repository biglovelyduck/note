/*Expedition(POJ2431)*/
/*题意：驾驶一辆车要行驶L距离。最开始卡车有P汽油，卡车每开1单位耗1单位汽油
途中有N个加油站，第i个加油站距离起点Ai单位距离，最多可以给卡车加Bi单位汽油
问能否到达终点，可以的话最少需要加棘几次油*/
//N<=1000000  P<=1000000 
//思路：在经过加油站时，往优先队列里加入Bi
//当燃料空的时候：1.如果优先队列也空，则无法到达终点
//					2.否则取出最大元素给卡车加油
int L,P,N;
int A[MAX_N+1],B[MAX_N+1];
void solve(){
	//为了写起来方便，我们把终点也当做加油站
	A[N]=L;
	B[N]=0;
	N++;
	//维护加油站的优先队列
	priority_queue<int> que;
	//ans:加油次数，pos:现在所在位置,tank:油箱油量
	int ans=0,pos=0,tank=P;
	for(int i=0;i<N;i++){
		//接下去到达下一个加油站要前进的距离
		int d=A[i]-pos;
		//不断的加油直到油箱足够到下一个加油站
		while(tank-d<0){
			if(que.empty()){
				puts("-1");
				return;
			}
			tank+=que.top();
			que.pop();
			ans++;
		}
		//继续走，直到到达下一个加油站
		tank-=d;
		pos=A[i];
		que.push(B[i]); 
	}
	cout<<ans; 
} 
