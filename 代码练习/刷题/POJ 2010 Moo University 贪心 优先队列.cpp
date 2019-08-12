//POJ 2010 Moo University ̰�� ���ȶ��� 
/*
��ţ��ѧ���̴���������Cͷ��ţ������Nͷ��
���Ƿֱ�÷�score_i����Ҫ����ѧ��aid_i��ϣ��������������������F��ͬ
ʱ�÷���λ����ߡ������λ����*/
/*�Ƚ���ţ���򣬿���ÿ����ţ��Ϊ��λ��ʱ�����������ͣ�ǰ��ģ�����Ⱥţ��ѧ���ܺ�lower_i��
������ܺ�upper_i��Ȼ��ӷ�������������ɨ�裬����aid_i + lower_i + upper_i <= F�ĵ�һ����������Ž⡣*/
/*#include <queue>
#include <iostream>
#include <functional>
#include <limits>
#include <algorithm>
using namespace std;
#define MAX_COW 100000+16
int C,N,F;
pair<int,int> cow[MAX_COW];
//ţi��Ϊ��λ��ʱ��lower[i]��ʾ�����������Ķ�ţ��ѧ���ܺ�
int lower[MAX_COW],upper[MAX_COW]; 
int main(){
	cin>>N>>C>>F;
	int half=N/2;
	for(int i=0;i<C;i++)
		cin>>cow[i].first>>cow[i].second;	//score_i   aid_i
	sort(cow,cow+C);
	{
		int total=0;
		priority_queue<int> q;
		for(int i=0;i<C;++i){
			lower[i]= q.size()==half?total:0x3f3f3f3f;
			q.push(cow[i].second);
			total+=cow[i].second;
			if(q.size()>half)
				//�ߵ�һ��ѧ����ߵļһ�
				total -= q.top(); q.pop(); 
		}
	}
	{
		int total = 0;
		priority_queue<int> q;
		for (int i = C - 1; i >= 0; --i)
		{
			upper[i] =  q.size() == half ? total : 0x3f3f3f3f;
			q.push(cow[i].second);
			total += cow[i].second;
			if (q.size() > half)
			{
				// Ȼ���ߵ�һ��ѧ����ߵļһ�
				total -= q.top(); q.pop();
			}
		}
	}
	int result;
	for (int i = C - 1; i >= 0; --i)
	{
		if (lower[i] + cow[i].second + upper[i] <= F)
		{
			result = cow[i].first;
			break;
		}
	}
 
	cout << result << endl;
	return 0;
} */


#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
#include <functional>
using namespace std;
 
#define MAX_COW 100000 + 16
 
int N, C, F;
pair<int, int> cow[MAX_COW];
// ţi��Ϊ��λ��ʱ��lower[i]��ʾ������������ţ��ѧ���ܺ�
int lower[MAX_COW], upper[MAX_COW];
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{

	cin >> N >> C >> F;
	int half = N / 2;
	for (int i = 0; i < C; ++i)
	{
		cin >> cow[i].first >> cow[i].second;	// ���� <-> ѧ��
	}
	sort(cow, cow + C);
	{
		int total = 0;
		priority_queue<int> q;
		for (int i = 0; i < C; ++i)
		{
			lower[i] = q.size() == half ? total : 0x3f3f3f3f;
			q.push(cow[i].second);
			total += cow[i].second;
			if (q.size() > half)
			{
				// Ȼ���ߵ�һ��ѧ����ߵļһ�
				total -= q.top(); q.pop();
			}
		}
	}
 
	{
		int total = 0;
		priority_queue<int> q;
		for (int i = C - 1; i >= 0; --i)
		{
			upper[i] = q.size() == half ? total : 0x3f3f3f3f;
			q.push(cow[i].second);
			total += cow[i].second;
			if (q.size() > half)
			{
				// Ȼ���ߵ�һ��ѧ����ߵļһ�
				total -= q.top(); q.pop();
			}
		}
	}
 
	int result;
	for (int i = C - 1; i >= 0; --i)
	{
		if (lower[i] + cow[i].second + upper[i] <= F)
		{
			result = cow[i].first;
			break;
		}
	}
 
	cout << result << endl;
	

	return 0;
}
