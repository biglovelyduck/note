//2018 �������⼯������   ������ֵÿ�
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

bool flag[1005];
 
int read(){				//��ȡ��Ƭ���ÿ���� 
    int sign=0,ans=0;
    char a=getchar();
    if((a<'0'||a>'9')&&(a!='-'))
        a=getchar();
    if(a=='-'){
        sign=1;
        a=getchar();
    }
    while(a>='0'&&a<='9'){
        ans=ans*10+a-'0';
        a=getchar();
    }
    flag[ans]=sign;
    return ans;
}
 
int main(){
    int n,m;
    scanf("%d%d",&n,&m);	//n���ˣ�m����Ƭ�� 
    memset(flag,false,sizeof(flag));
    vector<vector<int> > p(n);	//������Ƭ 
    vector<double> pa(n,0.0),pb(n,0.0);
    int c;
    for(int i=0;i<m;i++){
        scanf("%d",&c);		//��Ƭ�������
        p[i].resize(c);
        for(int j=0;j<c;j++)
            p[i][j]=read();
    }
    int a,b;
    a=read();b=read();
    double maxa=0.0,maxb=0.0;
    for(int i=0;i<m;i++){
        bool finda=find(p[i].begin(),p[i].end(),a)!=p[i].end();
        bool findb=find(p[i].begin(),p[i].end(),b)!=p[i].end();
        if(finda||findb){
            for(int j=0;j<p[i].size();j++){
                if(finda&&flag[a]!=flag[p[i][j]]){
                    pa[p[i][j]]+=(double)1.0/p[i].size();
                    maxa=max(maxa,pa[p[i][j]]);
                }
                else if(findb&&flag[b]!=flag[p[i][j]]){
                    pb[p[i][j]]+=(double)1.0/p[i].size();
                    maxb=max(maxb,pb[p[i][j]]);
                }
            }
        }
    }
    if(maxa==pa[b]&&maxb==pb[a]){
        printf("%s%d %s%d\n",flag[a]?"-":"",a,flag[b]?"-":"",b);
    }
    else{
        for(int i=0;i<n;i++){
            if(pa[i]==maxa)
                printf("%s%d %s%d\n",flag[a]?"-":"",a,flag[b]?"-":"",i);
        }
        for(int i=0;i<n;i++){
            if(pb[i]==maxb)
                printf("%s%d %s%d\n",flag[b]?"-":"",b,flag[a]?"-":"",i);
        }
    }
    return 0;
}

