#include <iostream>
#include <cstdio>
using namespace std;
int get(int *p,int i,int j){
	//return p[i*4+j];
	return *(p+i*4+j);
} 
int main(){
	int a[3][4]={{1,2,3,4},{1,2,3,4},{1,2,3,100}};
	printf("%d\n",get(&a[0][0],2,3));
	//二维数组的动态声明
	int **a=new int* [5];
	for(int i=0;i<5;i++){
		a[i]=new int[4];
	}
	//使用后释放内存
	for(int i=0;i<5;i++){
		delete []a[i];
	} 
	delete []a;
	
	int d[10];
	int (*p)[10]=&d;
	int *q=d;
	
	int w[3][4];
	int (*pw)[4]=w;
	
	return 0;
}
