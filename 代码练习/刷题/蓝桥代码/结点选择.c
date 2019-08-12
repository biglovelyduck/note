/*  
�㷨ѵ�� ���ѡ��  
  
��������  
��һ�� n ���ڵ����������ÿ���ڵ㶼��һ��������Ȩֵ�����һ���㱻ѡ���ˣ���ô�����Ϻ������ڵĵ㶼���ܱ�ѡ����ѡ���ĵ��Ȩֵ������Ƕ��٣�  
  
�����ʽ  
��һ�а���һ������ n ��  
  
��������һ�а��� n ������������ i ������������� i ��Ȩֵ��  
  
������һ�� n-1 �У�ÿ���������ϵ�һ���ߡ�  
  
�����ʽ  
���һ������������ѡ���ĵ��Ȩֵ�͵����ֵ��  
��������  
5  
1 2 3 4 5  
1 2  
1 3  
2 4  
2 5  
�������  
12  
����˵��  
ѡ��3��4��5�ŵ㣬Ȩֵ��Ϊ 3+4+5 = 12 ��  
���ݹ�ģ��Լ��  
����20%�����ݣ� n <= 20��  
  
����50%�����ݣ� n <= 1000��  
  
����100%�����ݣ� n <= 100000��  
  
Ȩֵ��Ϊ������1000����������  
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
int M;     //��ʾ�ߵ������ţ���ʼΪ0
int head[MAXN];      //��ʾĳ����������ӵı�,��űߵ������� 
int dp[MAXN][2];     //dp[x][0]��ʾ��x����㲻ѡ��ʱ���Ȩֵ��dp[x][1]��ʾ��x�����ѡ��ʱ���Ȩֵ
struct Edge{
    int toNode;      //��ʾ�����ߵ���Ľ��
    int nextEdge;   //��ʾ�����ߵĳ���������ӵ���һ����
}edge[2*MAXN];        //һ����n����㣬��n-1���ߣ����ǲ�ͬ�ĳ������������ͬ�ıߣ�������2n-2����

//���±߼���߼�,������
void add(int from, int to){
    edge[M].toNode = to;
    edge[M].nextEdge = head[from];
    head[from] = M++;                            //head[x]��ֵ���ܻᱻ���θ�ֵ
}

//����dfs����
void dfs(int node, int preNode){
    for (int i = head[node]; i != -1; i = edge[i].nextEdge){
        if (edge[i].toNode == preNode)             //˵���������Ѿ�������
            continue;
        int toNode = edge[i].toNode;           //��ʾ��i����Ľ��
        dfs(toNode, node);
        dp[node][0] += max(dp[toNode][0], dp[toNode][1]);             //�ý�㲻�㣬��ñ��ϵ���һ����ѡҲ�ɲ�ѡ
        dp[node][1] += dp[toNode][0];                                  //�Ľ��ѡ�ˣ��ñ�����һ���Ͳ���ѡ��
    }
}
int main(){
    int n;
    memset(head, -1, sizeof(head));           //���б���Ϊ-1����ʾ�����ڸñ�
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> dp[i][1];                      //ÿһ������Ȩֵ
    }
    for (int j = 1; j <= n - 1; j++){
        int from, to;
        cin >> from >> to;
        add(from, to);              
        add(to, from);
    }
    dfs(1, 0);                      //��1�Ž�㿪ʼ���̬�滮
    int result = max(dp[1][0], dp[1][1]);          //��Ϊ��ȷ������㣬���ԴӼ��ſ�ʼ��̬�滮���Ҽ��ŵ�״̬
                                                                //ͬ������Ҳ����д��      dfs(2, 0);   int result = max(dp[2][0], dp[2][1]);������ֻ��һ������ʱ��Ͳ�����
    cout << result << endl;
    return 0;
}
