#include <list>
#include <iostream>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//����Ĵ�ӡ
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
	    charList.push_front(i+65);//void push_front( const TYPE &val );������val���ӵ������ͷ����
	printList(charList);
	//ɾ������'E'��ʵ��
	charList.remove('E');
	printList(charList);
	//Ϊ��������
	charList.sort();
	printList(charList);
	charList.push_back('E');  
    charList.push_back('E');  
    charList.push_back('E'); 
    printList(charList);
    //ɾ���б������ظ���Ԫ��
	charList.unique();
	printList(charList); 
	printf("hello...\n");
	system("pause"); 
	return 0;
}
