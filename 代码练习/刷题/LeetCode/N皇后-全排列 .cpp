//N�ʺ�-ȫ���� 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
const int MAX_N=101; 
int sum=0;						//���еĸ��� 
int P[MAX_N];					//P[i]��ʾ��i�лʺ����ڵ��к�
int n;							//n�ʺ�
int hasTable[MAX_N];			//hasTable[i]��ʾ��i���Ƿ񱻷��ʹ�
//����index-n��ȫ����
void generateP1(int index){
    if(index==n+1){				//�ݹ�߽磬����һ������
        bool flag=true;			//���赱ǰ������һ���Ϸ�����
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //�������������ʺ������ͬһ�Խ����򲻺Ϸ�
                if(abs(i-j)==abs(P[i]-P[j]))	flag=false;
            }
        }
        if(flag) sum++;
        return;
    }
    for(int x=1;x<=n;x++){		//����ÿ��
        if(hasTable[x]==false){	//�����ǰ��û�б��� 
            P[index]=x;			//��index�з��ö�Ӧ���У���̽���е���		
            hasTable[x]=true;
            generateP1(index+1);
            hasTable[x]=false;
        }
    }
}
//�����Ż�
void generateP2(int index){
	if(index==n+1){
		sum++;
		return;
	}
	for(int x=1;x<=n;x++){			//����ÿ�� 
		if(hasTable[x]==false){
			//���������жϣ��жϵ�x���ܷ���ûʺ�
			bool flag=true;			//�����ȿ��Է��ã�index�ǵ�ǰ�ʺ����ڵ��� 
			for(int pre=1;pre<index;pre++){	//����֮ǰ���úõĻʺ󣨱���ÿ�У�������Ƿ��г�ͻ 
				if(abs(index-pre)==abs(x-P[pre])){
					flag=false;
					break;
				}
			} 
			if(flag){
				P[index]=x;
				hasTable[x]=true;
				generateP2(index+1);
				hasTable[x]=false;
			}
		}
	}
} 

//DFS:
int ans=0;
int a[8];								//a[i]��ʾi�����ڵ��� 
bool attack(int x0,int y0,int x1,int y1){//��ʾ����λ���Ƿ���Թ������Ƿ���true
    if(x0==x1||y0==y1) return true;
    if(x0+y0==x1+y1||x0-y0==x1-y1) return true;
    return false;
}
void dfs(int x){						//�ӵ�x�п�ʼ
    if(x==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){				//������̽
        bool ok=true;					//������� 
        for(int j=0;j<x;j++){			//���֮ǰ����
            if(attack(j,a[j],x,i)){
                ok=false;
                break;					//��һ�в�����,����һ��
            }
        }
        if(ok){
            a[x]=i;						//��һ�з��ϣ��ͷ��ûʺ� 
            dfs(x+1);					//�ݹ�����
        }
    }
} 

int main(){
	memset(P,0,sizeof(P));
	memset(hasTable,false,sizeof(hasTable));
	cin>>n; 
	generateP2(1);
	cout<<sum<<endl;
	return 0;
} 
