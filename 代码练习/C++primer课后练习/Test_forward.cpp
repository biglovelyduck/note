#include <iostream>
using namespace std;
template<typename T>
void print(T& t){
    cout << "lvalue" << endl;
}
template<typename T>
void print(T&& t){
    cout << "rvalue" << endl;
}
 
template<typename T>
void TestForward(T && v){//实参是右值，形参还会变成左值 
    print(v);
    print(std::forward<T>(v));
    print(std::move(v));
}
 
int main(){
    TestForward(1);
    int x = 1;
    //TestForward(x);//参数是左值 
    //TestForward(std::forward<int>(x));//完美转发 
    return 0;
}
 
