#include <iostream>
#include <map>
#include <functional>
using namespace std;
 
// ��ͨ����
int add(int i, int j) { return i + j; }
// lambda���ʽ
auto mod = [](int i, int j){return i % j; };
// ����������
struct divide
{
	int operator() (int denominator, int divisor)
	{
		return denominator / divisor;
	}
};
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	// ���޵�map
	map<char, int(*)(int, int)> binops_limit;
	binops_limit.insert({ '+', add });
	binops_limit.insert({ '%', mod });
	// ����	1	error C2664: ��void std::_Tree<std::_Tmap_traits<_Kty,_Ty,_Pr,_Alloc,false>>::insert(std::initializer_list<std::pair<const _Kty,_Ty>>)��: �޷������� 1 �ӡ�initializer-list��ת��Ϊ��std::pair<const _Kty,_Ty> &&��
	//binops_limit.insert({ '%', divide ()});
 
	// ������map
	map<char, function<int(int, int)>> binops = 
	{
		{ '+', add },
		{ '-', minus<int>() },
		{ '*', [](int i, int j){return i - j; } },
		{ '/', divide() },
		{ '%', mod },
	};
	cout << binops['+'](10, 5) << endl;
	cout << binops['-'](10, 5) << endl;
	cout << binops['*'](10, 5) << endl;
	cout << binops['/'](10, 5) << endl;
	cout << binops['%'](10, 5) << endl;
	system("pause");
	return 0;
}
///////////////////////////End Sub//////////////////////////////////
