#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <set>
using namespace std;
void SetExample1()
{
	cout << "*********SetExample1*********" << endl;
 
	set<int> c;
	c.insert(1);
	c.insert(2);
	c.insert(3);//2
	c.insert(3);
	c.insert(3);
	c.insert(3);
	c.insert(3);
	c.insert(3);//7
	c.insert(4);
	c.insert(5);
	c.insert(6);
 
	cout << "lower_bound(3): " << *c.lower_bound(3) << endl;
	cout << "upper_bound(3): " << *c.upper_bound(3) << endl;
	cout << "equal_bound(3): " << *c.equal_range(3).first 
		<< " " << *c.equal_range(3).second << endl;
 
	cout << "lower_bound(5): " << *c.lower_bound(5) << endl;
	cout << "upper_bound(5): " << *c.upper_bound(5) << endl;
	cout << "equal_bound(5): " << *c.equal_range(5).first 
		<< " " << *c.equal_range(5).second << endl;
}

int main()
{
	/*
    //! ex 11.9
    std::map<std::string, std::list<std::size_t>> m;

    //! ex 11.10
    //! can be declared.
    std::map<std::vector<int>::iterator, int> mv;
    std::map<std::list<int>::iterator, int> ml;


    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(),0));

    //! but when using this one the compiler complained that
    //! error: no match for 'operator<' in '__x < __y'
    std::list<int> li;
    ml.insert(std::pair<std::list<int>::iterator,int>(li.begin(),0));
    */
    SetExample1();
    return 0;
}

