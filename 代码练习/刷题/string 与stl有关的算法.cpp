//
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
//#include <boost/bind.hpp>
using namespace std;
int main(){
	//trim 
//	string s(" hello ");
//    s.erase(0, s.find_first_not_of(' '));	//ɾ��ǰ��Ŀո�
//    cout << s;
//    s.erase(s.find_last_not_of(' ') +1);	//ɾ������Ŀո� 
//    cout << s;
    //erase�����ַ�
//	string s("   h  e    llo, w    orld. say bye   ");
//    s.erase(remove_if(s.begin(),s.end(), bind2nd(equal_to<char>(), ' ')), s.end()); 
//    cout<<s<<endl; 
	//startwith,endwith
//    string s("hello, world");
//    string head("hello");
//    string tail("ld");
//    bool startwith = s.compare(0, head.size(), head) == 0;
//    cout << boolalpha << startwith << endl;
//    bool endwith = s.compare(s.size() - tail.size(), tail.size(), tail) == 0;
//    cout << boolalpha << endwith << endl;
	//�Ѱ�һ��װ�� string �������������е� string ������������ô����
//	vector<string> vect;
//    vect.push_back("hello");
//    vect.push_back(", ");
//    vect.push_back("world");
//    cout << accumulate(vect.begin(), vect.end(), string("")); 
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> lst(arr, arr + 10);

    lst.erase(remove_if(lst.begin(), lst.end(),
        boost::bind(std::modulus<int>(), _1, 2) == 0),
        lst.end()
    );
           
    std::copy(lst.begin(), lst.end(),
        std::ostream_iterator<int>(std::cout, " "));
}
