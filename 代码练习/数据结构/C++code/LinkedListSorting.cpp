#include <cstdio>
#include <algorithm>
using namespace std;

const int max=100005;

struct Node{
	int address,data,next;
	bool flag;
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag==false||b.flag==false){
		return a.flag>b.flag;//只要a，b有一个是无效结点就把他放到后面 ,a为true，cmp返回true，只要返回true就从小到大排序 
	}
	else{
		return a.data<b.data;//从小到大排序 
	}
}

int main(){
	for(int i=0;i<maxn;i++){//初始化 
		node[i].flag=false;
	}
	int n,begin,address;
	scanf("%d%d",&n,&begin);
	for(int i=0;i<n;i++){
		scanf("%d",&address);//结点的地址 
		scanf("%d%d",&node[address].data,&node[address].next);//可能输入了无效结点，即前后结点不匹配 
		node[address].address=address;
	}
	int count=0,p=begin;//p为初始地址
	//枚举链表，对flag进行标记，同时计数有效节点个数
	while(p!=-1){
		node[p].flag=true;
		count++;
		p=node[p].next;
	} 
	if(count==0){
		printf("0 -1");//特判 
	}
	else{
		//筛选有效结点,并且按照data从大到小排序
		sort(node,node+maxn,cmp);
		//输出结果
		//防止-1倍%05化，提前判断
		printf("%d %05d\n",count,node[0].address);
		for(int i=0;i<count;i++){
			if(i!=count-1){
				printf()
			}
			else{
				
			}
		} 
	} 
	return 0;
} 
