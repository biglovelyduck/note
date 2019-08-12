//CCF 消息传递接口(队列) 201903-4 
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
const int N=1e4+7;
struct node{
	int x,y;	//x->y flag=1是S
	bool flag; 
};
int s[N],r[N];
node msg[N][10];	//msg以倒序的方式存储每一个人的所有消息 
int num[N];

queue<node> 	q;
int n;

vs split(string str,const char flag=' '){
	istringstream iss(str);
	vs ans;
	while(getline(iss,str,flag))	//遇到flag就停止读取 
		if(str.size())
			ans.push_back(str);
	return ans;
}

int to_int(string str){
	int ans=0;
	for(int i=0;i<str.size();i++)
		ans=ans*10+str[i]-'0';
	return ans;
}

void get_in(int k){
	if(num[k]){
		q.push(msg[k][num[k]]);
		num[k]--;
	}
}

int main(){
	int T;
	cin>>T>>n;
	getchar();
	while(T--){
		memset(s,-1,sizeof(s));
		memset(r,-1,sizeof(r));
		memset(msg,0,sizeof(msg));
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++){
			string str;
			getline(cin,str);
			vs sv=split(str);
			num[i]=sv.size();	//每一行的元素个数 
			for(int j=0;j<sv.size();j++){
				int k=num[i]-j;		//k慢慢减小 
				msg[i][k].x=i;		
				msg[i][k].y=to_int(sv[j].substr(1));
				if(sv[j][0]=='S') msg[i][k].flag=1;	//S
			}
		}
		for(int i=0;i<n;i++){
			get_in(i);		//开始所有人的第一个进入队列 
		}
		int sum=0;
		while(!q.empty()){
			node tmp=q.front();q.pop();
			bool isOK=0;
			int x=tmp.x,y=tmp.y;
			if(tmp.flag){	//若是发送消息 S:x->y
				if(r[y]==x){
					isOK=1;r[y]=-1;get_in(x);get_in(y);	
				} 
				else s[x]=y;	//不能消去，更新 
			}
			else{			//若是收到消息 
				if(s[y]==x){
					isOK=1;s[y]=-1;get_in(x);get_in(y);
				}
				else r[x]=y;
			}
			if(isOK) sum++;
			else sum--;
		}
		if(sum==0) cout<<"0\n";
		else cout<<"1\n";
	}
	return 0;
}
