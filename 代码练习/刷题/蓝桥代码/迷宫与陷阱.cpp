#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
int n,k;//行列，无敌时间
string s[1000];
map<int,int> dis;
queue<int> q;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
//状态三元组(s, x, y)编码成一个整数st = s * 1000000 + x * 1000 + y。
int main(){
	cin>>n>>k; 
	for(int i=0;i<n;i++) cin>>s[i];
	q.push(0);
	dis[0]=0;
	while(q.empty()){
		int st=q.front();//st是队首取出的点 
		int sec=st/1000000;
		int x=st%1000000/1000;
		int y=st%1000;
		int nx,ny,nsec,nst;
		for(int d=0;d<4;d++){
			nx=x+dx[d];
			ny=y+dy[d];
			if(nx>=0&&ny>=0&&nx<n&&ny<n&&s[nx][ny]!='#'){
				if(s[nx][ny]=='.'){
					if(nx==n-1&&ny==n-1){
						cout<<dis[st]+1<<endl;
						return 0;
					}
					nsec=sec>0?sec-1:0;
					nst=nsec*1000000+nx*1000+ny;//队首元素相邻的点 
					//该点尚未访问 
					if(dis.find(nst)==dis.end()){
						dis[nst]=dis[st]+1; 
						q.push(nst);
					}
				}
				else if(s[nx][ny]=='X'){
					nsec=sec>0?sec-1:0;
					if(nsec>0){
						nst=nsec*1000000+nx*1000+ny;//队首元素相邻的点 
						//该点尚未访问 
						if(dis.find(nst)==dis.end()){
							dis[nst]=dis[st]+1; 
							q.push(nst);
						}
					}
				}
				else{//是无敌 
					nsec=k+1;
					nst=nsec*1000000+nx*1000+ny;//队首元素相邻的点 
						//该点尚未访问 
						if(dis.find(nst)==dis.end()){
							dis[nst]=dis[st]+1; 
							q.push(nst);
						}
				}
			}
		}
	}
	cout<<-1<<endl; 
	return 0;
}
