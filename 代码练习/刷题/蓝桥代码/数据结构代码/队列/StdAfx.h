#define MSIZE 30    

typedef struct{      //�Զ����������ͣ�Ŀ��һ����������һ���Ǹ�����һ���׼���������ȷ�������֣���һ���Ǽ�һЩ�Ƚϸ��ӵ����������� 
	int data[MSIZE];
	int front;
	int rear;
}Queue;  //���� 

void initQueue(Queue *Q);
void enQueue(Queue *Q,int e);
void deleteQueue(Queue *Q,int *e);
void queuePrint(Queue Q);
int menuSelect();