/*输入一棵树的中序和后序遍历要求找到一个叶子使它到根的权值和最小*/ 
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//因为各个结点的权值不同，直接用权值作为结点编号 
const int maxv=1000+10;//结点最大数目
int in_order[maxv],//存储中序遍历的数字
	post_order[maxv],//存储后序遍历的数字
	lch[maxv],//l[root]用来存储root的左子树的根的值
	rch[maxv];//r[root]用来存储root的右子树的根的值
int n;//全局变量，用来表示结点的个数
	
//将输入的序列放入到a中 ,读取成功返回true 
bool read_list(int* a){
	string line;
	if(!getline(cin,line))	return false;//输入读取失败 
	stringstream ss(line);//将输入的line暂时放到流stream中，stringstream:实现类型转换
	n=0;
	int x;
	while(ss>>x)//挨个从流(line)中读取单个整数 
	    a[n++]=x;
	return n>0; 
} 
	
//通过in_order[L1..R1]和post_order[L2..R2]建立一棵二叉树，返回树根 
int build(int L1,int R1,int L2,int R2){
	if(L1>R1) return 0;//空树
	int root=post_order[R2];
	int p=L1;//位置	
	while(in_order[p]!=root) p++;//p返回root的位置
	int cnt=p-L1;//左子树的结点个数
	lch[root]=build(L1,p-1,L2,L2+cnt-1);//lch[root]存的是root的左子树的根
	rch[root]=build(p+1,R2,L2+cnt,R2-1);
	return root; 
}
	
int best,//保存最优解
    best_sum;//最优解对应的权和
	
//
void dfs(int u,int sum){//u为根,sum为当前位置的和 
	sum+=u;
	if(!lch[u]&&rch[u])	{//根的左右子树都不为空
	    if(sum<best_sum||(sum==best_sum&&u<best)){
	    	best=u;
	    	best_sum=sum;
		}
    }
    if(lch[u]) dfs(lch[u],sum);//左根存在,从左根开始遍历
	if(rch[u]) dfs(rch[u],sum); 
} 
	

int main(int argc, char** argv) {
	while(read_list(in_order)){
		read_list(post_order);
		build(0,n-1,0,n-1);//建立二叉树
		best_sum=10000000;
		dfs(post_order[n-1],0);
		cout<<best<<"\n"; 
	}
	return 0;
}
