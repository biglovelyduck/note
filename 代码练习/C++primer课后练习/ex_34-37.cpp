#include <iostream>
#include <iterator>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

//34  �����ӡvector 
void r_print(const vector<string> &v);
//35 ��ͨ�����������ӡһ��vector
void r_withOrdinary_print(const vector<string> &v); 
//36 ʹ��find��list�в������һ��ֵΪ0��Ԫ��λ�� 
list<int>::iterator find_last_0(list<int> &l);
//37 vector(10)�е�λ��3-7֮���Ԫ�����򿽱���list 
void vec2list_3_7_reverse(vector<int> &v,list<int> &list);


int main(){
	vector<string> v={"a1","b1","c1"};
	//34
	r_print(v);
	cout<<"\n";
	
	//35
	r_withOrdinary_print(v);
    std::cout << "\n";
    
    //36
	std::list<int>  l = {1,2,3,4,0,5,6};
    auto it = find_last_0(l);
    std::cout << *it << "\n";
    
    //37
    std::vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
    std::list<int>  lst;
    vec2list_3_7_reverse(vi,lst);
    for(auto e : lst)
        std::cout << e <<" ";
    std::cout << std::endl;
	return 0;
}

inline void 
r_print(const vector<string> &v){
	for_each(v.crbegin(),v.crend(),[](const string &s){
		cout<<s<<" ";
	});
}

inline void
r_withOrdinary_print(const vector<string> &v){
	for(auto it=prev(v.cend());it!=prev(v.cbegin());--it){
		cout<<*it<<" ";
	}
}

inline list<int>::iterator  
find_last_0(list<int> &l){
	auto r_it=find(l.rbegin(),l.rend(),0);
	auto it=r_it.base();//��תΪ������˳��,λ��+1 
	return prev(it); 
}

inline void 
vec2list_3_7_reverse(vector<int> &v,list<int> &list){
	copy(v.crbegin()+3,v.crend()-2,back_inserter(list));
}
