#include <cstdio>
#include <algorithm>
using namespace std;

const int max=100005;

struct Node{
	int address,data,next;
	bool flag;
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag==false||b.flag==false){
		return a.flag>b.flag;//ֻҪa��b��һ������Ч���Ͱ����ŵ����� ,aΪtrue��cmp����true��ֻҪ����true�ʹ�С�������� 
	}
	else{
		return a.data<b.data;//��С�������� 
	}
}

int main(){
	for(int i=0;i<maxn;i++){//��ʼ�� 
		node[i].flag=false;
	}
	int n,begin,address;
	scanf("%d%d",&n,&begin);
	for(int i=0;i<n;i++){
		scanf("%d",&address);//���ĵ�ַ 
		scanf("%d%d",&node[address].data,&node[address].next);//������������Ч��㣬��ǰ���㲻ƥ�� 
		node[address].address=address;
	}
	int count=0,p=begin;//pΪ��ʼ��ַ
	//ö��������flag���б�ǣ�ͬʱ������Ч�ڵ����
	while(p!=-1){
		node[p].flag=true;
		count++;
		p=node[p].next;
	} 
	if(count==0){
		printf("0 -1");//���� 
	}
	else{
		//ɸѡ��Ч���,���Ұ���data�Ӵ�С����
		sort(node,node+maxn,cmp);
		//������
		//��ֹ-1��%05������ǰ�ж�
		printf("%d %05d\n",count,node[0].address);
		for(int i=0;i<count;i++){
			if(i!=count-1){
				printf()
			}
			else{
				
			}
		} 
	} 
	return 0;
} 
