/*栋栋最近开了一家餐饮连锁店，提供外卖服务。随着连锁店越来越多，怎么合理的给客户送餐成为了一个急需解决的问题。
　栋栋的连锁店所在的区域可以看成是一个n×n的方格图（如下图所示），方格的格点上的位置上可能包含栋栋的分店（绿色标注）
  或者客户（蓝色标注），有一些格点是不能经过的（红色标注）。
　方格图中的线表示可以行走的道路，相邻两个格点的距离为1。栋栋要送餐必须走可以行走的道路，而且不能经过红色标注的点。
送餐的主要成本体现在路上所花的时间，每一份餐每走一个单位的距离需要花费1块钱。每个客户的需求都可以由栋栋的任意分店配送，每个分店没有配送总量的限制。
　　现在你得到了栋栋的客户的需求，请问在最优的送餐方式下，送这些餐需要花费多大的成本。
输入格式
　　输入的第一行包含四个整数n, m, k, d，分别表示方格图的大小、栋栋的分店数量、客户的数量，以及不能经过的点的数量。
　　接下来m行，每行两个整数xi, yi，表示栋栋的一个分店在方格图中的横坐标和纵坐标。
　　接下来k行，每行三个整数xi, yi, ci，分别表示每个客户在方格图中的横坐标、纵坐标和订餐的量。（注意，可能有多个客户在方格图中的同一个位置）
　　接下来d行，每行两个整数，分别表示每个不能经过的点的横坐标和纵坐标。
输出格式
　　输出一个整数，表示最优送餐方式下所需要花费的成本。

  这个题，猛地一看真的感觉很难的样子，应该是能用BFS或者DFS的，或者还有什么深奥的算法？然后就搜了一下题解，感觉巨简单，真的巨简单。主要思路
  就是BFS，具体怎么BFS呢，就是在输入时将所有的卖家入队，之后开始BFS，从第一个卖家开始进行一下广搜，把周围点入队，然后从第二个卖家再开始，
  然后第三个第四个……感觉巧妙之处就是在于这样相当于每个卖家的点以几乎相等的速度向外扩张，谁先碰到顾客的点，就给顾客送餐。想想确实是BFS啊，
  还是大神厉害，化简为繁，要是考试的时候我绝逼是想不出来的，就算是有思路也不敢写，其实写起来代码非常简单。只有一点稍微动一下下脑子就是用在
  结构体里用一个value变量记录经过的路程长短，之后和顾客的需求相乘就可以得到最后的答案了。闲话少说，上代码
*/
#include<stdio.h>
#include<string>
#include<iostream>  
#include<queue>  
#define N 1001  
using namespace std;  
typedef struct Node {  
    char type;//点的类型 ,1是店家，2是顾客，0是普通点，-1是不能走的点  
    int x,y;//点的坐标  
    int needs;//记录顾客需要的快餐的数量  
    int value;  //记录经过的路程长短
} Node;  
//用来统一改变x,y的坐标   
char d_x[4]={-1,1,0,0};  
char d_y[4]={0,0,-1,1};  
queue<Node> q;  //用来存放结点的队列
Node arcs[N][N];  //用来存放结点的数组
bool vis[N][N];  //用来表示该点走没走过
int n;  //方格图的大小n*n
  
bool isTure(int x,int y){  //判断某点是否合法
    if(x>n || y>n || x<1 || y<1) return 0;  
    if(arcs[x][y].type==-1) return 0;  
    if(vis[x][y]) return 0;  //true或1走过
    return 1;  
}  
  
int main() {  
    int m=0,k=0,d=0;  //初始化分店数量，客户数量，不能走的点为0
	//__int64 ans=0;
    //long long int ans=0; 
	long int ans=0;//花费
    cin>>n;  
    cin>>m>>k>>d;  //依次输入nmkd
    //输入m个分店  
    while(m--) {  //m=0跳出while
        int x,y;  
        cin>>x>>y;  
        arcs[x][y].x=x;  
        arcs[x][y].y=y;  
        arcs[x][y].type=1;  //存放分店信息
        q.push(arcs[x][y]);  //将分店位置的信息放入队列
        vis[x][y]=1;  //该点已经走过
    }  
    //k个客户  
    while(k--) {  
        int x,y,needs;  
        cin>>x>>y>>needs;  
        arcs[x][y].x=x;  
        arcs[x][y].y=y;  
        arcs[x][y].type=2;  
        //这里注意要+=因为顾客坐标可能重复   
        arcs[x][y].needs+=needs;  
    }  
    //d个不能走的地方  
    while(d--) {  
        int x,y;  
        cin>>x>>y;  
        arcs[x][y].x=x;  
        arcs[x][y].y=y;  
        arcs[x][y].type=-1;  
    }  
    //将空格点赋值x,y（很耗时的感觉）   
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=n;j++)  
            if(arcs[i][j].type==0){  
                arcs[i][j].x=i;  
                arcs[i][j].y=j;  
            }  
      
    //从每个店开始BFS，碰到顾客就卸货，反正是每个店的范围同步增长  
    while(!q.empty()){  //当队列为空跳出循环，q初始值里面有分店
        Node temp;  
        temp=q.front();  //temp为当前店的信息
        q.pop();  //删除队列里的当前分店
        //i为0,1,2,3时分别表示该点的上下左右坐标   
        for(int i=0;i<4;i++){ //上下左右 
            int tp_x=temp.x+d_x[i],tp_y=temp.y+d_y[i];  //记录上下左右的坐标
            if(!isTure(tp_x,tp_y)) continue;  //该点不能走，继续下一个（上下左右），广度优先
            //value的值就是用来记录从卖家开始走了多少步   
            arcs[tp_x][tp_y].value=arcs[temp.x][temp.y].value+1; 

            //遇到顾客就将顾客的需求和走的步数相乘  
            if(arcs[tp_x][tp_y].type==2)   {
                ans+=arcs[tp_x][tp_y].needs*arcs[tp_x][tp_y].value;
				cout<<"x:"<<temp.x<<"   y:"<<temp.y<<"\n";
			}
            q.push(arcs[tp_x][tp_y]);  //q存放从分店出发可以走的上下左右的位置
            vis[tp_x][tp_y]=1; //表示该点已经走过

        }  //for循环结束
    }   //while循环结束
    cout<<ans;  
    return 0;  
}  