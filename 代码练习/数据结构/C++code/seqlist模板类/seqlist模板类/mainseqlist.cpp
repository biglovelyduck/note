#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "SeqList.cpp"

using namespace std;

typedef struct Teacher{
	char name[64];
	int age;
}Teacher;
int main(){
	Teacher t1, t2, t3,tmp;
	t1.age = 21;
	t2.age = 22;
	t3.age = 33;
	SeqList<Teacher> list(10);
	list.insert(t1,0);
	list.insert(t2, 0);
	list.insert(t3 ,0);
	for (int i = 0; i < list.getLen(); i++){
		list.get(i, tmp);
		cout << tmp.age << " ";
	}
	while (list.getLen() > 0){
		list.del(0, tmp);
		cout << tmp.age << " ";
	}
	system("pause");
	return 0;
}
