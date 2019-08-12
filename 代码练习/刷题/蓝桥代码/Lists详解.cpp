#include<list> 
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//链表的打印
void print(list<int>& l) {
	list<int>::iterator i,iend;//每种容器都定义了自己的迭代器，迭代器变量相当于指针 
	iend=l.end(); //end()函数返回一个迭代器，指向链表的末尾。
	for(i=l.begin();i!=iend;i++)// begin()函数返回一个迭代器，指向list的第一个元素。由容器来调用 
	cout<<*i<<' ';
}

int main(int argc, char** argv) {
	list<int> l;
	for(int j=1;j<=10;j++){
		l.push_back(j);//语法:void push_back( const TYPE &val );适用于各种类型push_back()将val连接到链表的最后。
	} 
	list<int> carry; 
	//splice()函数  
    /* 
        语法:
    void splice( iterator pos, list &lst );
    void splice( iterator pos, list &lst, iterator del );
    void splice( iterator pos, list &lst, iterator start, iterator end );
    splice()函数把lst连接到pos的位置。如果指定其他参数，则插入lst中del所指元素到现链表的pos上，或者用start和end指定范围。
    */  
    carry.splice(carry.begin(),l,l.begin());//把l中从begin开始的迭代器开始插入到carry中
	cout<<"carry的链表元素为：";
	print(carry); //??????
	cout<<endl;
	
	cout<<"l的链表元素为：";
	print(l);
	cout<<endl;
	
	list<int> x;
	x.push_back(34); 
	x.push_back(33);
	x.push_back(32);
	/* 语法:
    void merge( list &lst );
    void merge( list &lst, Comp compfunction );
    merge()函数把自己和lst链表连接在一起，产生一个整齐排列的组合链表。如果指定compfunction，则将指定函数作为比较的依据。*/
    l.merge(x);//将链表x连接到链表l上，返回l
	cout<<"l的链表元素为：";
	print(l);
	cout<<endl; 
	getchar();//目的就是为了在退出之前可以让调用者再输入一个字符，这时候系统的I/O就停留在读入之上，调用者就可以看清输出了。
	return 0;
}
