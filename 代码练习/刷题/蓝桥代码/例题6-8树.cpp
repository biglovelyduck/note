/*����һ����������ͺ������Ҫ���ҵ�һ��Ҷ��ʹ��������Ȩֵ����С*/ 
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//��Ϊ��������Ȩֵ��ͬ��ֱ����Ȩֵ��Ϊ����� 
const int maxv=1000+10;//��������Ŀ
int in_order[maxv],//�洢�������������
	post_order[maxv],//�洢�������������
	lch[maxv],//l[root]�����洢root���������ĸ���ֵ
	rch[maxv];//r[root]�����洢root���������ĸ���ֵ
int n;//ȫ�ֱ�����������ʾ���ĸ���
	
//����������з��뵽a�� ,��ȡ�ɹ�����true 
bool read_list(int* a){
	string line;
	if(!getline(cin,line))	return false;//�����ȡʧ�� 
	stringstream ss(line);//�������line��ʱ�ŵ���stream�У�stringstream:ʵ������ת��
	n=0;
	int x;
	while(ss>>x)//��������(line)�ж�ȡ�������� 
	    a[n++]=x;
	return n>0; 
} 
	
//ͨ��in_order[L1..R1]��post_order[L2..R2]����һ�ö��������������� 
int build(int L1,int R1,int L2,int R2){
	if(L1>R1) return 0;//����
	int root=post_order[R2];
	int p=L1;//λ��	
	while(in_order[p]!=root) p++;//p����root��λ��
	int cnt=p-L1;//�������Ľ�����
	lch[root]=build(L1,p-1,L2,L2+cnt-1);//lch[root]�����root���������ĸ�
	rch[root]=build(p+1,R2,L2+cnt,R2-1);
	return root; 
}
	
int best,//�������Ž�
    best_sum;//���Ž��Ӧ��Ȩ��
	
//
void dfs(int u,int sum){//uΪ��,sumΪ��ǰλ�õĺ� 
	sum+=u;
	if(!lch[u]&&rch[u])	{//����������������Ϊ��
	    if(sum<best_sum||(sum==best_sum&&u<best)){
	    	best=u;
	    	best_sum=sum;
		}
    }
    if(lch[u]) dfs(lch[u],sum);//�������,�������ʼ����
	if(rch[u]) dfs(rch[u],sum); 
} 
	

int main(int argc, char** argv) {
	while(read_list(in_order)){
		read_list(post_order);
		build(0,n-1,0,n-1);//����������
		best_sum=10000000;
		dfs(post_order[n-1],0);
		cout<<best<<"\n"; 
	}
	return 0;
}
