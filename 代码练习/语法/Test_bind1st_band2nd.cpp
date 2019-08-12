#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
 
 
/**  
* std::bind1st  std::bind2nd 就是将一个二元函数的一个参数设置为定值，这样二元函数就转换为了一元函数
* 因为有些算法的参数要求必须是一元函数，但是我们又想用二元函数，那么就可以使用这两个函数
*/
/**
*@brief std::less 仿函数的内部实现
    template <class T> struct less : binary_function <T,T,bool> {
        bool operator() (const T& x, const T& y) const {return x<y;}
    };
*/
 
struct person{
    int age;
    std::string name;
};
 
struct person_filter_func: public std::binary_function<person,std::string,bool>
{
    bool operator()(const person& p,const std::string& key) const{
        return (p.name.find(key) != std::string::npos); 
    }
};
 
void disp(int val){    std::cout<<val<<" "; }
void disp_v(const person& p){    std::cout<<p.age<<","<<p.name<<" "; }
 
int main()
{
    //使用 std::less 仿函数
    int arr[] = {1,2,3,4,5,6,7,8,9};
    std::vector<int> vec;
    std::copy_if(std::begin(arr),std::end(arr),std::back_inserter(vec),std::bind1st(std::less<int>(),6)); //将6 绑定为第一个参数，即 6 < value
    std::for_each(vec.begin(),vec.end(),disp);  // 7 8 9
 
    vec.clear();
    std::copy_if(std::begin(arr),std::end(arr),std::back_inserter(vec),std::bind2nd(std::less<int>(),6)); //将6 绑定为第二个参数，即 value < 6
    std::for_each(vec.begin(),vec.end(),disp); //1 2 3 4 5
 
 
    //使用自定义的仿函数
    std::vector<person> vecP;
    person p1 = {1,"jack"}; vecP.push_back(p1);
    person p2 = {2,"rose"}; vecP.push_back(p2);
    person p3 = {3,"jane"}; vecP.push_back(p3);
 
    std::vector<person> vecRet;
    std::copy_if(vecP.begin(),vecP.end(),std::back_inserter(vecRet),std::bind2nd(person_filter_func(),"ja"));  //将包含关键字"ja"的person，复制到vecRet容器中
    std::for_each(vecRet.begin(),vecRet.end(),disp_v);//1, jack  3, jane
}
