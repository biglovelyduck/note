/*����һ���ݺ������Ϸ��
��ͼ1����3x4�ĸ����У���Ϸ��˫���������û�����
������ǣ�
1. ���ܷ������Ѿ������˻����ĵط�����ֻ���ڿո��з��ã���
2. �����ķ���ֻ������ֱ��ˮƽ���á�
3. �������������������еĻ����ͨ����
��ν��ͨ��ָ����������������һ��ֱ�ߣ����м�û��������ͬ����Ļ����������
���磺
ͼ1��ʾ�ľ����£�������C2λ����ֱ���ã�Ϊ�˷�����������λ�ã�ͼ�����¶�����˱�ǣ���������ˮƽ���ã���Ϊ����A2��ͨ��
ͬ������B2��B3��D2��ʱ���ַ��򶼲����Է��á�
�����C2��ֱ���ú�D2�Ϳ���ˮƽ�����ˣ���Ϊ���ٻ���A2��ͨ���ܵ���C2���赲����
4. ��Ϸ˫���������û�񣬲�������Ȩ��Ҳ�����ԷŶ����

��ĳһ���޷��������ã���÷�Ϊ�������һ������

��Ϸ��ʼʱ�����Ѿ������˶�����
��������ǣ���д���򣬶����ʼ״̬����������Լ��������ķ��÷�����������ú�ľ��档
ͼ1�ľ����ʾΪ��
00-1
-000
0100
���á�0����ʾ����λ�ã��á�1����ʾ��ֱ���ã��á�-����ʾˮƽ���á�

�ⷨ��Ψһ���ҵ�����ⷨ���ɡ�

���磬���棺
0111
-000
-000
�Ľ⣺
-111
-000
-000

�����磬���棺
1111
----
0010
�Ľ⣺
1111
----
0110

#include <iostream>
using namespace std;
void main()
{
//��new����һ����ά����,�����ַ���,�ǵȼ۵�
//һ:
int (*p)[10] = new int[5][10];
//��:
int **p = new int* [5];
for(int i=0;i <5;i++)
p[i] = new int[10];
//ָ������Ĵ���,Ҳ�����ַ���
//һ:
char **pa = new char* [4];
for (int i=0;i <4;i++)
{
pa[i] = new char[8]; //Ϊÿ��ָ�붼����8��charԪ�ؿռ䡣
}
//��:
char *pa[4];//���Բ���new����
for (int i=0;i <4;i++)
{
pa[i] = new char[8]; //Ϊÿ��ָ�붼����8��charԪ�ؿռ䡣
}
//delete��ά����
//forһ:
delete []p;
//for��:
for(int i=0; i <5; ++i)
delete []p[i];
delete []p;
//deleteָ������
//forһ:
for(int i=0; i <4; ++i)
delete []pa[i];
delete []pa;
//for��:
for(int i=0; i <4; ++i)
delete []pa[i];
}


*/

#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

string trim(char* s){
	char *str1;
	char *str2=s;
	while(*str2!='\0'){
		if(*str2!=' '){
			*str1=*str2;
			str1++;
			str2++;
			cout<<*str2<<endl; 
		}
		else{
			str2++;
		}
	}
	return string(str1);
}

int main(int argc, char** argv) {
//	char (*data)[10]=new char[3][10];  ��ȷ

//    char **data=new char* [3] ;//����
//	for(int i=0;i<3;i++){
//		data[i]=new char[10];
//	} 

//    char data[3][10];

//    cin.get(data[0],10);
//    cin.getline(data[0],10); 
    //cout<<trim(data[0])<<endl;
    
    char (*data)[10]=new char[3][10];
    //gets(data[0]);
//    gets(data[1]);
//    gets(data[2]);
   // cout<<trim(data[0])<<endl;


    char s[20]="fang xi kai";//ָ��s�ĵ�ַ���ɱ� 
//    char* p=s;//p����ַ����ĵ�ַ 
////    cin.get(s,10);
//    while(*p!='\0'){
//    	cout<<*p<<endl;
//    	p++;
//	
	char *str2=s;
	char *str1=s;
	cout<<"str1="<<str1<<endl;
	cout<<"str2="<<str2<<endl;
	cout<<"s="<<s<<endl; 
	cout<<endl;
	cout<<"&str1="<<&str1<<endl;
	cout<<"&str2="<<&str2<<endl;
	cout<<"&s="<<&s<<endl; 
	cout<<endl;

	while(*str2!='\0'){
		if(*str2!=' '){
			*str1=*str2;
			str1++;
			str2++;
			//cout<<*str2<<endl; 
		}
		else{
			str2++;
		}
	}
	*str1=*str2;
	cout<<"s="<<s<<endl;
	return 0;
}
