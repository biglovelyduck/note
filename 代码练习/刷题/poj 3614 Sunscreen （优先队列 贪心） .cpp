//poj 3614 Sunscreen （优先队列 贪心） 
/*奶牛美容：有C头奶牛日光浴，每头奶牛分别需要minSPF_i和maxSPF_i单位强度之间的阳光。
现有L种防晒霜，分别能使阳光强度稳定为SPF_i，其瓶数为cover_i。求最多满足多少头奶牛*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
pair<int,int> cow[2500+16];
pair<int,int> bottle[2500+16];
priority_queue<int,vector<int>,greater<int> > q;//最大堆 
int main(){
	int C,L;	//C:奶牛数 L：防晒乳数 
	cin>>C>>L;
	for(int i=0;i<C;i++)
		cin>>cow[i].first>>cow[i].second;	//min SPF maxSPF
	for(int i=0;i<L;i++)
		cin>>bottle[i].first>>bottle[i].second;		//SPF  number
	sort(cow,cow+C);
	sort(bottle,bottle+L);
	int cur=0;	//现在正在等待涂防晒霜的奶牛的index 
	int result=0;
	for(int i=0;i<L;i++){
		while(cur<C&&cow[cur].first<=bottle[i].first){
	 		q.push(cow[cur].second);
			 ++cur; 
		}
		while(!q.empty()&&bottle[i].second){
			int maxSPF=q.top();q.pop();
			if(maxSPF>=bottle[i].first){
				++result;
				--bottle[i].second;
			}
		}    
	}
	cout<<result<<endl;
	return 0;
}
