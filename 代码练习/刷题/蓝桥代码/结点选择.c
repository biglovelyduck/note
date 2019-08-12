/*  
算法训练 结点选择  
  
问题描述  
有一棵 n 个节点的树，树上每个节点都有一个正整数权值。如果一个点被选择了，那么在树上和它相邻的点都不能被选择。求选出的点的权值和最大是多少？  
  
输入格式  
第一行包含一个整数 n 。  
  
接下来的一行包含 n 个正整数，第 i 个正整数代表点 i 的权值。  
  
接下来一共 n-1 行，每行描述树上的一条边。  
  
输出格式  
输出一个整数，代表选出的点的权值和的最大值。  
样例输入  
5  
1 2 3 4 5  
1 2  
1 3  
2 4  
2 5  
样例输出  
12  
样例说明  
选择3、4、5号点，权值和为 3+4+5 = 12 。  
数据规模与约定  
对于20%的数据， n <= 20。  
  
对于50%的数据， n <= 1000。  
  
对于100%的数据， n <= 100000。  
  
权值均为不超过1000的正整数。  
*/  
/*
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
  
typedef struct Node  
{  
    int to;  
    int next;  
}Node;  
  
#define N 100020  
  
int max(int a, int b)  
{  
    return a > b ? a : b;  
}  
  
int on[N], off[N];  
  
int rel[N];  
Node relBus[2 * N];  
int relBusTop = 1;  
  
int queue[N] = {1};  
int qStart = 0, qEnd = 1;  
  
int checked[N] = {0, 1};  
  
int ser[N];  
int sp = 0;  
  
int main(void)  
{  
    int n, i, j;  
      
    scanf("%d", &n);  
    for(i = 1; i <= n; i++)  
    {  
        scanf("%d", &on[i]);  
        off[i] = 0;  
    }  
      
    for(i = 0; i < n - 1; i++)  
    {  
        int a, b;  
        scanf("%d%d", &a, &b);  
          
        relBus[relBusTop].to = b;  
        relBus[relBusTop].next = rel[a];  
        rel[a] = relBusTop++;  
          
        relBus[relBusTop].to = a;  
        relBus[relBusTop].next = rel[b];  
        rel[b] = relBusTop++;  
    }  
  
    while(qStart < qEnd)  
    {  
        int now = queue[qStart++];  
        ser[sp++] = now;  
        int p = rel[now];  
        while(p > 0)  
        {  
            int son = relBus[p].to;  
            if(checked[son] == 0)  
            {  
                queue[qEnd++] = son;  
                checked[son] = 1;  
            }  
            p = relBus[p].next;  
        }  
    }  
      
    for(i = n - 1; i >= 0; i--)  
    {  
        int son = ser[i];  
        int p = rel[son];  
          
        while(p > 0)  
        {  
            int father = relBus[p].to;  
              
            on[father] += off[son];  
            off[father] += max(on[son], off[son]);  
            p = relBus[p].next;  
        }  
    }  
      
    printf("%d", max(on[1], off[1]));  
    return 0;  
}*/  
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;    
#define max(a,b) a>b?a:b
const int MAXN = 100001;
int M;     //表示边的索引号，初始为0
int head[MAXN];      //表示某个结点所连接的边,存放边的索引号 
int dp[MAXN][2];     //dp[x][0]表示第x个结点不选择时最大权值，dp[x][1]表示第x个结点选择时最大权值
struct Edge{
    int toNode;      //表示这条边到达的结点
    int nextEdge;   //表示这条边的出发结点连接的下一条边
}edge[2*MAXN];        //一共有n个结点，有n-1条边，但是不同的出发结点算作不同的边，所以有2n-2条边

//把新边加入边集,构造树
void add(int from, int to){
    edge[M].toNode = to;
    edge[M].nextEdge = head[from];
    head[from] = M++;                            //head[x]的值可能会被二次赋值
}

//类似dfs遍历
void dfs(int node, int preNode){
    for (int i = head[node]; i != -1; i = edge[i].nextEdge){
        if (edge[i].toNode == preNode)             //说明这条边已经搜索过
            continue;
        int toNode = edge[i].toNode;           //表示边i到达的结点
        dfs(toNode, node);
        dp[node][0] += max(dp[toNode][0], dp[toNode][1]);             //该结点不算，则该边上的另一结点可选也可不选
        dp[node][1] += dp[toNode][0];                                  //改结点选了，该边上另一结点就不能选了
    }
}
int main(){
    int n;
    memset(head, -1, sizeof(head));           //所有边置为-1，表示不存在该边
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> dp[i][1];                      //每一个结点的权值
    }
    for (int j = 1; j <= n - 1; j++){
        int from, to;
        cin >> from >> to;
        add(from, to);              
        add(to, from);
    }
    dfs(1, 0);                      //从1号结点开始向后动态规划
    int result = max(dp[1][0], dp[1][1]);          //因为不确定根结点，所以从几号开始动态规划就找几号的状态
                                                                //同样这里也可以写成      dfs(2, 0);   int result = max(dp[2][0], dp[2][1]);不过当只有一个结点的时候就不对了
    cout << result << endl;
    return 0;
}
