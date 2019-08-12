//For13.14
/*#include <iostream>
using namespace std;
class numbered{
public:
	numbered(){
		static int unique=10;
		mysn=unique++;
	}
	
	int mysn;
};

void f(numbered s){
	cout<<s.mysn<<endl;
}
//����Ĭ�ϵĿ������캯�� 
int main(){
	numbered a,b=a,c=b;
	f(a);
	f(b);
	f(c);
}

output:
10
10
10
*/

/* 
//For 13.15
#include <iostream>
using namespace std;
class numbered{
public:
	numbered(){
		static int unique=10;
		mysn=unique++;
	}
	//�Զ��忽�����캯�� 
	numbered(const numbered& n) {
        mysn = n.mysn + 1;
    }
	
	int mysn;
};

void f(numbered s){//��ֵ���ݣ�����ÿ������캯�� 
	cout<<s.mysn<<endl;
}
//�Զ��忽�����캯�� 
int main(){
	numbered a;
	f(a);
	f(b);
	f(c);
}

output:
11
12
13
*/

//  For 13.16

#include <iostream>

class numbered {
public:
    numbered() {
        static int unique = 10;
        mysn = unique++;
    }

    numbered(const numbered& n) {
        mysn = n.mysn + 1;
    }

    int mysn;
};

void f(const numbered& s) {
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}

// output
// 10
// 11
// 12

