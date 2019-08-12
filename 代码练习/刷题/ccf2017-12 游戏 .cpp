//ccf2017-12 сно╥ 
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		v[i]=i+1;
	int i=0;
	int num=0;
	while(true){
		num++;
		if(v.size()==1) break;
		if(i==v.size()) i=0;
		if(num%k==0||num%10==k){
			v.erase(v.begin()+i);
			i--;
		}
		//cout<<"v.size():"<<v.size()<<endl;
		i++;
	}
	cout<<*v.begin()<<endl;
	return 0;
}
