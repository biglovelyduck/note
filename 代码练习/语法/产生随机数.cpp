#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
int main(){
	//每次运行程序产生的随机数都是固定的 
	int a=rand()%100;
	cout<<a<<endl;
	int b=rand()%100;
	cout<<b<<endl;
	//设置种子
	srand(time(0));
	vector<int> v;
	for(int i=0;i<10;i++){
		v.push_back(rand()%100);
	} 
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	} 
	return 0;
}
