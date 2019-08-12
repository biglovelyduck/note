#include <iostream>
#include <set>
#include <string>
using namespace std;
//模板类 
template<class T>
class RuntimeCmp
{
public:
	//升序降序 ,声明类型 
	enum cmp_mode {normal, reverse};
private:
	// 排序方式 
	cmp_mode emMode;
 
public:
	//构造函数 ，参数默认为normal    ：赋值成员变量 
	RuntimeCmp(cmp_mode m = normal) : emMode(m){
		if (m== normal)
		{
			cout << "normal" << endl;
		}
		else
		{
 
			cout << "reverse" << endl;
		}
	}
	bool operator() (const T &t1, const T &t2)const
	{
		return emMode == normal ? t1 < t2 :t2 < t1;//根据模式值确定需要调用的值
	}
	bool operator== (const RuntimeCmp& rc)
	{
		return emMode == rc.emMode;
	}
};
 
typedef set<int, RuntimeCmp<int> >IntSet;
 
void fill(IntSet & nSet)
{
	nSet.insert(4);
	nSet.insert(7);
	nSet.insert(5);
	nSet.insert(1);
	nSet.insert(6);
	nSet.insert(2);
	nSet.insert(5);
}
void SetExample3()
{
	cout << "*********SetExample3*********" << endl;
 
	IntSet nSetContainer;
	fill(nSetContainer);
	IntSet::iterator it = nSetContainer.begin();
 
	PrintElements(nSetContainer, "Set1: ");
 	//构造函数 
	RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);
 
	IntSet nSetContainer2(reverse_order);
	fill(nSetContainer2);
	PrintElements(nSetContainer2, "Set2: ");
 
	nSetContainer = nSetContainer2;//不见赋值了元素，也赋值了排序准则
	nSetContainer.insert(3);
	PrintElements(nSetContainer, "Set1: ");
 
	if (nSetContainer.value_comp() == nSetContainer2.value_comp())
	{
		cout << "set1 and set2 have same sorting criterion" << endl;
	} 
	else
	{
		cout << "set1 and set2 have different sorting criterion" << endl;
	}
 
}
