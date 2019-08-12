#include<stdlib.h> //开辟空间的头文件
#include<stdio.h>
/*线性表*/ 
struct TLink { 
 int data; 
 struct TLink * next; 
};/*end struct TLink*/ 
 
/*生成新元素*/ 
struct TLink * new_item(int number) //返回一个指向链表内存的指针r
{ 
 struct TLink * r = 0; 
 r = (struct TLink *)malloc(sizeof(struct TLink)); //创建一个指向链表内存的指针，rp = (JL **)malloc(15 * sizeof(JL *));说明p指向一个有15个结构体指针构成的指针数组；
 r->data = number;  
 r->next = 0; 
 return r; 
}/*end new_item*/ 
 
/*在线性表中查询数据*/ 
struct TLink * lookup(struct TLink * root, int number) //参数：(根，要查询的数据)
{ 
 struct TLink * h = root; //h先指向根
 while(h) { //h不为空
  if (h->data == number) return h; 
  h = h->next ; 
 }/*end lookup*/ 
 return 0; 
} 
 
/*在线性表中添加一个数据*/ 
void append(struct TLink * * root, int number) //参数:(指向结构体类型的指针（指向根）)
{ 
 struct TLink * r = 0, * n = 0; 
 if (!root) return ; //指向根的指针root不存在
 
 /*不记录重复元素*/ 
 if (lookup(*root, number)) return; 
 
 /*如果表为空则新建表*/ 
 r = *root; 
 if (!r) { //r为空
  *root = new_item(number); //*root 是指针
  return ; 
 }/*end if*/ 
 
 /*为保证为有序线性表，如果数据比表头还小则作为表头*/ 
 if (number < r->data ) { 
  n = new_item(number); 
  n->next = r; 
  *root = n; 
  return ; 
 }/*end if*/ 
 
 /*在有序线性表中查找位置插入元素*/ 
 while(r) { 
  n = r->next ; //n是r的下一个指针
 
  /*如果已经是表尾则直接追加*/ 
  if (!n) { //n不存在
   n = new_item(number); 
   r->next = n; 
   return ; 
  }/*end if*/ 
 
  /*在中央某处插入,n存在*/ 
  if (number < n->data ) { 
   r->next = new_item(number); //r->next为指向当前插入位置的指针
   r->next->next = n; 
   return ; 
  }/*end if*/ 
  r = n; 
 }/*end while*/ 
}/*end append*/ 
 
/*打印有序线性表*/ 
void print(struct TLink * root) 
{ 
 struct TLink * r = root; 
 printf("【"); 
 while(r) { //r存在
  printf("%d ", r->data ); 
  r = r->next ; 
 }/*end while*/ 
 printf("\b】\n"); //  "\b":先输出x的当前值，然后再将其消掉，就像我们打字时==Backspace
}/*end print*/ 
 
/*将有序线性表h1合并至有序线性表h0，并销毁线性表h1*/ //重点!!!!!!!!!!!!!!!!!!!!!!
void merge(struct TLink ** h0, struct TLink ** h1) 
{ 
 struct TLink * h = 0, * k = 0; 
 if (!h0 || !h1) return ; //其中任何一个不存在都返回
 h = *h1; 
 while(h) { //h存在,h为h1的根
  append(h0, h->data ); 
  k = h; 
  h = h->next ; 
  free(k); //销毁原来的h
 }/*end h*/ 
 h1 = 0; 
} 
 
int main(void) 
{ 
 int i = 0; struct TLink * x=0, *y = 0; 
 int a[]  = {2,5,4,6,8,9} ; 
 int b[]  = {5,8,9,6,3,8} ; 
 printf("原数据为：\n数组A：【"); 
 for(i = 0; i < 6; i++) { 
  printf("%d ", a[i]); 
  append(&x, a[i]); 
 }/*next*/ 
 printf("\b】\n数组B：【"); 
 for(i = 0; i < 6; i++) { 
  printf("%d ", b[i]); 
  append(&y, b[i]); 
 }/*next*/ 
 printf("\b】\n转换为有序线性表\nA："); 
 print(x); 
 printf("B："); 
 print(y); 
 printf("AB合并后为："); 
 merge(&x, &y); 
 print(x); 
 return 0; 
}