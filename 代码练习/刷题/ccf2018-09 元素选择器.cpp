//ccf2018-09 Ԫ��ѡ���� 
//˼·��������� 
#include <iostream>
#include <string> 
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int N=100+10;
//���Ľ�� 
struct node{
	string name,id;
}tree[N];
stack<int> s;	//��ջ������������ 
vector<int> g[N];	//�ڽӱ� 
int pre[N];		//����ÿ�е�ǰ׺��ĸ��� 
int num;	//����ѡ�����Ĳ��� 
string str[N];	//����ѡ�����ĵ��� 
int cnt,ans[N];		//�����	,cnt�Ǹ�����ans�����к� 
int n,m;
void dfs_name(int u,int d); 
void dfs_id(int u,int d)  //ƥ��id
{
    if(tree[u].id==str[d]) d++;
    if(d>num) ans[cnt++]=u,d=num;  //ƥ�������һ����Ҫ����ƥ�����һ��
    for(int i=0;i<g[u].size();i++)
        if(str[d][0]=='#') dfs_id(g[u][i],d);
        else dfs_name(g[u][i],d);
}

void dfs_name(int u,int d){
	if(tree[u].name==str[d])	d++;	//ƥ��ɹ�
	if(d>num)	ans[cnt++]=u,d=num; //ƥ�������һ����Ҫ����ƥ�����һ�� 
	for(int i=0;i<g[u].size();i++){	//�����ý����ӽ�� 
		if(str[d][0]=='#')	dfs_id(g[u][i],d);
		else dfs_name(g[u][i],d);
	} 
}

int main(){
	cin>>n>>m;
	getchar();
	string in;
	tree[0].name=tree[0].id="";
	for(int i=1;i<=n;i++){
		getline(cin,in);	//�����һ�д�ŵ�string in�� 
		pre[i]=0;
		bool flag=false;
		string name="",id="";
		//��ȡ�㼶����ǩ��id��Ϣ
		for(int j=0;j<in.length();j++){
			if(in[j]=='.') pre[i]++;
			else if(in[j]==' '){
				//�����ո���
				flag=true;
				while(j+1<in.length()&&in[j+1]==' ') j++; 
			}
			else{
				//������ǩ
				if(!flag) name+=tolower(in[j]);
				//������ǩ 
				else id+=in[j];
			}
		}
		//���е��⣬�ܹ������еĸ�����Ϣ��ȡ����
		tree[i].name=name;
		tree[i].id=id;
		//��ջ����������������ǰ��С�� �Լ���������
		while(!s.empty()&&pre[s.top()]>=pre[i]) s.pop();	//���������Լ��ĸ��ڵ� 
		if(!s.empty()) g[s.top()].push_back(i);		//ĳ�����ڽӵ������ӽڵ� 
		else g[0].push_back(i);	 //ʹ�ý��0����Ϊ�ܸ�
		s.push(i); 
	}
	while(m--){
		getline(cin,in);
		num=0;		//���浥�ʵĸ��� 
		str[0]="";		//��ʼ����һ������ 
		for(int i=0;i<in.length();i++){
			//�ѵ�����ȡ����
			if(in[i]==' '){
				if(str[num]!="")
					num++,str[num]="";		//��ʼ����һ������ 
				while(i+1<in.length()&&in[i+1]==' ') i++;	
			}
			else str[num]+=in[i]; 
		}
		if(str[num]=="")	num--;
		for(int i=0;i<=num;i++){
			//����ǩת��ΪСд,id���ԵĴ�Сд���� 
			if(str[i][0]!='#')
				for(int j=0;j<str[i].length();j++)
					str[i][j]=tolower(str[i][j]); 
		}
		cnt=0;
		if(num==0){		//ֻ��һ������ 
			if(str[0][0]=='#'){
				for(int i=1;i<=n;i++)
					if(tree[i].id==str[0])	ans[cnt++]=i;
			}
			else{
				for(int i=1;i<=n;i++)
					if(tree[i].name==str[0])	ans[cnt++]=i;
			}
		}
		else{
			//���ѡ����
			if(str[0][0]=='#')
				dfs_id(0,0);	//�������ṹ�Ӹ���㿪ʼ����
			else 
				dfs_name(0,0); 
		}
		sort(ans,ans+cnt);
		cout<<cnt;
		for(int i=0;i<cnt;i++)
			cout<<" "<<ans[i];
		cout<<endl; 
	} 
	return 0;
}
