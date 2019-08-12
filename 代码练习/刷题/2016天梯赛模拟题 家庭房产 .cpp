//2016天梯赛模拟题 家庭房产 
//此题代码网上抄袭 
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)

//考察并查集
//思路：每个家庭归为一个并查集 

#define MAX 10005
int p[MAX],visit[MAX]={0},la[MAX]={0};
struct node
{
    int id , people ;	//这个家庭成员的最小编号，家庭人数 
    double sum , num ;//这个家庭的人均面积，人房产套数 
};
node person[MAX] ,ans[MAX],p2[MAX];	//p2存放每个大家庭 
bool comp(const struct node&a,const struct node&b)
{
    if(a.sum == b.sum)
        return a.id < b.id;
    return a.sum > b.sum;
}
int Find(int x)	//找到编号为x的根结点编号 
{
	/*
    int temp = x ;
    while(p[temp]!=temp)
        temp = p[temp] ;
    return temp;*/
    if(p[x]==x) return x;
    else return p[x]=Find(p[x]);
}
void join(int x , int y) 
{
    int t1 , t2 ;
    t1 = Find(x) ;
    t2 = Find(y) ;
    if(t1 != t2)
    {
        if(t1 > t2)
        {
            p[t1] = t2 ;
        }
        else p[t2] = t1 ;
    }
}
int main()
{
    int n ,id, nm , nf , k , nk;	//人数，自己编号，父、母编号 
    double hn , hs;
    scanf("%d" , &n);	//n个人 
    for(int i = 0 ; i <MAX ; i ++)
    {
        p[i] = i ;		//初始化n个人的父亲 ，初始化并查集 
    }
    for(int i = 0 ; i <n ; i ++)
    {
        scanf("%d%d%d",&id,&nf,&nm);	//每个人的编号，父亲编号，母亲编号 
        visit[id] = 1 ;											//表示已经归为一个集合？ 
        if(nm!=-1) {join(id,nm);visit[nm]=1;}	//合并为一个集合（大家庭） 
        if(nf!=-1) {join(id,nf);visit[nf]=1;}
        scanf("%d",&k);		 
        for(int i = 0 ; i < k ; i ++)
        {
            scanf("%d" , &nk);	//每个孩子的编号 
            if(nk!=-1)
            {
                join(id,nk);
                visit[nk] = 1;
            }
        }
        scanf("%lf%lf",&person[i].num,&person[i].sum);	//这个人的房产套数和总面积 
        person[i].id = id;
    }
    for(int i = 0 ; i < n ; i ++)
    {
        int tid = Find(person[i].id);	//找到这个人所在大家庭的根 
        p2[tid].id = tid;
        p2[tid].num += person[i].num;
        p2[tid].sum += person[i].sum;
        //cout << p2[tid].sum<<endl;
    }
    int ren = 0 ;
    for(int i = 0 ; i < MAX ; i ++)
    {
        if(visit[i])
            p2[Find(i)].people++;		//该家族人数加1 
    }
    for(int i = 0 ; i <MAX ; i ++)
    {
        if(visit[i])
        {
            int ttt = Find(i) ;
            if(!la[ttt])		//标记 
            {
                la[ttt] = 1 ;
                //cout <<p2[ttt].num<<endl;
                double xx = double(p2[ttt].people);
                ans[ren].id = ttt;
                ans[ren].num = p2[ttt].num*1.0/xx;
                ans[ren].sum = p2[ttt].sum*1.0/xx;
                ans[ren++].people = int(xx) ;
            }
        }
    }
    printf("%d\n" , ren) ;	//家庭的个数 
    sort(ans,ans+ren,comp);	//给每个家庭排序 
    for(int i = 0 ; i < ren ; i ++)
        printf("%04d %d %.3f %.3f\n" , ans[i].id,ans[i].people,ans[i].num,ans[i].sum);
    return 0 ;
}

