#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <cctype>
#include <string>
#include <cstdio>
using namespace std;
const int N=105;//������� 
struct Node{
	string lable;//��ǩ�� 
	string id;//id�� 
	int d;//���� 
}a[N]; //ÿ��ֻ��һ����ǩ��id���� 
vector<string> demand;//��Ų�ѯ�ı�ǩ�ָ� 
map<string,int> parent;//��ʾ�������Ⱥ��еı�ǩ,id���� �ĸ��� 
map<string,int> query;//��ʾҪ��ѯ�ı�ǩ��id���Եĸ��� 
//���ַ���ת��ΪСд��
string& trans(string &s){
	for(int i=0;i<s.length();i++){
		s[i]=tolower(s[i]);//to_lower����ͷ�ļ�cctype 
	}
	return s;
}
//�Լ������split����,�Կո���зָ��ַ����������������������v��
void split(char *s,vector<string> &v){
	v.clear();
	char *p=strtok(s," ");//pָ���һ�����ָ���ַ���,û���ַ������� NULL 
	while(p){
		v.push_back(p);
		p=strtok(NULL," ");
	} 
} 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();//��ȡ�س�
	for(int i=1;i<=n;i++){
		string s;
		getline(cin,s);//�������һ�е��ַ������浽s 
		//ͳ������
		int cnt=0;
		for(int j=0;j<s.length()&&s[j]=='.';j++,cnt++);//����cnt�����ǩ��ʼλ�� 
		//��ȡ��ǩ
		int len=0,pos=-1;
		//�����#��pos�ͼ�¼#���±�
		for(int j=cnt;j<s.length();j++,len++){
			if(s[j]==' '){
				if(j+1<s.length()&&s[j+1]=='#') pos=j+1;
				break;
			} 
		}
		a[i].d=cnt; //��i�е�������d
		a[i].lable=s.substr(cnt,len); //len�����ǩ���ȣ�����ҿ� 
		//����ǩ��תΪСд
		a[i].lable=trans(a[i].lable);
		if(pos==-1){
			//û��id����
			a[i].id=""; 
		} 
		else a[i].id=s.substr(pos);//����#�� 
	}
	//�����ѯ���ַ��� 
	while(m--){
		char d[100];
		gets[d];
		split(d,demand); //�ָ���ַ�����ŵ�demand��
		vector<int> ans;//�����к� 
		if(demand.size()==1){//���Ǻ����������ֱ��ƥ�� 
			string q=demand[0];
			if(q[0]!='#') q[0]=trans(q[0]); 
			//���ҽ���ƥ��
			for(int i=1;i<=n;i++){//�����Ǳ�ǩ����#id 
				if(q==a[i].lable||q==a[i].id) ans.push_back(i);//�����к� 
			} 
		} 
		else{//�и�Ԫ�� 
			query.clear();//���Ҫ��ѯ��map
			for(int i=0;i<demand.size()-1;i++){
				//ͳ�Ʊ�ǩ��id���Եĸ���
				if(demand[i][0]!='#'){//����Ǳ�ǩ��ת����Сд 
					demand[i]=trans(demand[i]); 
				}
				query[demand[i]]++; 
			}
			string q=demand.back();//���һ��string 
			if(q[0]!='#') q=trans(q);
			//����ƥ��
			for(int i=1;i<=n;i++){
				if(q==a[i].lable||q==a[i].id){
					//��ȡa�����Ƚ��ĸ�����ǩ��id���Եĸ��� 
					parent.clear();
					for(int j=i-1;j>0&&a[j].d<=a[i].d;j--){
						if(a[j].d==a[i].d) continue;//ϸ�ڣ�
						parent[a[j].lable]++;
						if(a[j].id!="") parent[a[j].id]++; 
					} 
					//�ж��Ƿ��������
					bool flag=true;
					//������ѯ���е�idѡ�����ͱ�ǩѡ����
					for(map<string,int>::iterator it=query.begin();it!=query.end();it++){
						if(parent.count(it->first)==0||parent[it->first]<it->second){
							//���û������Ԫ�ػ�������ʱ��������
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
 
