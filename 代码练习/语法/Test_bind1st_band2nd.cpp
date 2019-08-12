#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
 
 
/**  
* std::bind1st  std::bind2nd ���ǽ�һ����Ԫ������һ����������Ϊ��ֵ��������Ԫ������ת��Ϊ��һԪ����
* ��Ϊ��Щ�㷨�Ĳ���Ҫ�������һԪ�������������������ö�Ԫ��������ô�Ϳ���ʹ������������
*/
/**
*@brief std::less �º������ڲ�ʵ��
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
    //ʹ�� std::less �º���
    int arr[] = {1,2,3,4,5,6,7,8,9};
    std::vector<int> vec;
    std::copy_if(std::begin(arr),std::end(arr),std::back_inserter(vec),std::bind1st(std::less<int>(),6)); //��6 ��Ϊ��һ���������� 6 < value
    std::for_each(vec.begin(),vec.end(),disp);  // 7 8 9
 
    vec.clear();
    std::copy_if(std::begin(arr),std::end(arr),std::back_inserter(vec),std::bind2nd(std::less<int>(),6)); //��6 ��Ϊ�ڶ����������� value < 6
    std::for_each(vec.begin(),vec.end(),disp); //1 2 3 4 5
 
 
    //ʹ���Զ���ķº���
    std::vector<person> vecP;
    person p1 = {1,"jack"}; vecP.push_back(p1);
    person p2 = {2,"rose"}; vecP.push_back(p2);
    person p3 = {3,"jane"}; vecP.push_back(p3);
 
    std::vector<person> vecRet;
    std::copy_if(vecP.begin(),vecP.end(),std::back_inserter(vecRet),std::bind2nd(person_filter_func(),"ja"));  //�������ؼ���"ja"��person�����Ƶ�vecRet������
    std::for_each(vecRet.begin(),vecRet.end(),disp_v);//1, jack  3, jane
}
