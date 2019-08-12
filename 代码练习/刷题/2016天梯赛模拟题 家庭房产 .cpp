//2016������ģ���� ��ͥ���� 
//����������ϳ�Ϯ 
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

//���첢�鼯
//˼·��ÿ����ͥ��Ϊһ�����鼯 

#define MAX 10005
int p[MAX],visit[MAX]={0},la[MAX]={0};
struct node
{
    int id , people ;	//�����ͥ��Ա����С��ţ���ͥ���� 
    double sum , num ;//�����ͥ���˾�������˷������� 
};
node person[MAX] ,ans[MAX],p2[MAX];	//p2���ÿ�����ͥ 
bool comp(const struct node&a,const struct node&b)
{
    if(a.sum == b.sum)
        return a.id < b.id;
    return a.sum > b.sum;
}
int Find(int x)	//�ҵ����Ϊx�ĸ������ 
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
    int n ,id, nm , nf , k , nk;	//�������Լ���ţ�����ĸ��� 
    double hn , hs;
    scanf("%d" , &n);	//n���� 
    for(int i = 0 ; i <MAX ; i ++)
    {
        p[i] = i ;		//��ʼ��n���˵ĸ��� ����ʼ�����鼯 
    }
    for(int i = 0 ; i <n ; i ++)
    {
        scanf("%d%d%d",&id,&nf,&nm);	//ÿ���˵ı�ţ����ױ�ţ�ĸ�ױ�� 
        visit[id] = 1 ;											//��ʾ�Ѿ���Ϊһ�����ϣ� 
        if(nm!=-1) {join(id,nm);visit[nm]=1;}	//�ϲ�Ϊһ�����ϣ����ͥ�� 
        if(nf!=-1) {join(id,nf);visit[nf]=1;}
        scanf("%d",&k);		 
        for(int i = 0 ; i < k ; i ++)
        {
            scanf("%d" , &nk);	//ÿ�����ӵı�� 
            if(nk!=-1)
            {
                join(id,nk);
                visit[nk] = 1;
            }
        }
        scanf("%lf%lf",&person[i].num,&person[i].sum);	//����˵ķ�������������� 
        person[i].id = id;
    }
    for(int i = 0 ; i < n ; i ++)
    {
        int tid = Find(person[i].id);	//�ҵ���������ڴ��ͥ�ĸ� 
        p2[tid].id = tid;
        p2[tid].num += person[i].num;
        p2[tid].sum += person[i].sum;
        //cout << p2[tid].sum<<endl;
    }
    int ren = 0 ;
    for(int i = 0 ; i < MAX ; i ++)
    {
        if(visit[i])
            p2[Find(i)].people++;		//�ü���������1 
    }
    for(int i = 0 ; i <MAX ; i ++)
    {
        if(visit[i])
        {
            int ttt = Find(i) ;
            if(!la[ttt])		//��� 
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
    printf("%d\n" , ren) ;	//��ͥ�ĸ��� 
    sort(ans,ans+ren,comp);	//��ÿ����ͥ���� 
    for(int i = 0 ; i < ren ; i ++)
        printf("%04d %d %.3f %.3f\n" , ans[i].id,ans[i].people,ans[i].num,ans[i].sum);
    return 0 ;
}

