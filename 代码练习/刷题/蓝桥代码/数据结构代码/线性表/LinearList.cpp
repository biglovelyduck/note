#include<stdlib.h> //���ٿռ��ͷ�ļ�
#include<stdio.h>
/*���Ա�*/ 
struct TLink { 
 int data; 
 struct TLink * next; 
};/*end struct TLink*/ 
 
/*������Ԫ��*/ 
struct TLink * new_item(int number) //����һ��ָ�������ڴ��ָ��r
{ 
 struct TLink * r = 0; 
 r = (struct TLink *)malloc(sizeof(struct TLink)); //����һ��ָ�������ڴ��ָ�룬rp = (JL **)malloc(15 * sizeof(JL *));˵��pָ��һ����15���ṹ��ָ�빹�ɵ�ָ�����飻
 r->data = number;  
 r->next = 0; 
 return r; 
}/*end new_item*/ 
 
/*�����Ա��в�ѯ����*/ 
struct TLink * lookup(struct TLink * root, int number) //������(����Ҫ��ѯ������)
{ 
 struct TLink * h = root; //h��ָ���
 while(h) { //h��Ϊ��
  if (h->data == number) return h; 
  h = h->next ; 
 }/*end lookup*/ 
 return 0; 
} 
 
/*�����Ա������һ������*/ 
void append(struct TLink * * root, int number) //����:(ָ��ṹ�����͵�ָ�루ָ�����)
{ 
 struct TLink * r = 0, * n = 0; 
 if (!root) return ; //ָ�����ָ��root������
 
 /*����¼�ظ�Ԫ��*/ 
 if (lookup(*root, number)) return; 
 
 /*�����Ϊ�����½���*/ 
 r = *root; 
 if (!r) { //rΪ��
  *root = new_item(number); //*root ��ָ��
  return ; 
 }/*end if*/ 
 
 /*Ϊ��֤Ϊ�������Ա�������ݱȱ�ͷ��С����Ϊ��ͷ*/ 
 if (number < r->data ) { 
  n = new_item(number); 
  n->next = r; 
  *root = n; 
  return ; 
 }/*end if*/ 
 
 /*���������Ա��в���λ�ò���Ԫ��*/ 
 while(r) { 
  n = r->next ; //n��r����һ��ָ��
 
  /*����Ѿ��Ǳ�β��ֱ��׷��*/ 
  if (!n) { //n������
   n = new_item(number); 
   r->next = n; 
   return ; 
  }/*end if*/ 
 
  /*������ĳ������,n����*/ 
  if (number < n->data ) { 
   r->next = new_item(number); //r->nextΪָ��ǰ����λ�õ�ָ��
   r->next->next = n; 
   return ; 
  }/*end if*/ 
  r = n; 
 }/*end while*/ 
}/*end append*/ 
 
/*��ӡ�������Ա�*/ 
void print(struct TLink * root) 
{ 
 struct TLink * r = root; 
 printf("��"); 
 while(r) { //r����
  printf("%d ", r->data ); 
  r = r->next ; 
 }/*end while*/ 
 printf("\b��\n"); //  "\b":�����x�ĵ�ǰֵ��Ȼ���ٽ����������������Ǵ���ʱ==Backspace
}/*end print*/ 
 
/*���������Ա�h1�ϲ����������Ա�h0�����������Ա�h1*/ //�ص�!!!!!!!!!!!!!!!!!!!!!!
void merge(struct TLink ** h0, struct TLink ** h1) 
{ 
 struct TLink * h = 0, * k = 0; 
 if (!h0 || !h1) return ; //�����κ�һ�������ڶ�����
 h = *h1; 
 while(h) { //h����,hΪh1�ĸ�
  append(h0, h->data ); 
  k = h; 
  h = h->next ; 
  free(k); //����ԭ����h
 }/*end h*/ 
 h1 = 0; 
} 
 
int main(void) 
{ 
 int i = 0; struct TLink * x=0, *y = 0; 
 int a[]  = {2,5,4,6,8,9} ; 
 int b[]  = {5,8,9,6,3,8} ; 
 printf("ԭ����Ϊ��\n����A����"); 
 for(i = 0; i < 6; i++) { 
  printf("%d ", a[i]); 
  append(&x, a[i]); 
 }/*next*/ 
 printf("\b��\n����B����"); 
 for(i = 0; i < 6; i++) { 
  printf("%d ", b[i]); 
  append(&y, b[i]); 
 }/*next*/ 
 printf("\b��\nת��Ϊ�������Ա�\nA��"); 
 print(x); 
 printf("B��"); 
 print(y); 
 printf("AB�ϲ���Ϊ��"); 
 merge(&x, &y); 
 print(x); 
 return 0; 
}