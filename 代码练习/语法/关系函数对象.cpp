/*��ϵ�������� 
����equal_to<Tpye>
equal_to<string> stringEqual;
sres = stringEqual(sval1,sval2);
������not_equal_to<Type>
���� greater<Type>
���ڵ���greater_equal<Type>
С�� less<Type>
С�ڵ���less_equal<Type>
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main()
{
	vector<string> v1;
	v1.push_back("bbb");
	v1.push_back("aaa");
	v1.push_back("ccc");
	v1.push_back("zzzz");
	v1.push_back("ccc");
	string s1 = "ccc";
	//int num = count_if(v1.begin(),v1.end(), equal_to<string>(),s1);
	int num = count_if(v1.begin(),v1.end(),bind2nd(equal_to<string>(), s1));
	cout << num << endl;
	return 0;
} 

