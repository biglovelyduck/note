typedef int StackDataType;//����ջ����������Ϊ����
//�ڵ������һ���ڵ�ĵ�ַ������
typedef struct stackNode{//stackNode��д�ɲ�д
    StackDataType data; //�ýڵ������
    struct stackNode *next;//nextΪ��һ���ڵ�ĵ�ַ
}stackNode;

typedef struct stack{//ջ��ʼֻ��һ��ͷ�ڵ�,ջ�ĳ�Ա���ǽڵ�
    stackNode *top;
}LinkStack;


void initStack(LinkStack *s);
bool stackEmpty(LinkStack &s);
void getTop(LinkStack *s,StackDataType e);
void push(LinkStack *s,StackDataType e);
void pop(LinkStack *s,StackDataType e);
void stackPrint(LinkStack &s);
int menu_Select();
