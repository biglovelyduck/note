/*����һ�����󣬶�����ͨ�������������ڣ�����ֵ��ͬ��
���������һ�ŵ�ͼ����ͬ������Ϳ�Բ�ͬ��ɫ��
���룺
����N, (N<50)��ʾ�����������
������N�У�ÿ��N���ַ����������е�Ԫ��
������һ������M��(M<1000)��ʾѯ����
������M�У�ÿ�д���һ��ѯ�ʣ�
��ʽΪ4��������y1,x1,y2,x2��
��ʾ(��y1��,��x1��) �� (��y2��,��x2��) �Ƿ���ͨ��
��ͨ���true������false

���磺
10
0010000000
0011100000
0000111110
0001100010
1111010010
0000010010
0000010011
0111111000
0000010000
0000000000
3
0 0 9 9
0 2 6 8
4 4 4 6

����Ӧ�������
false
true
true*/ 
#include <iostream>
#include <string>
#include <cstring>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

bool lian_tong(char data[][100],int y1,int x1,int y2,int x2){
	if(y1==y2&&x1==x2) return true;
	char old=data[y1][x1];
	data[y1][x1]='*';//��ǲȹ�
	//dfs
	if(y1>0&&old==data[y1-1][x1]&&lian_tong(data,y1-1,x1,y2,x2)) return true; 
	if(y1<sizeof(data)/sizeof(data[0])&&old==data[y1+1][x1]&&lian_tong(data,y1+1,x1,y2,x2)) return true;//sizeof(data)/sizeof(data[0]):��ȡ���� 
	if(x1>0&&old==data[y1][x1-1]&&lian_tong(data,y1,x1-1,y2,x2)) return true; 
	if(x1<sizeof(data[0])/sizeof(data[0][0])&&old==data[y1][x1+1]&&lian_tong(data,y1,x1+1,y2,x2)) return true;
	data[y1][x1]=old;
	return false; 
}

int main(int argc, char** argv) {
	int m,n;
	cin>>n;
	string s[n];
	char **data=new char*;
	for(int i=0;i<n;i++){
		cin>>s[i];
		strcpy(data[i],s[i].c_str());
	}
	cout<<"����:"<<sizeof(data)/sizeof(data[0])<<endl;
	cout<<"������"<<sizeof(data[0])/sizeof(data[0][0])<<endl;
//	for(int i=0;i<sizeof(data)/sizeof(data[0]);i++){
//		for(int j=0;i<sizeof(data[0])/sizeof(data[0][0]);i++){
//			cout<<data[i][j];
//		}
//		cout<<endl;
//	}
//	cin>>m;
//	getchar();
//	for(int i=0;i<m;i++){
//		string str;
//		getline(cin,str);
//		char st[7];
//		strcpy(st,str.c_str());
//		char *p,s[4];
//		int k=0;
//		p=strtok(st," ");
//		while(p!=NULL){
//			s[k++]=*p;
//			p=strtok(NULL," ");
//		}
//		int y1=s[0]-'0';
//		int x1=s[1]-'0';
//		int y2=s[2]-'0';
//		int x2=s[3]-'0';
//		//cout<<lian_tong(data,y1,x1,y2,x2)<<endl;
//		cout<<y1<<x1<<y2<<x2<<endl;
//       }
//        bool b=true;
//        cout<<b;//true��ӡ1 
	return 0;
}
