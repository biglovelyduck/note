/*堆的实现*/ 
//左儿子编号：自己编号*2+1  右儿子编号：自己编号*2+2 
int heap[MAX_N],sz=0;//大小 
void push(int x){
	int i=sz++;//自己结点的编号
	while(i>0){
		//父亲结点编号
		int p=(i-1)/2;
		//如果已经没有大小颠倒，则退出
		if(heap[p]<=x) break;
		//和父亲结点有大小颠倒
		heap[i]=heap[p];
		i=p; 
	} 
	heap[i]=x;
} 
int pop(){
	//最小值
	int ret=heap[0];
	//要提到根的数值
	int x=heap[--sz]; 
	//从根开始向下交换
	int i=0;
	while(i*2+1<sz){
		//比较儿子的值
		int a=i*2+1,b=i*2+2;
		if(b<sz&&heap[b]<heap[a]) a=b;//a保存较小儿子的下标 
		//如果已经没有大小颠倒就退出
		if(heap[a]>=x) break;
		//把儿子的数值提上来
		heap[i]=heap[a]; 
		i=a;//继续向下走 
	}
	heap[i]=x;
	return ret; 
}

//堆即优先队列的实现，stl的priority_queue就是，取出数值得到最大值 
