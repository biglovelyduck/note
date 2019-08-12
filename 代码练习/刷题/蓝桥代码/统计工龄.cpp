
/*7 统计工龄（25 分）
给定公司N名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。

输入格式:

输入首先给出正整数N（≤10
?5
?? ），即员工总人数；随后给出N个整数，即每个员工的工龄，范围在[0, 50]。

输出格式:

按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。

输入样例:

8
10 2 0 5 7 2 5 2
输出样例:

0:1
2:3
5:2
7:1
10:1*/
#include <iostream> 
#include<algorithm>
#include<vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 

bool comp(int a,int b){
	    return (a<b);
}
int main(){
	vector<int> v,v1;
	vector<int> :: iterator it;
	int n,num;
	cin>>n;
	while(n--){
		scanf("%d",&num);
		v.push_back(num);
	}
    sort(v.begin(),v.end(),comp);
    v1.assign(v.begin(),v.end());
    vector<int> :: iterator first=unique(v.begin(),v.end());//将多余重复的元素放在数组最后 
    v.erase(first,v.end());
	for(it=v.begin();it!=v.end();it++)
	    cout<<*it<<":"<<count(v1.begin(),v1.end(),*it)<<endl;
	return 0;
}
