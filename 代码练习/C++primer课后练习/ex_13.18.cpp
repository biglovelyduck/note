#include <iostream>
#include <string>
using namespace std;
class Emploee{
public:
	Emploee();
	Emploee(const string &name);
	~Emploee();
	
	const int getId() const{ return this->id;}
private:
	string name;
	int id;
	static int increment;
};

int Emploee::increment=0;

Emploee::Emploee(){
	id=increment++;
}

Emploee::Emploee(const string &name){
	id=increment++;
	this->name=name;
}
