/*有错误！迭代器不能指向空*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
void input(vector<int> &v){
	int n;
	vector<int>::iterator it=v.begin();
	for(int i=0;i<10;i++){
		scanf("%d",&n);
		v.insert(it++,n);
	}
}
void output(vector<int> v){
	do{ 
		vector<int>::iterator it=v.begin();
		printf("%d ",v.front());
		v.erase(it);
	} while(v.empty()); 
}
void dealWith(vector<int> &v){
	int min=v[0],minNum=0;
	int max=v[0],maxNum=0;
	for(int i=1;i<v.size();i++){
		if(v[i]<min){
			min=v[i];
			minNum=i;
		}
	}
	swap(v[minNum],v[0]);
	for(int i=1;i<v.size();i++){
		if(v[i]>max){
			max=v[i];
			maxNum=i;
		}
	}
	swap(v[maxNum],v[v.size()-1]);
}
int main(){
	vector<int> v;
	input(v);
	cout<<v.size()<<endl;
	dealWith(v);
	output(v);
	return 0;
} 
