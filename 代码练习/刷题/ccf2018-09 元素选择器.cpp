//ccf2018-09 元素选择器 
//思路：构造出树 
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
//树的结点 
struct node{
	string name,id;
}tree[N];
stack<int> s;	//用栈来辅助构造树 
vector<int> g[N];	//邻接表 
int pre[N];		//保存每行的前缀点的个数 
int num;	//保存选择器的层数 
string str[N];	//保存选择器的单词 
int cnt,ans[N];		//保存答案	,cnt是个数，ans保存行号 
int n,m;
void dfs_name(int u,int d); 
void dfs_id(int u,int d)  //匹配id
{
    if(tree[u].id==str[d]) d++;
    if(d>num) ans[cnt++]=u,d=num;  //匹配完最后一个，要继续匹配最后一个
    for(int i=0;i<g[u].size();i++)
        if(str[d][0]=='#') dfs_id(g[u][i],d);
        else dfs_name(g[u][i],d);
}

void dfs_name(int u,int d){
	if(tree[u].name==str[d])	d++;	//匹配成功
	if(d>num)	ans[cnt++]=u,d=num; //匹配完最后一个，要继续匹配最后一个 
	for(int i=0;i<g[u].size();i++){	//遍历该结点的子结点 
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
		getline(cin,in);	//输入的一行存放到string in里 
		pre[i]=0;
		bool flag=false;
		string name="",id="";
		//提取层级，标签，id信息
		for(int j=0;j<in.length();j++){
			if(in[j]=='.') pre[i]++;
			else if(in[j]==' '){
				//遇到空格了
				flag=true;
				while(j+1<in.length()&&in[j+1]==' ') j++; 
			}
			else{
				//遇到标签
				if(!flag) name+=tolower(in[j]);
				//遇到标签 
				else id+=in[j];
			}
		}
		//运行到这，能够将该行的各种信息提取出来
		tree[i].name=name;
		tree[i].id=id;
		//用栈辅助建造树，查找前面小于 自己点数的行
		while(!s.empty()&&pre[s.top()]>=pre[i]) s.pop();	//用来查找自己的父节点 
		if(!s.empty()) g[s.top()].push_back(i);		//某个点邻接的所有子节点 
		else g[0].push_back(i);	 //使用结点0来作为总根
		s.push(i); 
	}
	while(m--){
		getline(cin,in);
		num=0;		//保存单词的个数 
		str[0]="";		//初始化第一个单词 
		for(int i=0;i<in.length();i++){
			//把单词提取出来
			if(in[i]==' '){
				if(str[num]!="")
					num++,str[num]="";		//初始化另一个单词 
				while(i+1<in.length()&&in[i+1]==' ') i++;	
			}
			else str[num]+=in[i]; 
		}
		if(str[num]=="")	num--;
		for(int i=0;i<=num;i++){
			//将标签转换为小写,id属性的大小写敏感 
			if(str[i][0]!='#')
				for(int j=0;j<str[i].length();j++)
					str[i][j]=tolower(str[i][j]); 
		}
		cnt=0;
		if(num==0){		//只有一个单词 
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
			//后代选择器
			if(str[0][0]=='#')
				dfs_id(0,0);	//按照树结构从根结点开始查找
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
