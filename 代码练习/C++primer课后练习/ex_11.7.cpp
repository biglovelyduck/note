#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	map<string,vector<string> > famls;
	string lastName,chldName;
	while([&]()->bool{
		cout<<"Please enter lastName:\n";
		return cin>>lastName&&lastName!="@q";
	}())
//! the () used here is to call the lambda ,otherwise it does not work
	{
		cout<<"Please enter children's name:\n";
		while(cin>>chldName&&chldName!="@q"){
			famls[lastName].push_back(chldName);
		}
	}
	
	for(auto e : famls)
    {
        std::cout << e.first << ":\n";

        //! iterate through the vector.
        for(auto c : e.second)
            std::cout << c << " ";
        std::cout << "\n";
    }
	return 0;
} 
