#include <iostream>
#include <set>
#include <string>
using namespace std;
//ģ���� 
template<class T>
class RuntimeCmp
{
public:
	//������ ,�������� 
	enum cmp_mode {normal, reverse};
private:
	// ����ʽ 
	cmp_mode emMode;
 
public:
	//���캯�� ������Ĭ��Ϊnormal    ����ֵ��Ա���� 
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
		return emMode == normal ? t1 < t2 :t2 < t1;//����ģʽֵȷ����Ҫ���õ�ֵ
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
 	//���캯�� 
	RuntimeCmp<int> reverse_order(RuntimeCmp<int>::reverse);
 
	IntSet nSetContainer2(reverse_order);
	fill(nSetContainer2);
	PrintElements(nSetContainer2, "Set2: ");
 
	nSetContainer = nSetContainer2;//������ֵ��Ԫ�أ�Ҳ��ֵ������׼��
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
