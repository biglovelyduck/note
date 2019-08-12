typedef int StackDataType;//定义栈的数据类型为整数
//节点包括下一个节点的地址与数据
typedef struct stackNode{//stackNode可写可不写
    StackDataType data; //该节点的数据
    struct stackNode *next;//next为下一个节点的地址
}stackNode;

typedef struct stack{//栈开始只有一个头节点,栈的成员就是节点
    stackNode *top;
}LinkStack;


void initStack(LinkStack *s);
bool stackEmpty(LinkStack &s);
void getTop(LinkStack *s,StackDataType e);
void push(LinkStack *s,StackDataType e);
void pop(LinkStack *s,StackDataType e);
void stackPrint(LinkStack &s);
int menu_Select();
