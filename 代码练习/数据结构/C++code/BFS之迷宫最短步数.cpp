#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=100;
struct node{
	int x,y;
	int step;//stepΪ��㵽���λ�õ����ٲ������������� 
}S,T,Node;//���������ṹ�����
int n,m;//�У���
char maze[maxn][maxn];//�Թ�
bool inq[maxn][maxn];//��¼λ�ã�x,y)�Ƿ��Ѿ����
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
//���λ��(x,y)�Ƿ���Ч
bool test(int x,int y){
	if(x>=n||x<0||y>=m||y<0) return false;
	if(maze[x][y]=='*') return false;
	if(inq[x][y]) return false;//�Ѿ���� 
	return true; 
}
int BFS(){
	queue<node> q;
	q.push(S);
	while(!q.empty()){
		node top=q.front();
		q.pop();
		if(top.x==T.x&&top.y==T.y){
			return top.step;
		}
		for(int i=0;i<4;i++){
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(test(newX,newY)){
				Node.x=newX;
				Node.y=newY;
				Node.step=top.step+1;
				q.push(Node);
				inq[newX][newY]=true;
			}
		}
	}
	return -1;
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		getchar();//
		for(int j=0;j<m;j++){
			maze[i][j]=getchar();
		}
		maze[i][m+1]='\0'; 
	}
	scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
	S.step=0;
	printf("%d\n",BFS());
	return 0;
}
