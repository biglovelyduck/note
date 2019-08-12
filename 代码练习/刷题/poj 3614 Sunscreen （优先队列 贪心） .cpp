//poj 3614 Sunscreen �����ȶ��� ̰�ģ� 
/*��ţ���ݣ���Cͷ��ţ�չ�ԡ��ÿͷ��ţ�ֱ���ҪminSPF_i��maxSPF_i��λǿ��֮������⡣
����L�ַ�ɹ˪���ֱ���ʹ����ǿ���ȶ�ΪSPF_i����ƿ��Ϊcover_i��������������ͷ��ţ*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
pair<int,int> cow[2500+16];
pair<int,int> bottle[2500+16];
priority_queue<int,vector<int>,greater<int> > q;//���� 
int main(){
	int C,L;	//C:��ţ�� L����ɹ���� 
	cin>>C>>L;
	for(int i=0;i<C;i++)
		cin>>cow[i].first>>cow[i].second;	//min SPF maxSPF
	for(int i=0;i<L;i++)
		cin>>bottle[i].first>>bottle[i].second;		//SPF  number
	sort(cow,cow+C);
	sort(bottle,bottle+L);
	int cur=0;	//�������ڵȴ�Ϳ��ɹ˪����ţ��index 
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
