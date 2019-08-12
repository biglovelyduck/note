//poj1979 Red and Black£®…ÓÀ—£© 
#include <cstdio>
#include <iostream>
using namespace std;
#define MAX_H 20

char map[MAX_H][MAX_H];
int visited[MAX_H][MAX_H];
int resultCount=0;
int arr[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int width,height;

void dfs(int x,int y);

int main(){
	//freopen("input.txt","r",stdin);
	cin>>height>>width; 
	int startWidth=0;
	int startHeight=0;
	while(!(width==0&&height==0)){
		resultCount=1;
		for(int i=0;i<width;i++){
			for(int j=0;j<height;j++){
				visited[i][j]=0;
				cin>>map[i][j];
				if(map[i][j]=='@'){
					startWidth=i;
					startHeight=j;
				}
			}
		}
		dfs(startWidth,startHeight);
		cout<<resultCount<<endl;
		cin>>height>>width;
	}
	return 0;
}

void dfs(int x,int y){
	int tempX=0;
	int tempY=0;
	for(int d=0;d<4;d++){
		tempX=x+arr[d][0];
		tempY=y+arr[d][1];
		if(tempX>=0&&tempX<width&&tempY>=0&&tempY<height){
			if(map[tempX][tempY]=='.'&&visited[tempX][tempY]==0){
				visited[tempX][tempY]=1;
				resultCount++;
				dfs(tempX,tempY);
			}
		}
	}
}
