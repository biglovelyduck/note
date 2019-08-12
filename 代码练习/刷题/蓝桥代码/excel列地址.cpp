#include<iostream>

using namespace std;

string f(int n){
	for(int i=0;i<=26;i++){
		for(int j=0;j<=26;j++){
			for(int k=0;k<=26;k++){
				int x=i*26*26+j*26+k;
				if(x==n){
					string s="";
					if(i>0) s += (char)(i-1+'A');
				    if(j>0) s += (char)(j-1+'A');
				    if(k>0) s += (char)(k-1+'A');
				    return s;
				}
			}
		}
	}
	return "";
}

int main(){
	int n;
	cin>>n;
	for(int i=0; i<750; i++){
		cout<<i<<":"<<f(i)<<endl;
	}
	return 0;
}

