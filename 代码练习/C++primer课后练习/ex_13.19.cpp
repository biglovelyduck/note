//  Answer: No, cause there really is no sensible meaning. employee can't copy in real world.
#include <string>
using namespace std;
class Emploee{
public:
	Employee();
    Employee(const string &name);
    //拷贝控制成员,不需要
	Emploee(const Emploee&)=delete;
	Emploee& operator=(const Emploee&)=delete; 
private:
    string name_;
    int id_;
    static int s_increment;	
};
