#include <iostream>
#include <algorithm>
#include <cstdio>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

/*void print_permutation(int n,int* A,int cur){
	if(cur==n){
		for(int i=0;i<n;i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	else {
		for(int i=1;i<=n;i++){//������A�����������i  
		int ok=1;
		for(int j=0;j<cur;j++){
			if(A[j]==i) ok=0;
		}
		if(ok){
			A[cur]=i;
			print_permutation(n,A,cur+1);
		}
		}
	} 
} */
//���ɿ����ظ���ȫ���� 
/*void print_permutation(int n,int* A,int cur,int* P){
	if(cur==n){
		for(int i=0;i<n;i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	else {
		for(int i=0;i<n;i++){ 
		int c1,c2=0;
		for(int j=0;j<cur;j++) if(A[j]==P[i]) c1++;//ͳ����A��P[i]���ֵĴ��� 
		for(int j=0;j<n;j++) if(P[i]==P[j]) c2++;//P��P[i]���ֵĴ���c2
		if(c1<c2){
			A[cur]=P[i];
			print_permutation(n,A,cur+1,P);
		} 
		}
	} 
} */

/* 
int main(int argc, char** argv) {
	//int P[4]={1,1,2,3};
	int A[4];
	print_permutation(4,A,0,P);
	return 0;
}*/

//��һ������
int main(){
int n,p[10];
scanf("%d",&n);
for(int i=0;i<n;i++) scanf("%d",&p[i]);
sort(p,p+n);
do{
	for(int i=0;i<n;i++) cout<<p[i]<<" ";
	cout<<endl;
} while(next_permutation(p,p+n));
return 0;
}
