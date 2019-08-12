//CCF ��Ϣ���ݽӿ�(����) 201903-4 
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
const int N=1e4+7;
struct node{
	int x,y;	//x->y flag=1��S
	bool flag; 
};
int s[N],r[N];
node msg[N][10];	//msg�Ե���ķ�ʽ�洢ÿһ���˵�������Ϣ 
int num[N];

queue<node> 	q;
int n;

vs split(string str,const char flag=' '){
	istringstream iss(str);
	vs ans;
	while(getline(iss,str,flag))	//����flag��ֹͣ��ȡ 
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
			num[i]=sv.size();	//ÿһ�е�Ԫ�ظ��� 
			for(int j=0;j<sv.size();j++){
				int k=num[i]-j;		//k������С 
				msg[i][k].x=i;		
				msg[i][k].y=to_int(sv[j].substr(1));
				if(sv[j][0]=='S') msg[i][k].flag=1;	//S
			}
		}
		for(int i=0;i<n;i++){
			get_in(i);		//��ʼ�����˵ĵ�һ��������� 
		}
		int sum=0;
		while(!q.empty()){
			node tmp=q.front();q.pop();
			bool isOK=0;
			int x=tmp.x,y=tmp.y;
			if(tmp.flag){	//���Ƿ�����Ϣ S:x->y
				if(r[y]==x){
					isOK=1;r[y]=-1;get_in(x);get_in(y);	
				} 
				else s[x]=y;	//������ȥ������ 
			}
			else{			//�����յ���Ϣ 
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
