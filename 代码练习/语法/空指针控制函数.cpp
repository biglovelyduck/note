#include <iostream>
using namespace std; 

class Demo {
public:
    Demo():count(0) {}
      ~Demo() {}
  
      void say(const std::string&msg) {
      	//cout<<count<<endl; 
      	//��ʼ��ΪNULL����ָ�룬���԰�ȫ�ĵ��ò��漰���Ա���������Ա�������������
      	//stderr��׼������������������������޻�������
      	//C++ �ľ�̬�󶨣�������ɺ��Ա�������Ѿ����ڡ�
      		cout<<count<<endl;
          fprintf(stderr,"%s\n", msg.c_str());
      }   
   private:
      int count;
};
  
int main(int argc, char **argv) {
//    Demo* v = NULL;
//    v->say("hello world");
    Demo v1;
    v1.say("nimasl");
}
