#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
int main(){
	//ÿ�����г����������������ǹ̶��� 
	int a=rand()%100;
	cout<<a<<endl;
	int b=rand()%100;
	cout<<b<<endl;
	//��������
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
