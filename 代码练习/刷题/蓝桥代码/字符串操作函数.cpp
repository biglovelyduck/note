#include <iostream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	string s1="hello";
	string s2;
	s2.assign(s1,0,3);//���ڸ�����ֵ��assign�������ڽ�һ���ַ����Ĳ������ݸ�ֵ����һ��string,����s2��ֵΪ��hel��
	
	swap(s1,s2);////���������ַ���������,swap������s1��s2�����ݽ���������s1="hel",s2="hello" 
	
	//+=��append()��push_back()//���ַ���β��׷������,"+="��׷��string�����ַ��Լ�C����ַ�����append���������׷��string�����C����ַ�����push_back������ֻ��׷���ַ�
	s1+=s2;
	s1+="world";
	s1+='c';
	
	s1.append(s2);
	s1.append(" world");
	s1.push_back('c');
	
	//insert()//���ڲ����ַ���
	string s3="world";
	s3.insert(0,"hello ");
	s3.insert(6,"haha ");
	cout<<"s3="<<s3<<endl; 
	
	//erase()//����ɾ��ָ��λ�õ��ַ�
	s3.erase(6,5);
	cout<<"s3="<<s3<<endl; //ɾ����6λ�ÿ�ʼ��5���ַ�
	//������ɾ����������λ��
	string::iterator it=s3.begin()+1;
	s3.erase(it); //ɾ��������λ��Ϊ1���ַ� 
	cout<<"s3="<<s3<<endl; 
	s3.erase(s3.begin(),s3.begin()+4);//ɾ��֮��������ַ� 
	cout<<"s3="<<s3<<endl<<endl; 
	
	//clear()������~string()//��������ɾ��ȫ���ַ���
	s3.clear();
	s3.insert(0,"c");//��ʱs3Ϊһ���մ� 
	cout<<"s3="<<s3<<endl;
	//s3.~string();//���������ַ����ͷ��ڴ棬������������� 
	//cout<<"s3="<<s3<<endl;
	
	// ==����=��<��<=��>��>=��compare()//�Ƚ��ַ���
	if(s1.compare(s2) == 0)
          cout << "���" << endl;  
    else  cout << "�����" << endl;
    
    //data()���������������ַ��������ʽ����
	const char *a=s3.data();// const char *data();data()��������ָ���Լ��ĵ�һ���ַ���ָ��.
	cout<<"a="<<a<<endl; 
	
  /*size()������length()�����������ַ������ַ���
 eg.string str = "haha";
    str.size() ���� str.length(),ֵ��Ϊ4
 
    empty()//�ж��ַ����Ƿ�Ϊ��
 */
	return 0;
}
