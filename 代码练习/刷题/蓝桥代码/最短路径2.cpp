#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
#define N 200000+5 
const int inf=0x3f3f3f3f;//常量
struct node {  //用于邻接表存储图
               // u,v边端点，next记录上一条以u为起点的边的下标，w权值
	int u,v,next,w;
}e[N]; 
int head[N];
int dis[N]; //存储从源点到各个点的距离
int vis[N];//标记是否访问过
int n,m,cnt;  //cnt为结构体下标
void add(int u,int v,int w)  //构建邻接表存储图
{
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];   //存储上一条边，u->v在结构体中的下标
    head[u]=cnt++;      //把当前边的下标存入head[u]中，从而，当再出现从u指向其他的边时
}                //可以把下标存入下条边的.next中，参照e[cnt].next=head[u]
void spfa()         //spfa算法求最短路，
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
    q.push(1);   //源点入队
    while(!q.empty())
    {
        u=q.front(); //每次取队首元素，访问该点指向的所有边
        q.pop();
        vis[u]=0;
        for(i=head[u];i!=-1;i=e[i].next) //顶点从u->v的最后一条边的下标存储在head[u]中
        {     //e[i].next为上一条以u为起点的有向边下标
            v=e[i].v;  //head[u]初始化为-1，即第一条u->v的边。next为-1，访问依此判断是否结束
            w=e[i].w;
            if(dis[v]>dis[u]+w)  //通过该点可以缩短从源点1到点V的距离
            {
                dis[v]=dis[u]+w;
                if(!vis[v])    //V再次入队
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
