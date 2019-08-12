#include <list>
#include <iostream>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//链表的打印
void printList(list<char>& l) {
	list<char>::iterator i,iend;
	iend=l.end(); 
	for(i=l.begin();i!=l.end();i++){
		cout<<*i<<' ';
	}
	cout<<endl;
}

int main(int argc, char** argv) {
	list<char> charList;
	for(int i=0;i<10;i++)
	    charList.push_front(i+65);//void push_front( const TYPE &val );函数将val连接到链表的头部。
	printList(charList);
	//删除所有'E'的实例
	charList.remove('E');
	printList(charList);
	//为链表升序
	charList.sort();
	printList(charList);
	charList.push_back('E');  
    charList.push_back('E');  
    charList.push_back('E'); 
    printList(charList);
    //删除列表所有重复的元素
	charList.unique();
	printList(charList); 
	printf("hello...\n");
	system("pause"); 
	return 0;
}
