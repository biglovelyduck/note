#define MSIZE 30    

typedef struct{      //自定义数据类型，目的一般有两个，一个是给变量一个易记且意义明确的新名字，另一个是简化一些比较复杂的类型声明。 
	int data[MSIZE];
	int front;
	int rear;
}Queue;  //队列 

void initQueue(Queue *Q);
void enQueue(Queue *Q,int e);
void deleteQueue(Queue *Q,int *e);
void queuePrint(Queue Q);
int menuSelect();