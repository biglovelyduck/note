#include <iostream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//�ַ�����ʼ��
void strInit(){
	cout<<"�ַ�����ʼ����"<<endl;
	
	string s1="abcdefg";//��ʼ����ʽ1 
	string s2("sbcdrfg");//��ʼ����ʽ2
	string s3=s2;//ͨ��������ʼ����ʽ3
	string s4(7,'s');//��ʼ��7��s���ַ���
	
	cout<<"s1="<<s1<<endl; 
	cout<<"s2="<<s2<<endl; 
	cout<<"s3="<<s3<<endl; 
	cout<<"s4="<<s4<<endl; 
} 

//�ַ�������
void strErgo(){
	cout<<"�ַ���������"<<endl;
	
	string s1="abcdefg";
	
	//���鷽ʽ����
	cout<<"1.ͨ�����鷽ʽ������"<<endl;
	for(int i=0;i<s1.length();i++){
		cout<<s1[i]<<" ";
	} 
	cout<<endl;
	
    //ͨ������������
	cout<<"2.ͨ��������������" <<endl;
	for(string::iterator it=s1.begin();it!=s1.end();it++){ 
		cout<<*it<<" "; 
	}
	cout<<endl;
	
	//ͨ��at()��ʽ����
	cout<<"3.ͨ��at()��ʽ������"<<endl;
	for(int i=0;i<s1.length();i++){
		cout<<s1.at(i)<<" ";
	}
	cout<<endl;
}

//�ַ�ָ����ַ�����ת��
void strConvert(){
	cout<<"�ַ�ָ����ַ�����ת��"<<endl;
	string s1="abcdefg";
	
	cout<<"stringת��Ϊchar*"<<endl;
	cout<<s1.c_str()<<endl; //const char *str = s1.c_str();   c_str()����һ��ָ���������ָ��
	
	cout<<"char*��ȡstring�����ݣ�"<<endl;
	char buf[64]={0};
	s1.copy(buf,7);
	cout<<buf<<endl;
} 

//�ַ�������
void strAdd(){
	cout<<"�ַ������ӣ�"<<endl;
	
	cout<<"��ʽ1��"<<endl;
	string s1="123";
	string s2="456";
	s1+=s2;
	cout<<"s1="<<s1<<endl;
	
	cout<<"��ʽ2��"<<endl;
	string s3="123";
	string s4="456";
	s3.append(s4);
	cout<<"s3="<<s3<<endl;
} 

int main(int argc, char** argv) {
	//��ʼ��  
    strInit();  
    cout << endl;  
    //����  
    strErgo();  
    cout << endl;  
    //�ַ�ָ�����ͺ��ַ���ת��  
    strConvert();  
    cout << endl;  
    //�ַ�������  
    strAdd();  
    cout << endl;  
    system("pause");  
    return 0;  
}
