#include <iostream>
using namespace std;

void main01()
{
	char YourName[50];
	int myInt;
	long myLong;
	double myDouble;
	float myFloat;
	unsigned int myUnsigned;

	cout << "请输入一个Int: ";
	cin >> myInt;
	cout << "请输入一个Long: ";
	cin >> myLong;
	cout << "请输入一个Double: ";
	cin >> myDouble;

	cout << "请输入你的姓名: ";
	cin >> YourName;

	cout << "\n\n你输入的数是：" << endl;
	cout << "Int: \t" << myInt << endl;
	cout << "Long: \t" << myLong << endl;
	cout << "Double: \t" << myDouble << endl;
	cout << "姓名: \t" << YourName << endl;
	cout<< endl << endl;
	system("pause");
	return ;
}

//1 输入英文 ok 
//2 ctr+z  会产生一个 EOF(-1)
int main02()
{
	char ch;
	while( (ch= cin.get())!= EOF)
	{
		std::cout << "字符: " << ch << std::endl;
	}
	std::cout << "\n结束.\n";
	system("pause");
	return 0;
}

//演示:读一个字符 链式编程
int main03()
{
	char a, b, c;
	cin.get(a);
	cin.get(b);
	cin.get(c);
	cout << a << b << c<< endl;

	cout << "开始链式编程" << endl;
	cout.flush();

	cin.get(a).get(b).get(c);
	cout << a << b << c<< endl;
	system("pause");
	return 0;
}


//演示cin.getline() 可以接受空格
int main04()
{
	char buf1[256];
	char buf2[256]; 
	cout << "\n请输入你的字符串 不超过256" ;
	cin.getline(buf1, 256, '\n'); 
	cout << buf1 << endl;

	// 
	cout << "注意: cin.getline() 和 cin >> buf2 的区别, 能不能带空格 " << endl;
	cin >> buf2 ; //流提取操作符 遇见空格 停止提取输入流
	cout << buf2 << endl;
	system("pause");
	return 0;
}

//缓冲区实验 
/*
1 输入 "aa bb cc dd" 字符串入缓冲区 
2 通过 cin >> buf1; 提走了 aa 
3 不需要输入 可以再通过cin.getline() 把剩余的缓冲区数据提走
*/
int main05()
{
	char buf1[256];
	char buf2[256];

	cout << "请输入带有空格的字符串,测试缓冲区" << endl; 
	cin >> buf1;
	cout << "buf1:" << buf1 << endl; 

	cout << "请输入数据..." << endl;

	//缓冲区没有数据,就等待; 缓冲区如果有数据直接从缓冲区中拿走数据
	cin.getline(buf2, 256); 
	cout << "buf2:" << buf2 << endl;
	system("pause");
	return 0;
}

// ignore 和 peek
void main06()
{
	int  intchar;
	char buf1[256];
	char buf2[256];

	cout << "请输入带有空格的字符串,测试缓冲区 aa bb cc dd ee " << endl; 
	cin >> buf1;
	cout << "buf1:" << buf1 << endl; 

	cout << "请输入数据..." << endl;
	cin.ignore(2);
	//intchar = cin.peek();
	//cout << "缓冲区若有数据,返回第一个数据的asc码:" << intchar << endl;

	//缓冲区没有数据,就等待; 缓冲区如果有数据直接从缓冲区中拿走数据
	cin.getline(buf2, 256); 
	cout << "buf2:" << buf2 << endl;

	intchar = cin.peek(); //没有缓冲区 默认是阻塞模式 
	cout << "缓冲区若有数据,返回第一个数据的asc码:" << intchar << endl;
	system("pause");
}

//案例:输入的整数和字符串分开处理
int main() 
{
	cout << "Please, enter a number or a word: ";
	char c = std::cin.get();

	if ( (c >= '0') && (c <= '9') ) //输入的整数和字符串 分开处理
	{
		int n; //整数不可能 中间有空格 使用cin >>n
		cin.putback (c);
		cin >> n;
		cout << "You entered a number: " << n << '\n';
	}
	else
	{
		string str;
		cin.putback (c);
		getline (cin,str); // //字符串 中间可能有空格 使用 cin.getline();
		cout << "You entered a word: " << str << '\n';
	}	system("pause");
	return 0;
}

