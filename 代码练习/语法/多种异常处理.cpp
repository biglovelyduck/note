#include <iostream> 
using namespace std;
class A{};
class B{};

int main()
{
	try
	{
		int 	j = 0;    
		double 	d = 2.3;    
		char 	str[20] = "Hello";
		cout<<"Please input a exception number: ";
		int a; 
		cin>>a;
		switch(a)
		{
		case  1: 
			throw d;      
		case  2: 
			throw j;      
		case  3: 
			throw str;
		case  4: 
			throw A();      
		case  5: 
			throw B();
		default: 
			cout<<"No throws here.\n";    
		}
	}
	catch(int)
	{
		cout<<"int exception.\n";
	}
	catch(double)
	{
		cout<<"double exception.\n";
	}
	catch(char*)
	{
		cout<<"char* exception.\n";
	}
	catch(A)
	{
		cout<<"class A exception.\n";
	}
	catch(B)
	{
		cout<<"class B exception.\n";
	}
	cout<<"That's ok.\n";
	system("pause");
}//====================================

