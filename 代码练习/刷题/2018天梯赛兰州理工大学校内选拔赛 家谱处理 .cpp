/*
//2018��������������ѧУ��ѡ���� ���״��� 
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
//˼·�� �� 
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
	int n,m;	//���������ֵ������������������ 
	cin>>n>>m;
	getchar();
	string s;	//�����һ�� 
	vector<string> v;	//����ÿһ�� 
	vector<node*> vec;	//���ÿ���ڵ� 
	int c[n];	//ÿ�������ֵĿո��� 
	for(int i=0;i<n;i++){
		getline(cin,s);
		v.push_back(s);
	}
	for(int i=0;i<n;i++){
		c[i]=count(v[i].begin(),v[i].end(),' ');
	}
	node* root=new node(v[0]);							//cout<<"�������ɹ�"<<endl;
	root->parent=NULL;
	vec.push_back(root); 
	for(int i=1;i<n;i++){
		vec.push_back(new node(v[i]));
		if(c[i]!=0){	//�и��ڵ� 
			//�ҵ������
			for(int j=i-1;j>=0;j--){
				if(c[j]+2==c[i]){
					//j���Ǹ����
					string name=v[i].substr(c[i]);		//cout<<"name:"<<name<<endl; 
					node* n=new node(name);
					n->parent=vec[j];
					vec[j]->childs.push_back(n);
					break;
				}
			} 
		}
	}
	//�������û���� 
	vector<string> query(m);	//����ÿ����ѯ��� 
	for(int i=0;i<m;i++){
		getline(cin,s);
		query.push_back(s);
	}															//cout<<"����ɹ�"<<endl;
	//�ָ��ѯ��� 
	vector<vector<string> > vect;	//�ռ���ѯ���ֿ�
	//ʹ��stringstream���и�ո� 
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
	
	 
	//�Ѿ����ָ����
	for(int i=0;i<m;i++){
		string X=vect[i][0];
		string relation=vect[i][3];
		string Y=vect[i][5];
		if(relation=="child"){
			//���ҽ�� 
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
		else if(relation=="sibling"){	// �ֵ� 
			
		}
		else if(relation=="descendant") {	//ֶ�� 
			
		}
		else if(relation=="ancestor"){	//���� 
			
		} 
	} 
	return 0;
} */

//�ȾȺ��Ӱ�
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
/*parent ����
child ����
ancestor ����
sibling ͬ��
descendent ����*/ 
const int maxn=100+5;
string s;
map<string,int> maps;
int a[maxn],fa[maxn];
vector<int> vec[maxn];
//�ж�a�ǲ���b������ 
bool dfs(int a,int b){
	if(vec[a].size()==0) return false;
	for(size_t i=0;i<vec[a].size();i++){
		//��������
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
	while(n--){		//���������������� 
		string name="";
		s="";
		getline(cin,s);
		int len=(int)s.size();
		int k=0;
		for(int i=0;i<len;i++){
			if(s[i]!=' ') name+=s[i];
			else k++;	//ͳ�ƿո����� 
		}
		k /=2;			//k�Ǹ��ڵ�Ŀո��� 
		maps[name]=cnt++; 	//name��Ӧ�����id
		int id=maps[name];
		if(k!=0){
			//���������������
			vec[a[k]].push_back(id); 	//a[k]���ݿո���������id 
			fa[id]=a[k];	//fa[id]���浱ǰid�ĸ��ڵ�id 
		} 
		
		else fa[id]=-1;
		a[k+1]=id;	//���µ�ǰ������father 
	}
	while(test--){
		string n1,n2,n3,tmp;
		cin>>n1>>tmp>>tmp>>n2>>tmp>>n3;
		if(solve(n1,n3,n2[0])) cout<<"True"<<endl;
		else cout<<"False"<<endl;
	}
	return 0;
}
