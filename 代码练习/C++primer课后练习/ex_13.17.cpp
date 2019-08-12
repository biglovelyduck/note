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
//调用默认的拷贝构造函数 
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
	//自定义拷贝构造函数 
	numbered(const numbered& n) {
        mysn = n.mysn + 1;
    }
	
	int mysn;
};

void f(numbered s){//按值传递，会调用拷贝构造函数 
	cout<<s.mysn<<endl;
}
//自定义拷贝构造函数 
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

