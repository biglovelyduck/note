#include <iostream>
#include <cstdio>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	//int* p=(int *)malloc(sizeof(int)*5);
//	int* p1=p;
//	for(int i=0;i<3;i++)
//	    scanf("%d",p1++); 
//	cout<<*(p1-1); 
//	free(p);
	char* s;
	scanf("%s",s);
	cout<<*s;
	return 0;
}
