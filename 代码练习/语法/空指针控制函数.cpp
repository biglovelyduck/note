#include <iostream>
using namespace std; 

class Demo {
public:
    Demo():count(0) {}
      ~Demo() {}
  
      void say(const std::string&msg) {
      	//cout<<count<<endl; 
      	//初始化为NULL的类指针，可以安全的调用不涉及类成员变量的类成员函数而不会出错。
      	//stderr标准错误输出流，这个流的输出是无缓冲的输出
      	//C++ 的静态绑定，编译完成后成员函数就已经存在。
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
