/*简介

使用map的时候发现很多细节部分还是不清楚，所以重新整理一下。

#include <map> 
map是使用红黑树实现的，访问、查找和删除操作的复杂度都是O(logn)。
template<
    class Key,    //键
    class T,      //值
    class Compare = std::less<Key>,   // 
    class Allocator = std::allocator<std::pair<const Key, T> >
> class map;
注意: 默认的情况下，Key要支持<操作，并且排序规则是从小到大。*/ 

#include <iostream>
#inlcude <map> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*一. 构造函数

map的构造函数方式大体来说有如下几种：

std::map<std::string, int> default_map;    //默认构造
std::map<std::string, int> copied_map(default_map);    //拷贝构造
std::map<std::string, int> iter_map(default_map.find("abc"), default_map.end());    //Range constructor

//C++11 初始值列构造
std::map<std::string, int> init_map {
    {"this", 100},
    {"can", 100},
    {"be", 100},
    {"const", 100},
  };*/
  
/*二. 遍历操作

遍历map无疑就需要使用到迭代器，下面列出了四种map迭代器，详细的遍历可以看下文的代码部分。

iterator begin();   //返回指向起始元素的迭代器
iterator rbegin();  //返回指向末尾元素的迭代器

iterator end();     //返回指向末尾元素的后一个的迭代器
iterator rend();    //返回指向起始元素的前一个的迭代器
1
2
3
4
5
Map迭代器

C++11中还加入了at()函数，这里就不做介绍了。

*/

/*三. 插入操作

1. 使用[]插入

直接使用[]插入，如果mymap中不存在键值为"abc"元素，那么就执行插入操作。 
- 操作示例：mymap["abc"] = 1;

2. 插入单个元素

函数原型：std::pair<iterator,bool> insert( const value_type& value ); //这里的返回值：bool表示插入是否成功、iterator返回插入的位置
操作示例：mymap.insert( std::map<int, std::string>::value_type(1, "one") );
3. 插入多个元素

//函数原型：
template< class InputIt >
    void insert( InputIt first, InputIt last );
1
2
3
//操作示例：
std::map<int, std::string> tmp = {
    {5, "five"},
    {6, "six"}
};
mymap.insert( tmp.begin(),tmp.end() );

4. 使用std::initializer_list插入

C++11中新加入的插入数据方式： 
- 函数原型：void insert( std::initializer_list<value_type> ilist ); 
- 操作示例：mymap.insert( { {7, "seven"}, {8, "eight"}, {9, "nine"} } );*/
	return 0;
}
