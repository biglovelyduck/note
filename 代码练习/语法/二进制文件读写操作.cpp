#include <fstream>
#include <iostream>
#include <string>
using namespace std; 
class Teacher{
	private:
		int age;
		string name;
	public:
		Teacher(int age,string name){
			this->age=age;
			this->name=name;
		}
		~Teacher(){
		}
		printT(){
			cout<<"age:"<<age<<endl;
			cout<<"name:"<<name<<endl;
		}
};

//二进制
int main()
{
	char fileName[255] = "H:/文件Test/teacher.dat";
	ofstream fout(fileName,ios::binary);
	if(!fout)
	{
		cout << "Unable to open " << fileName << " for writing.\n";
		return(1);
	}

	Teacher t1(31, "31");
	Teacher t2(32, "32");
	fout.write((char *)&t1,sizeof (Teacher));
	fout.write((char *)&t2,sizeof (Teacher));
	fout.close();

	cout << "保存对象到二进制文件里成功!" << endl;

	ifstream fin(fileName,ios::binary);
	if(!fin)
	{
		cout << "Unable to open " << fileName << " for reading.\n";
		return (1);
	}
	Teacher tmp(100,"100");

	fin.read((char *)&tmp,sizeof (Teacher));
	tmp.printT();
	fin.read((char *)&tmp,sizeof (Teacher));
	tmp.printT();
	system("pause");

	return 0;
}

