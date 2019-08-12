#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k,ka,ks;//�У��У� �����ţ��������ȵ�����������ͬ��״�������� 
char g[100][100];//��������ͼƬ 
bool vis[100][100];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<int> islands[1000];//����ÿ�������½�ر������ ��������˵islands[i]���vector���ǵ�i�������½�ر������ 

//����½�ر�� 
int has_func(int x,int y){
	return x*m+y;
}

//�ж��Ƿ񵽴�߽� 
int inb(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
} 

//dfs�����ϵ�����½�� 
void dfs(int x,int y,vector<int>& island){
	vis[x][y]=true;
	island.push_back(has_func(x,y));
	for(int d=0;d<4;d++){
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(inb(nx,ny)&&!vis[nx][ny]&&g[nx][ny]=='#'){
			dfs(nx,ny,island);
		}
	}	
} 

//�ж���״�Ƿ���ͬ
bool shape_similar(vector<int>& islandi,vector<int>& islandj) {
	if(islandi.size()!=islandj.size()) return false;
	int d=islandi[0]-islandj[0];
	for(int i=1;i<islandi.size();i++){
		if(islandi[i]-islandj[i]!=d) return false;
	}
	return true;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>g[i];
	memset(vis,false,sizeof(vis));
	k=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	if(!vis[i][j]&&g[i][j]=='#'){
		islands[k].clear();
		dfs(i,j,islands[k]);//��k���������е�½����ӵ�k��
		//k��������� 
		sort(islands[k].begin(),islands[k].end());//���������
		k++; 
	}
	ka=ks=0;
	for(int i=0;i<k;i++){
		bool fa=false,fs=false;
		for(int j=0;j<i;j++){
			if(islands[i].size()==islands[j].size()) fa=true;
			if(shape_similar(islands[i],islands[j])) fs=true;
		}
		if(!fa) ka++;
		if(!fs) ks++;
	}
	cout<<k<<' '<<ka<<' '<<ks<<endl; 
	return 0;
}
