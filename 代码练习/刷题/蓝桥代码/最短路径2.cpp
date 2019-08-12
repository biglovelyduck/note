#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
#define N 200000+5 
const int inf=0x3f3f3f3f;//����
struct node {  //�����ڽӱ�洢ͼ
               // u,v�߶˵㣬next��¼��һ����uΪ���ıߵ��±꣬wȨֵ
	int u,v,next,w;
}e[N]; 
int head[N];
int dis[N]; //�洢��Դ�㵽������ľ���
int vis[N];//����Ƿ���ʹ�
int n,m,cnt;  //cntΪ�ṹ���±�
void add(int u,int v,int w)  //�����ڽӱ�洢ͼ
{
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];   //�洢��һ���ߣ�u->v�ڽṹ���е��±�
    head[u]=cnt++;      //�ѵ�ǰ�ߵ��±����head[u]�У��Ӷ������ٳ��ִ�uָ�������ı�ʱ
}                //���԰��±���������ߵ�.next�У�����e[cnt].next=head[u]
void spfa()         //spfa�㷨�����·��
{
    int i,u,v,w;
    queue<int>q;
    for(i=1;i<=n;i++)
    {
        dis[i]=inf;
        vis[i]=0;
    }
    dis[1]=0;
    vis[1]=1;
    q.push(1);   //Դ�����
    while(!q.empty())
    {
        u=q.front(); //ÿ��ȡ����Ԫ�أ����ʸõ�ָ������б�
        q.pop();
        vis[u]=0;
        for(i=head[u];i!=-1;i=e[i].next) //�����u->v�����һ���ߵ��±�洢��head[u]��
        {     //e[i].nextΪ��һ����uΪ����������±�
            v=e[i].v;  //head[u]��ʼ��Ϊ-1������һ��u->v�ıߡ�nextΪ-1�����������ж��Ƿ����
            w=e[i].w;
            if(dis[v]>dis[u]+w)  //ͨ���õ�������̴�Դ��1����V�ľ���
            {
                dis[v]=dis[u]+w;
                if(!vis[v])    //V�ٴ����
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
 
}
int main()
{
    int i,u,v,w;
    while(~scanf("%d%d",&n,&m))
    {
        cnt=0;
        memset(head,-1,sizeof(head));
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        spfa();
        for(i=2;i<=n;i++)
            printf("%d\n",dis[i]);
    }
    return 0;
}
