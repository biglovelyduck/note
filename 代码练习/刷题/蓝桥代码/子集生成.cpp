#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//1.�������취:ѡ��һ��Ԫ�طŵ�������
void print_subset1(int n,int* A,int cur){
	if(cur==0) cout<<"NULL";
	for(int i=0;i<cur;i++) 
	    cout<<A[i]+1<<" ";
	cout<<endl;
	int minEle=cur?A[cur-1]+1:0;//ȷ����ǰԪ����С�Ķ����ֵ,cur>0ִ����� 
	for(int i=minEle;i<n;i++){
		A[cur]=i;//����Ӽ� 
		print_subset1(n,A,cur+1);
	} 
} 
//2.λ������:B[i]=1,���ҽ���i���Ӽ�B�� 
void print_subset2(int n,int* B,int cur){
	if(cur==n){
		for(int i=0;i<cur;i++)
			if(B[i]) cout<<i+1;//B[i]����1,ѡ����ûѡ��
			cout<<endl;
			return; 
	}
	B[cur]=1;//�ȼ���B[i]���Ӽ��� 
	print_subset2(n,B,cur+1);
	B[cur]=0; //�ټ���B[i]�����Ӽ���
	print_subset2(n,B,cur+1); 
} 
//3.�����Ʒ�
void print_subset3(int n,int s){
	for(int i=0;i<n;i++)//i��0,1,2 
	    if(s&(1<<i)) cout<<i+1;//s��0,1,2,3  1<<n��1,2,4 
	    cout<<endl;
}
int main(int argc, char** argv) {
	int A[3],B[3],n;
	cin>>n;
	//print_subset1(3,A,0);
	//print_subset2(3,B,0); 
	for(int i=0;i<(1<<n);i++)//(1<<n)==2^n
	    //cout<<i<<endl;
	    print_subset3(n,i);//i��0,1,2,3, 
	return 0;
}
