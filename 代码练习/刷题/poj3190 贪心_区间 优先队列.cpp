//poj 3190
/*题意：一群很有个性的奶牛，只在固定的时间产奶，每头牛需要用一个挤奶机器，问为满足所有牛产奶.
最少需要多少个挤奶机器，并按照奶牛给出的顺序来输出该奶牛挤奶机器的编号。

题解：先将奶牛按照开始产奶的时间从小到大排序，若开始时间相同，则按照结束时间从小到大排序。
然后用一个优先产奶结束时间的优先队列去维护当前产奶奶牛，若下一个奶牛的开始时间小于或者等于当前奶牛的
结束时间，则需要重新使用一个产奶机器，并入队列，若大于当前奶牛的结束时间，则可以同用一个挤奶机器，并
更新当前产奶奶牛。
--------------------- 
*/ 

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream> 
using namespace std;
int per[50010];
struct node{
	int start,end,pos;
}cow[50010],now;
bool operator<(const node& a,const node &b){	//来确定优先队列的排序规则 ，重载<就表示从小到大排序 
	//产奶结束的越早越优先
	if(a.end==b.end)
		return a.start>b.start;		//内部写>表示有<相反 
	return a.end>b.end; 
}
int cmp(node a,node b){
	if(a.start==b.start)
		return a.end<b.end;
	return a.start<b.start;
}
int main(){
	int n,k,i,cnt;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;++i){
			cin>>cow[i].start>>cow[i].end;
			cow[i].pos=i;	//记录给出数据时的编号 ,也就是挤奶机器的编号 
		}
		sort(cow,cow+n,cmp); 
		memset(per,0,sizeof(per));
	}
	priority_queue<node> q;
	q.push(cow[0]);
	per[cow[0].pos]=1;
	k=1;
	for(i=1;i<n;++i){
		now=q.top();
		if(cow[i].start>now.end){	//同用一个挤奶机器 
			per[cow[i].pos]=per[now.pos];
			q.pop();	
		}
		else{	//需要增加一个挤奶机器 
			per[cow[i].pos]=++k;	//机器编号加一 
		} 
		q.push(cow[i]);
	}
	cout<<k<<endl;
	for(i=0;i<n;++i){
		cout<<per[i]<<endl;
	}
	return 0;
}
