#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//1.增量构造法:选出一个元素放到集合中
void print_subset1(int n,int* A,int cur){
	if(cur==0) cout<<"NULL";
	for(int i=0;i<cur;i++) 
	    cout<<A[i]+1<<" ";
	cout<<endl;
	int minEle=cur?A[cur-1]+1:0;//确定当前元素最小的额可能值,cur>0执行左边 
	for(int i=minEle;i<n;i++){
		A[cur]=i;//存放子集 
		print_subset1(n,A,cur+1);
	} 
} 
//2.位向量法:B[i]=1,当且仅当i在子集B中 
void print_subset2(int n,int* B,int cur){
	if(cur==n){
		for(int i=0;i<cur;i++)
			if(B[i]) cout<<i+1;//B[i]等于1,选中与没选中
			cout<<endl;
			return; 
	}
	B[cur]=1;//先假设B[i]在子集中 
	print_subset2(n,B,cur+1);
	B[cur]=0; //再假设B[i]不在子集中
	print_subset2(n,B,cur+1); 
} 
//3.二进制法
void print_subset3(int n,int s){
	for(int i=0;i<n;i++)//i是0,1,2 
	    if(s&(1<<i)) cout<<i+1;//s是0,1,2,3  1<<n是1,2,4 
	    cout<<endl;
}
int main(int argc, char** argv) {
	int A[3],B[3],n;
	cin>>n;
	//print_subset1(3,A,0);
	//print_subset2(3,B,0); 
	for(int i=0;i<(1<<n);i++)//(1<<n)==2^n
	    //cout<<i<<endl;
	    print_subset3(n,i);//i是0,1,2,3, 
	return 0;
}
