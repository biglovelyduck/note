//POJ 2010 Moo University 贪心 优先队列 
/*
奶牛大学：奶大招生，从C头奶牛中招收N头。
它们分别得分score_i，需要资助学费aid_i。希望新生所需资助不超过F，同
时得分中位数最高。求此中位数。*/
/*先将奶牛排序，考虑每个奶牛作为中位数时，比它分数低（前面的）的那群牛的学费总和lower_i，
后面的总和upper_i。然后从分数高往分数低扫描，满足aid_i + lower_i + upper_i <= F的第一个解就是最优解。*/
/*#include <queue>
#include <iostream>
#include <functional>
#include <limits>
#include <algorithm>
using namespace std;
#define MAX_COW 100000+16
int C,N,F;
pair<int,int> cow[MAX_COW];
//牛i作为中位数时，lower[i]表示分数低于他的额牛的学费总和
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
				//踢掉一个学费最高的家伙
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
				// 然后踢掉一个学费最高的家伙
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
// 牛i作为中位数时，lower[i]表示分数低于它的牛的学费总和
int lower[MAX_COW], upper[MAX_COW];
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{

	cin >> N >> C >> F;
	int half = N / 2;
	for (int i = 0; i < C; ++i)
	{
		cin >> cow[i].first >> cow[i].second;	// 分数 <-> 学费
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
				// 然后踢掉一个学费最高的家伙
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
				// 然后踢掉一个学费最高的家伙
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
