//最长公共子序列
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int c[101][101];
int LCS1(const char* X,const char* Y){
	if(X==NULL||Y==NULL) return 0;
	int m=strlen(X);	//cout<<m<<endl;
	int n=strlen(Y);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			c[i][j]=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(X[i]==Y[j])	c[i+1][j+1]=c[i][j]+1;
			else{
				c[i+1][j+1]=max(c[i+1][j],c[i][j+1]);
			}	
		}
	}
	return c[m][n];
}
//记忆化的递推
#define INF 0x3f3f3f3f		//或者9999999 
int LCS2(string& X,string& Y,int i,int j){
	if(c[i][j]<INF) return c[i][j];
	if(X.length()==0||Y.length()==0) return 0;
	if((i==0)||(j==0))	c[i][j]=0;
	else if(X[i-1]==Y[j-1]) c[i][j]=LCS2(X,Y,i-1,j-1)+1;
	else c[i][j]=max(LCS2(X,Y,i-1,j),LCS2(X,Y,i,j-1));
	return c[i][j];	
}
int main(){
	char *a="ABCBDAB",*b="BDCABA";
	memset(c,INF,sizeof(c));
	string A=a;	//cout<<A<<endl;
	string B=b;	//cout<<B<<endl; 
	cout<<LCS2(A,B,strlen(a),strlen(b));
	return 0;
}
