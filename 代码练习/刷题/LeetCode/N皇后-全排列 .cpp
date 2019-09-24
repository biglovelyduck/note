//N皇后-全排列 
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
int sum=0;						//排列的个数 
int P[MAX_N];					//P[i]表示第i列皇后所在的行号
int n;							//n皇后
int hasTable[MAX_N];			//hasTable[i]表示第i行是否被访问过
//产生index-n的全排列
void generateP1(int index){
    if(index==n+1){				//递归边界，产生一个排列
        bool flag=true;			//假设当前排列是一个合法方案
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //检查遍历任意俩皇后，如果在同一对角线则不合法
                if(abs(i-j)==abs(P[i]-P[j]))	flag=false;
            }
        }
        if(flag) sum++;
        return;
    }
    for(int x=1;x<=n;x++){		//遍历每行
        if(hasTable[x]==false){	//如果当前行没有被用 
            P[index]=x;			//在index列放置对应的行，试探所有的行		
            hasTable[x]=true;
            generateP1(index+1);
            hasTable[x]=false;
        }
    }
}
//回溯优化
void generateP2(int index){
	if(index==n+1){
		sum++;
		return;
	}
	for(int x=1;x<=n;x++){			//遍历每行 
		if(hasTable[x]==false){
			//在这做个判断，判断第x行能否放置皇后
			bool flag=true;			//假设先可以放置，index是当前皇后所在的列 
			for(int pre=1;pre<index;pre++){	//遍历之前放置好的皇后（遍历每列），检测是否有冲突 
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
int a[8];								//a[i]表示i行所在的列 
bool attack(int x0,int y0,int x1,int y1){//表示两个位置是否可以攻击，是返回true
    if(x0==x1||y0==y1) return true;
    if(x0+y0==x1+y1||x0-y0==x1-y1) return true;
    return false;
}
void dfs(int x){						//从第x行开始
    if(x==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){				//逐列试探
        bool ok=true;					//假设符合 
        for(int j=0;j<x;j++){			//检查之前的行
            if(attack(j,a[j],x,i)){
                ok=false;
                break;					//这一列不符合,找下一列
            }
        }
        if(ok){
            a[x]=i;						//这一列符合，就放置皇后 
            dfs(x+1);					//递归深搜
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
