//ccf2018-03 ������� 
/*״̬ѹ��+����+����
���Ȱ���ְ���3����ѹ��Ϊһ�������������������Ϊ����ȥ�������Ƚϼ��
�����˶�Ҫ�����Ų����������ǲ��ģ������ͼ򵥵ı���µ�ǰ���ĸ�����
��Alice�͵ݹ��ѡ��������ܵõ�����������Bob������С����*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int p[12];	//������״̬ѹ�������� 
int judge(int d){
	int a[10],t=0;	//tΪ�ո��� 
	for(int i=8;i>=0;i--){
		a[i]=d%3;
		d/=3;
		if(a[i]==0) t++;
	}
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==1||
        a[3]==a[4]&&a[4]==a[5]&&a[5]==1||        
		a[6]==a[7]&&a[7]==a[8]&&a[8]==1||        
		a[0]==a[3]&&a[3]==a[6]&&a[6]==1||        
		a[1]==a[4]&&a[4]==a[7]&&a[7]==1||        
		a[2]==a[5]&&a[5]==a[8]&&a[8]==1||        
		a[0]==a[4]&&a[4]==a[8]&&a[8]==1||        
		a[2]==a[4]&&a[4]==a[6]&&a[6]==1)        
		return t+1;    
	if(a[0]==a[1]&&a[1]==a[2]&&a[2]==2||        
		a[3]==a[4]&&a[4]==a[5]&&a[5]==2||        
		a[6]==a[7]&&a[7]==a[8]&&a[8]==2||        
		a[0]==a[3]&&a[3]==a[6]&&a[6]==2||        
		a[1]==a[4]&&a[4]==a[7]&&a[7]==2||        
		a[2]==a[5]&&a[5]==a[8]&&a[8]==2||        
		a[0]==a[4]&&a[4]==a[8]&&a[8]==2||        
		a[2]==a[4]&&a[4]==a[6]&&a[6]==2)        
		return -t-1;    
	return 0;

}
int dfs(int d,int f){
	int ret=judge(d);	//���ص�ǰ���̵ĵ÷�
	if(ret!=0) return ret;	//�����˷��ؽ��
	//���廹û�н���
	int t=d,num=0; 		//dֻ�Ǵ������Ĳ���d,t����ʱ���沢����t,num�������ǰ���̵Ŀո��� 
	for(int i=0;i<9;i++){
		if(t%3==0) num++;
		t/=3;
	} 
	if(!num) return 0;	//ƽ��
	if(f>0){	//��ʾ�ֵ�Allice���� 
		int t=d;
		ret=-10;
		for(int i=0;i<9;i++){
			if(t%3==0) ret=max(ret,dfs(d+p[i],-f));
			t/=3;
		}
	}
	else{		//f<0��ʾ�ֵ�Bob���� 
		int t=d;
		ret=10;
		for(int i=0;i<9;i++){
			if(t%3==0) ret=min(ret,dfs(d+2*p[i],-f));
			t/=3;
		}
	}
	return ret;	 
}
int main(){
	p[0]=1;
	for(int i=1;i<10;i++){
		p[i]=3*p[i-1];	//p1=3,p2=9,p3=27	��ʼ������ 
	}
	int T;	//�������ݵ����� 
	cin>>T;   
	while(T--){
		int a,d=0;
		for(int i=0;i<9;i++){
			cin>>a;
			d=d*3+a;	// 
		}
		cout<<dfs(d,1);		
	} 
	return 0;
}
