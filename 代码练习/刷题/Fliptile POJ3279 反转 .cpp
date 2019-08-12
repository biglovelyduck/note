//Fliptile POJ3279 ��ת
/*ũ��Լ��֪��������ţ���̶ࡣ����Ϊ�����ţ��������׼����������Ϸ����һ��M��N ��
���ӣ�ÿ�����ӿ��Է�ת�����棬����һ���Ǻ�ɫ����һ���ǰ�ɫ����ɫ�ĸ��ӷ�ת�����
��ɫ����ɫ�ĸ��ӷ�ת�������Ǻ�ɫ����ϷҪ���ľ��ǰ����еĸ��Ӷ���ת�ɰ�ɫ��������
Ϊţ��ܴ�����ÿ�η�תһ������ʱ�����������������ڽӵĸ���Ҳ�ᱻ��ת����Ϊ����
��̫�鷳�ˣ�����ţ����ͨ���������ٵĴ��������и��Ӷ����ɰ�ɫ�����ڸ�����ÿ������
����ɫ�����������С�������ʱÿ�����ӷ�ת�Ĵ�������С�����Ľ��ж��ʱ������ֵ�
����С��һ�顣�ⲻ���ڵĻ��������IMPOSSIBLE��
��������
. 1 �� M, N �� 15*/ 

//˼·��ָ���õ�һ�еķ�ת������Ȼ��ʼ�ж��ڶ��е�ÿ��Ԫ���Ƿ���Ҫ��ת��Ȼ�������һ��
//ͨ������һ�еĵ���Ӱ������һ�еĵ� 

#include <bits/stdc++.h>
using namespace std;
#define MAX_M 16
#define MAX_N 16
const int dx[5]={-1,0,0,0,1};
const int dy[5]={0,-1,0,1,0};
int M,N;	
int opt[MAX_M][MAX_N];			//�������Ž� 
int flip[MAX_M][MAX_N];			//�����м���,�ȵ��ĵ㣬��Ӱ�쵽�����ĸ��� 
 
int title[MAX_M][MAX_N];		//����ڰ�ɫ����ɫΪ1	

//��ѯ(x,y)����ɫ
int get(int x,int y){
	int c=title[x][y]; 
	for(int d=0;d<5;d++){
		int x2=x+dx[d];
		int y2=y+dy[d];
		if(0<=x2&&x2<M&&0<=y2&&y2<N){
			c+=flip[x2][y2];	//c���ܵ������ĸ����ȵ��ĵ��Ӱ�� 
		}
	}
	return c&1;
} 

//�����һ��ȷ��������µ���С��������
//�����ڽⷵ��-1
int calc(){
	//����ӵڶ��п�ʼ�ķ�ת����
	for(int i=1;i<M;i++){
		for(int j=0;j<N;j++){
			if(get(i-1,j)==1)
				//�Ǻ�ɫ���ͱ��뷴ת�������
				flip[i][j]=1; 
		}
	}
	
	//�ж����һ���Ƿ�ȫ�ǰ�
	for(int j=0;j<N;j++){
		if(get(M-1,j)==1)
			return -1;	//�޽� 
	} 
	
	//ͳ�Ʒ�ת�Ĵ���
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
	
	//�����ֵ����Ե�һ�е����п���,2^N�ֿ���
	for(int i=0;i<(1<<N);i++){
		memset(flip,0,sizeof(flip));
		for(int j=0;j<N;j++)
			flip[0][N-1-j]=i>>j&1;			//��̽���еĿ��� 
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
