#include <iostream>
using namespace std;
int divide(int x, int y )
{
	if (y ==0)
	{
		throw x;
	}
	return x/y;
}

int main()
{
	try
	{
		cout << "8/2 = " << divide(8, 2) << endl;
		cout << "10/0 =" << divide(10, 0) << endl;
	}
	catch (int e)
	{
		cout << e<< " is divided by zero!" << endl;
	}
	catch(...)
	{
		cout << "δ֪�쳣" << endl;
	}
	
	cout << "ok" << endl;
 	system("pause");
	return 0;
}

