#include<iostream>
#include<cmath>
using namespace std;

bool just_prime(int num);

void main(){
	int sum=0;
	cout<<"0-100所有的素数：";
	for(int i=1;i<=100;i++){
		if(just_prime(i)){
			cout<<i<<" ";
			sum+=i;
		} 
		if(i==100) cout<<endl;
	}
	cout<<"0-100所有素数的和："<<sum<<endl;
}
bool just_prime(int num){
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0) return false;
	}
    return true;
}