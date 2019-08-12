/*���

ʹ��map��ʱ���ֺܶ�ϸ�ڲ��ֻ��ǲ������������������һ�¡�

#include <map> 
map��ʹ�ú����ʵ�ֵģ����ʡ����Һ�ɾ�������ĸ��Ӷȶ���O(logn)��
template<
    class Key,    //��
    class T,      //ֵ
    class Compare = std::less<Key>,   // 
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map;
ע��: Ĭ�ϵ�����£�KeyҪ֧��<������������������Ǵ�С����*/ 

#include <iostream>
#inlcude <map> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*һ. ���캯��

map�Ĺ��캯����ʽ������˵�����¼��֣�

std::map<std::string, int> default_map;    //Ĭ�Ϲ���
std::map<std::string, int> copied_map(default_map);    //��������
std::map<std::string, int> iter_map(default_map.find("abc"), default_map.end());    //Range constructor

//C++11 ��ʼֵ�й���
std::map<std::string, int> init_map {
    {"this", 100},
    {"can", 100},
    {"be", 100},
    {"const", 100},
  };*/
  
/*��. ��������

����map���ɾ���Ҫʹ�õ��������������г�������map����������ϸ�ı������Կ����ĵĴ��벿�֡�

iterator begin();   //����ָ����ʼԪ�صĵ�����
iterator rbegin();  //����ָ��ĩβԪ�صĵ�����

iterator end();     //����ָ��ĩβԪ�صĺ�һ���ĵ�����
iterator rend();    //����ָ����ʼԪ�ص�ǰһ���ĵ�����
1
2
3
4
5
Map������

C++11�л�������at()����������Ͳ��������ˡ�

*/

/*��. �������

1. ʹ��[]����

ֱ��ʹ��[]���룬���mymap�в����ڼ�ֵΪ"abc"Ԫ�أ���ô��ִ�в�������� 
- ����ʾ����mymap["abc"] = 1;

2. ���뵥��Ԫ��

����ԭ�ͣ�std::pair<iterator,bool> insert( const value_type& value ); //����ķ���ֵ��bool��ʾ�����Ƿ�ɹ���iterator���ز����λ��
����ʾ����mymap.insert( std::map<int, std::string>::value_type(1, "one") );
3. ������Ԫ��

//����ԭ�ͣ�
template< class InputIt >
    void insert( InputIt first, InputIt last );
1
2
3
//����ʾ����
std::map<int, std::string> tmp = {
    {5, "five"},
    {6, "six"}
};
mymap.insert( tmp.begin(),tmp.end() );

4. ʹ��std::initializer_list����

C++11���¼���Ĳ������ݷ�ʽ�� 
- ����ԭ�ͣ�void insert( std::initializer_list<value_type> ilist ); 
- ����ʾ����mymap.insert( { {7, "seven"}, {8, "eight"}, {9, "nine"} } );*/
	return 0;
}
