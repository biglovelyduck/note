#include <stdio.h>
#include <stdlib.h>   
#define MAXSIZE 20   
#define ERROR -1   
#define OK   1   
#define FALSE 0   
#define TRUE  1   
typedef enum{
	RIGHT,DOWN,LEFT,UP
}Direction;  
typedef enum{
	YES,NO
}MarkTag;  
typedef struct position   //迷宫中位置的坐标   
{  int x;  
   int y;  
}Position;  
typedef struct  
{  int order;          //当前位置在路径中的序号   
  Position seat;       //当前位置在迷宫中的坐标   
  Direction di;       //从当前位置走到下一位置的方向   
}SElemType;              //栈元素的类型   
typedef struct          
{   
SElemType *elem;  
  int top;  
}Stack;               //声明栈结构体
char maze[MAXSIZE][MAXSIZE]={  
 {'1','1','1','1','1','1','1','1','1','1','1'},  
 {'1','0','1','0','0','1','1','1','0','0','1'},  
 {'1','0','0','0','0','0','1','0','0','1','1'},  
 {'1','0','1','1','1','0','0','0','1','1','1'},  
 {'1','0','0','0','1','0','1','1','0','1','1'},  
 {'1','1','0','0','1','0','1','1','0','0','1'},  
 {'1','1','1','0','0','0','0','0','0','0','1'},  
 {'1','1','1','1','1','1','1','1','1','1','1'}  
 };    //用二维字符数组表示迷宫   
int InitStack(Stack *S)             //创建一个空栈   
{  
S->elem=(SElemType*)malloc(MAXSIZE*MAXSIZE*sizeof(SElemType));  
 if(!S->elem)  return ERROR;  
 S->top=0;    return OK;  
}    
int Push(Stack *S,SElemType e)     //元素e入栈   
{   if(S->top>=MAXSIZE*MAXSIZE)   return ERROR;  
S->elem[S->top++]=e;
return OK;     //指针==数组
}   
int Pop(Stack *S,SElemType *e) //栈顶元素出栈，由e带回栈顶元素   
{   if(S->top<=0)     return ERROR;  
  *e=S->elem[--S->top];   return OK;  
}  
 int Empty(Stack S)    //判断栈是否为空   
{  if(S.top==0)    return TRUE;  
   else   return FALSE;  
}   
int createMaze(Position *startpos,Position *endpos)  
{ Position start,end;  
 printf("请输入迷宫入口的位置：");  
 scanf("%d%d",&start.x,&start.y);  
printf("请输入迷宫出口的位置：");  
 scanf("%d%d",&end.x,&end.y);  
     *startpos=start; *endpos=end;  
 return OK;  
}  //createMze   
int canPass(Position curpos)  
{    if(maze[curpos.x][curpos.y]=='0')   return TRUE;  
     return FALSE;  
}   //canPass   
void markPos(Position curpos,MarkTag tag)     //为已经探索过的位置加标记   
{  switch(tag)  
 {  case YES: maze[curpos.x][curpos.y]='.'; break;   //路径标记   
  case NO:  maze[curpos.x][curpos.y]='#'; break;   //死胡同标记   
 }  
}    
//根据当前的位置坐标和下一步要探索的方向dir求下一步要走的位置坐标   
Position nextPos(Position curpos,Direction dir)  
{    Position nextpos;  
switch(dir)  
  {  case RIGHT:nextpos.x=curpos.x ;nextpos.y =curpos.y +1; break;  
     case DOWN :nextpos.x=curpos.x+1 ;nextpos.y =curpos.y; break;  
     case LEFT :nextpos.x=curpos.x ;nextpos.y =curpos.y -1; break;  
     case UP :nextpos.x=curpos.x-1 ;nextpos.y =curpos.y;  break;  
  }  
  return nextpos;  
}  
Direction nextDir(Direction dir)  //?
{  switch(dir)  
  {   case RIGHT: return DOWN;  
      case DOWN : return LEFT;  
      case LEFT: return UP;  
  }  
}  
int Solve(Stack *S,Position start,Position end)  
{//若迷宫中存在从入口start到出口end的通道，则求得一条存放在栈S中，并返回TRUE,若迷宫中不存在从入口start到出口end的通道，并返回FALSE   
 Position curpos;  
 SElemType e;  
 int curstep=1;   //共用的步数   
if(InitStack(S)==ERROR)  return FALSE;  
 curpos=start;  
do{  
 if(canPass(curpos)){      //当前位置可以通过   
     markPos(curpos,YES);   //留下足迹   
     e.order=curstep;e.seat=curpos;e.di=RIGHT;  //先从右试探
     Push(S,e);             //当前位置可以走就将其加入路径   
     if(curpos.x==end.x&&curpos.y==end.y)   //当前位置是出口   
      return TRUE;  
     curpos=nextPos(curpos,RIGHT);  
     curstep++;  
  }  
  else{              //当前位置不能通过   
if(!Empty(*S)){  
 if(Pop(S,&e)==ERROR)   return FALSE;  
     while(e.di==UP&&!Empty(*S)){  
     //四个方向都试探过，没有找到通路也不能继续探索，则回溯   
      curpos=e.seat;markPos(curpos,NO);  
      if(Pop(S,&e)==ERROR)  return FALSE;  
}  
    if(e.di!=UP){   //四个方向还没有试探完   
      e.di=nextDir(e.di);  
      Push(S,e);  //换下一个方向探索   
      curpos=nextPos(e.seat,e.di);  
}  
}  
  }  
 }while(!Empty(*S));  //栈不为空
 return FALSE;  
}  
void main()  
{  Position startPos,endPos;  
   Stack path;  
 int i,j;  
SElemType e;  
if(createMaze(&startPos,&endPos)==ERROR) return ;  
 Solve(&path,startPos,endPos);  
while(!Empty(path)){    //输出出口到入口的路径   
  Pop(&path,&e);  
  printf("(%d,%d)",e.seat.x,e.seat.y);  
 }  
//输出迷宫的图形   
 printf("\n");  
    for(i=0;i<8;i++)  
{for(j=0;j<11;j++)  
   printf("%c ",maze[i][j]);  
  printf("\n");  
 }  
}
