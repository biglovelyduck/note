//�����޲ι��캯���ʹ���Ĭ�ϲ����Ĺ��캯�� 
#include <iostream>
using namespace std;
class X{
	friend operator>>(ostream&,X&);
public:
	X(int sz=1024){
		ptr=new char[1024];
		cout<<"���ô���Ĭ�ϲ����Ĺ��캯��"<<endl;
	}
//	X(){
//		cout<<"�����޲ι��캯��"<<endl; 
//	}
private:
	char* ptr;
	
};
X buf;	//����˵������ 
int main(){
	return 0;
}
