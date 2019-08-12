#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <cctype>
#include <string>
#include <cstdio>
using namespace std;
const int N=105;//最大行数 
struct Node{
	string lable;//标签名 
	string id;//id名 
	int d;//缩进 
}a[N]; //每行只有一个标签和id属性 
vector<string> demand;//存放查询的标签分割 
map<string,int> parent;//表示各个祖先含有的标签,id属性 的个数 
map<string,int> query;//表示要查询的标签或id属性的个数 
//将字符串转换为小写串
string& trans(string &s){
	for(int i=0;i<s.length();i++){
		s[i]=tolower(s[i]);//to_lower包含头文件cctype 
	}
	return s;
}
//自己定义的split函数,以空格进行分割字符串，并将结果保存在数组v中
void split(char *s,vector<string> &v){
	v.clear();
	char *p=strtok(s," ");//p指向第一个被分割的字符串,没有字符串返回 NULL 
	while(p){
		v.push_back(p);
		p=strtok(NULL," ");
	} 
} 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();//读取回车
	for(int i=1;i<=n;i++){
		string s;
		getline(cin,s);//将输入的一行的字符串保存到s 
		//统计缩进
		int cnt=0;
		for(int j=0;j<s.length()&&s[j]=='.';j++,cnt++);//结束cnt保存标签起始位置 
		//获取标签
		int len=0,pos=-1;
		//如果有#，pos就记录#的下标
		for(int j=cnt;j<s.length();j++,len++){
			if(s[j]==' '){
				if(j+1<s.length()&&s[j+1]=='#') pos=j+1;
				break;
			} 
		}
		a[i].d=cnt; //第i行的缩进是d
		a[i].lable=s.substr(cnt,len); //len保存标签长度，左闭右开 
		//将标签都转为小写
		a[i].lable=trans(a[i].lable);
		if(pos==-1){
			//没有id属性
			a[i].id=""; 
		} 
		else a[i].id=s.substr(pos);//包含#符 
	}
	//输入查询的字符串 
	while(m--){
		char d[100];
		gets[d];
		split(d,demand); //分割的字符串存放到demand中
		vector<int> ans;//保存行号 
		if(demand.size()==1){//不是后代迭代器，直接匹配 
			string q=demand[0];
			if(q[0]!='#') q[0]=trans(q[0]); 
			//查找进行匹配
			for(int i=1;i<=n;i++){//可能是标签或者#id 
				if(q==a[i].lable||q==a[i].id) ans.push_back(i);//保存行号 
			} 
		} 
		else{//有父元素 
			query.clear();//清空要查询的map
			for(int i=0;i<demand.size()-1;i++){
				//统计标签，id属性的个数
				if(demand[i][0]!='#'){//如果是标签就转换成小写 
					demand[i]=trans(demand[i]); 
				}
				query[demand[i]]++; 
			}
			string q=demand.back();//最后一个string 
			if(q[0]!='#') q=trans(q);
			//进行匹配
			for(int i=1;i<=n;i++){
				if(q==a[i].lable||q==a[i].id){
					//获取a的祖先结点的各个标签和id属性的个数 
					parent.clear();
					for(int j=i-1;j>0&&a[j].d<=a[i].d;j--){
						if(a[j].d==a[i].d) continue;//细节！
						parent[a[j].lable]++;
						if(a[j].id!="") parent[a[j].id]++; 
					} 
					//判断是否符合条件
					bool flag=true;
					//遍历查询所有的id选择器和标签选择器
					for(map<string,int>::iterator it=query.begin();it!=query.end();it++){
						if(parent.count(it->first)==0||parent[it->first]<it->second){
							//如果没有祖先元素或者有暂时数量不够
							flag=false;
							break; 
						}
						if(flag) ans.push_back(i);
					} 
				}
			} 
		} 
	} 
	return 0;
}
 
