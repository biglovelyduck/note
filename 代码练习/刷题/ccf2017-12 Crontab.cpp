//ccf2017-12 Crontab
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;
const int N=20+1;
const string Month[]={"nothing","jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
const string Week[]={"sun","mon","tue","wed","thu","fri","sat"};
const int Dnum[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct qj{	//���䣬����a-b���ʱ��Σ�(-1,-1)��ʾ�κ�ʱ�� 
	int a,b; 
};
struct node{	//���ﱣ�����Ҫ���ʱ������ 
		vector<qj> minute;
		vector<qj> hour;
		vector<qj> day;
		vector<qj> month;
		vector<qj> week;
		string cmd;
}m[N];	//�������������� 
