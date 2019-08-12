//POJ2376-Cleaning Shifts
//����Ŀ���⡿
//��������С����ʹ����䣬�󸲸����������������С�����������������������-1��
/*��⣺����T��ʱ�����䣬���䷶Χ[1,T]����ͬţ�в�ͬ�Ĺ���ʱ�䣬�����ٶ���ͷţ�������Ը���������䡣
������ţ��ʼ������ʱ���Ⱥ�˳������֮�󲻶�ѭ���������=�յ�+1���ڿ�ʼ����ʱ���ܸ�������ţ�У�
ÿ��ѡ��һͷ����ʱ�������ţ�������յ�   */
#include <iostream>
#include <algorithm>
using namespace std;
const int N_MAX=25000+1;
pair<int,int> cows[N_MAX];
int N,T;
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	return (a.first<b.first||(a.first==b.first&&a.second>b.second));
}
int solve(){
	int used_cows=0;
	int end=0,num=0;
	while(end<T){
		int begin=end+1;
		//��ʱ��end����һͷţ�Ĺ�������ʱ�䣬��ʱ��begin�ǵ�ǰţ�Ĺ�����ʼʱ��Ҫ��begin֮ǰ 
		for(int i=num;i<N;i++){//ѡ���µ�һͷţ��ʹ�ù���ʱ�������Խ��Խ�� 
			if(cows[i].first<=begin){
				if(cows[i].second>=begin)//�п���ţ�Ĺ���ʱ��ֻ��һ��
					end=max(end,cows[i].second); 
			}
			else{
				num=i;//û�з���Ҫ���ţ����ѡ�ˣ�����ţ 
				break;
			}
		}
		if(begin>end) return -1;
		else used_cows++; 
	}
	return used_cows;
}
int main(){
	cin>>N>>T;
	for(int i=0;i<N;i++){
		cin>>cows[i].first>>cows[i].second;
	}
	sort(cows,cows+N,cmp);
	cout<<solve();
	return 0;
}
