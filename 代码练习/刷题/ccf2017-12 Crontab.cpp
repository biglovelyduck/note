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
struct qj{	//区间，代表a-b这个时间段，(-1,-1)表示任何时间 
	int a,b; 
};
struct node{	//这里保存符合要求的时间区段 
		vector<qj> minute;
		vector<qj> hour;
		vector<qj> day;
		vector<qj> month;
		vector<qj> week;
		string cmd;
}m[N];	//所有命令行数组 
