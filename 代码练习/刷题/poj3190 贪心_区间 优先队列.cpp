//poj 3190
/*���⣺һȺ���и��Ե���ţ��ֻ�ڹ̶���ʱ����̣�ÿͷţ��Ҫ��һ�����̻�������Ϊ��������ţ����.
������Ҫ���ٸ����̻�������������ţ������˳�����������ţ���̻����ı�š�

��⣺�Ƚ���ţ���տ�ʼ���̵�ʱ���С������������ʼʱ����ͬ�����ս���ʱ���С��������
Ȼ����һ�����Ȳ��̽���ʱ������ȶ���ȥά����ǰ������ţ������һ����ţ�Ŀ�ʼʱ��С�ڻ��ߵ��ڵ�ǰ��ţ��
����ʱ�䣬����Ҫ����ʹ��һ�����̻�����������У������ڵ�ǰ��ţ�Ľ���ʱ�䣬�����ͬ��һ�����̻�������
���µ�ǰ������ţ��
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
bool operator<(const node& a,const node &b){	//��ȷ�����ȶ��е�������� ������<�ͱ�ʾ��С�������� 
	//���̽�����Խ��Խ����
	if(a.end==b.end)
		return a.start>b.start;		//�ڲ�д>��ʾ��<�෴ 
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
			cow[i].pos=i;	//��¼��������ʱ�ı�� ,Ҳ���Ǽ��̻����ı�� 
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
		if(cow[i].start>now.end){	//ͬ��һ�����̻��� 
			per[cow[i].pos]=per[now.pos];
			q.pop();	
		}
		else{	//��Ҫ����һ�����̻��� 
			per[cow[i].pos]=++k;	//������ż�һ 
		} 
		q.push(cow[i]);
	}
	cout<<k<<endl;
	for(i=0;i<n;++i){
		cout<<per[i]<<endl;
	}
	return 0;
}
