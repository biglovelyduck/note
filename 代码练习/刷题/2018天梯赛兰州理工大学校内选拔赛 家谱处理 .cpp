/*
//2018天梯赛兰州理工大学校内选拔赛 家谱处理 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
//思路： 树 
struct node{
	node* parent;
	string name;
	vector<node*> childs;
	node(){
		
	}
	node(string name):name(name){
		
	}
}; 
int main(){
	int n,m;	//家谱中名字的数量，陈述语句数量 
	cin>>n>>m;
	getchar();
	string s;	//输入的一行 
	vector<string> v;	//保存每一行 
	vector<node*> vec;	//存放每个节点 
	int c[n];	//每个人名字的空格数 
	for(int i=0;i<n;i++){
		getline(cin,s);
		v.push_back(s);
	}
	for(int i=0;i<n;i++){
		c[i]=count(v[i].begin(),v[i].end(),' ');
	}
	node* root=new node(v[0]);							//cout<<"创建根成功"<<endl;
	root->parent=NULL;
	vec.push_back(root); 
	for(int i=1;i<n;i++){
		vec.push_back(new node(v[i]));
		if(c[i]!=0){	//有父节点 
			//找到父结点
			for(int j=i-1;j>=0;j--){
				if(c[j]+2==c[i]){
					//j就是父结点
					string name=v[i].substr(c[i]);		//cout<<"name:"<<name<<endl; 
					node* n=new node(name);
					n->parent=vec[j];
					vec[j]->childs.push_back(n);
					break;
				}
			} 
		}
	}
	//到这程序没问题 
	vector<string> query(m);	//保存每条查询语句 
	for(int i=0;i<m;i++){
		getline(cin,s);
		query.push_back(s);
	}															//cout<<"输入成功"<<endl;
	//分割查询语句 
	vector<vector<string> > vect;	//终极查询名字块
	//使用stringstream来切割空格 
	for(int i=0;i<m;i++){
		vector<string> tmp;
		string result;
		stringstream input(query[i]);
		while(input>>result){
			tmp.push_back(result); 			
		}
		for(int i=0;i<tmp.size();i++)
			cout<<tmp[i];
		vect.push_back(tmp);				//??????
	}
	
//	//ceshi
//	for(int i=0;i<m;i++){
//		for(int j=0;j<vect[i].size();j++){
//			cout<<vect[i][j];
//		}
//		cout<<endl;
//	} 
	
	 
	//已经被分割完毕
	for(int i=0;i<m;i++){
		string X=vect[i][0];
		string relation=vect[i][3];
		string Y=vect[i][5];
		if(relation=="child"){
			//查找结点 
			node* n_Y=NULL;
			for(int i=0;i<n;i++){
				if(vec[i]->name==Y){
					n_Y=vec[i];
				}
			}
			bool find=false;
			for(int i=0;i<n_Y->childs.size();i++){
				if(X==n_Y->childs[i]->name) find=true;
			}
			if(find) cout<<"True"<<endl;
			else cout<<"False"<<endl;
		} 
		else if(relation=="parent"){
			
		}
		else if(relation=="sibling"){	// 兄弟 
			
		}
		else if(relation=="descendant") {	//侄子 
			
		}
		else if(relation=="ancestor"){	//祖先 
			
		} 
	} 
	return 0;
} */

//救救孩子吧
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#define mst(a) memset(a,0,sizeof(a))
typedef long long ll;
using namespace std;
/*parent 父亲
child 孩子
ancestor 祖先
sibling 同辈
descendent 后裔*/ 
const int maxn=100+5;
string s;
map<string,int> maps;
int a[maxn],fa[maxn];
vector<int> vec[maxn];
//判断a是不是b的祖宗 
bool dfs(int a,int b){
	if(vec[a].size()==0) return false;
	for(size_t i=0;i<vec[a].size();i++){
		//遍历儿子
		if(vec[a][i]==b) return true;
		if(dfs(vec[a][i],b)) return true;
	}
	return false;
}
bool solve(string stra,string strb,char ch){
	int a=maps[stra];	
	int b=maps[strb];
	switch(ch){
		case 'p':return a==fa[b];break;
		case 'c':return fa[a]==b;break;
		case 'a':return dfs(a,b);break;
		case 's':return fa[a]==fa[b];break;
		case 'd':return dfs(b,a);break;
	}
}
int main(){
	int n,test,cnt=0;
	cin>>n>>test;
	getchar();
	while(n--){		//逐个处理输入的名字 
		string name="";
		s="";
		getline(cin,s);
		int len=(int)s.size();
		int k=0;
		for(int i=0;i<len;i++){
			if(s[i]!=' ') name+=s[i];
			else k++;	//统计空格数量 
		}
		k /=2;			//k是父节点的空格数 
		maps[name]=cnt++; 	//name对应自身的id
		int id=maps[name];
		if(k!=0){
			//如果不是最大的祖先
			vec[a[k]].push_back(id); 	//a[k]根据空格数保存结点id 
			fa[id]=a[k];	//fa[id]保存当前id的父节点id 
		} 
		
		else fa[id]=-1;
		a[k+1]=id;	//更新当前层数的father 
	}
	while(test--){
		string n1,n2,n3,tmp;
		cin>>n1>>tmp>>tmp>>n2>>tmp>>n3;
		if(solve(n1,n3,n2[0])) cout<<"True"<<endl;
		else cout<<"False"<<endl;
	}
	return 0;
}
