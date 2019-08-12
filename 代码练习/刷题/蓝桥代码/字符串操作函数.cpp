#include <iostream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	string s1="hello";
	string s2;
	s2.assign(s1,0,3);//用于赋予新值，assign函数用于将一个字符串的部分内容赋值给另一个string,对象s2的值为“hel”
	
	swap(s1,s2);////交换两个字符串的内容,swap函数将s1和s2的内容交换，现在s1="hel",s2="hello" 
	
	//+=、append()、push_back()//在字符串尾部追加内容,"+="可追加string对象，字符以及C风格字符串，append函数则可以追加string对象和C风格字符串，push_back函数则只能追加字符
	s1+=s2;
	s1+="world";
	s1+='c';
	
	s1.append(s2);
	s1.append(" world");
	s1.push_back('c');
	
	//insert()//用于插入字符串
	string s3="world";
	s3.insert(0,"hello ");
	s3.insert(6,"haha ");
	cout<<"s3="<<s3<<endl; 
	
	//erase()//用于删除指定位置的字符
	s3.erase(6,5);
	cout<<"s3="<<s3<<endl; //删除从6位置开始的5个字符
	//还可以删除迭代器的位置
	string::iterator it=s3.begin()+1;
	s3.erase(it); //删除迭代器位置为1的字符 
	cout<<"s3="<<s3<<endl; 
	s3.erase(s3.begin(),s3.begin()+4);//删除之间的所有字符 
	cout<<"s3="<<s3<<endl<<endl; 
	
	//clear()函数和~string()//都是用来删除全部字符的
	s3.clear();
	s3.insert(0,"c");//此时s3为一个空串 
	cout<<"s3="<<s3<<endl;
	//s3.~string();//销毁所有字符，释放内存，不可以随便销毁 
	//cout<<"s3="<<s3<<endl;
	
	// ==、！=、<、<=、>、>=、compare()//比较字符串
	if(s1.compare(s2) == 0)
          cout << "相等" << endl;  
    else  cout << "不相等" << endl;
    
    //data()函数，将内容以字符数组的形式返回
	const char *a=s3.data();// const char *data();data()函数返回指向自己的第一个字符的指针.
	cout<<"a="<<a<<endl; 
	
  /*size()函数和length()函数，返回字符串的字符数
 eg.string str = "haha";
    str.size() 等于 str.length(),值均为4
 
    empty()//判断字符串是否为空
 */
	return 0;
}
