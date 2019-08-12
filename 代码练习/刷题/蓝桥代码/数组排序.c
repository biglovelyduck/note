#include <stdio.h>
#include <stdlib.h>
#define N 10001
/*给定一个长度为n的数列，将这个数列按从小到大的顺序排列。1<=n<=200
输入格式
　　第一行为一个整数n。
　　第二行包含n个整数，为待排序的数，每个整数的绝对值小于10000。
输出格式
　　输出一行，按从小到大的顺序输出排序后的数列。
样例输入
5
8 3 6 4 9
样例输出
3 4 6 8 9*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	int a[N]; 
	int i,j,temp;
    scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
		if(a[j]>a[j+1]){
			temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
		}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
	return 0;
}
