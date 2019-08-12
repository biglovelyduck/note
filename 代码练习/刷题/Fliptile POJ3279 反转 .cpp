//Fliptile POJ3279 反转
/*农夫约翰知道聪明的牛产奶多。于是为了提高牛的智商他准备了如下游戏。有一个M×N 的
格子，每个格子可以翻转正反面，它们一面是黑色，另一面是白色。黑色的格子翻转后就是
白色，白色的格子翻转过来则是黑色。游戏要做的就是把所有的格子都翻转成白色。不过因
为牛蹄很大，所以每次翻转一个格子时，与它上下左右相邻接的格子也会被翻转。因为翻格
子太麻烦了，所以牛都想通过尽可能少的次数把所有格子都翻成白色。现在给定了每个格子
的颜色，请求出用最小步数完成时每个格子翻转的次数。最小步数的解有多个时，输出字典
序最小的一组。解不存在的话，则输出IMPOSSIBLE。
限制条件
. 1 ≤ M, N ≤ 15*/ 

//思路：指定好第一行的反转方法，然后开始判定第二行的每个元素是否需要反转，然后继续下一行
//通过踩下一行的点来影响上面一行的点 

#include <bits/stdc++.h>
using namespace std;
#define MAX_M 16
#define MAX_N 16
const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,-1,0,1,0};
int M,N;	
int opt[MAX_M][MAX_N];			//保存最优解 
int flip[MAX_M][MAX_N];			//保存中间结果,踩到的点，会影响到四周四个点 
 
int title[MAX_M][MAX_N];		//保存黑白色，黑色为1	

//查询(x,y)的颜色
int get(int x,int y){
	int c=title[x][y]; 
	for(int d=0;d<5;d++){
		int x2=x+dx[d];
		int y2=y+dy[d];
		if(0<=x2&&x2<M&&0<=y2&&y2<N){
			c+=flip[x2][y2];	//c会受到四周四个被踩到的点的影响 
		}
	}
	return c&1;
} 

//求出第一行确定的情况下的最小操作次数
//不存在解返回-1
int calc(){
	//求出从第二行开始的反转方法
	for(int i=1;i<M;i++){
		for(int j=0;j<N;j++){
			if(get(i-1,j)==1)
				//是黑色，就必须反转这个格子
				flip[i][j]=1; 
		}
	}
	
	//判断最后一行是否全是白
	for(int j=0;j<N;j++){
		if(get(M-1,j)==1)
			return -1;	//无解 
	} 
	
	//统计反转的次数
	int res=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			res+=flip[i][j];
		}
	}
	return res; 
} 

void solve(){
	int res=-1;
	
	//按照字典序尝试第一行的所有可能,2^N种可能
	for(int i=0;i<(1<<N);i++){
		memset(flip,0,sizeof(flip));
		for(int j=0;j<N;j++)
			flip[0][N-1-j]=i>>j&1;			//试探所有的可能 
		int num=calc();
		if(num>=0&&(res<0||res>num)){
			res=num;
			memcpy(opt,flip,sizeof(flip));
		}
	} 
	if(res<0)
			cout<<"IMPOSSIBLE\n";
	else
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				cout<<opt[i][j]<<(j+1==N?'\n':' ');
}

int main(){
	cin>>M>>N;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin>>title[i][j];
	solve();
	return 0;
}
