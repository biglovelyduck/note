
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int increase (int i)  
{  
	return i+1;   
}  

int main()
		{
			vector<int> vecIntA;
			vecIntA.push_back(1);
			vecIntA.push_back(3);
			vecIntA.push_back(5);
			vecIntA.push_back(7);
			vecIntA.push_back(9);
			transform(vecIntA.begin(),vecIntA.end(),vecIntA.begin(),increase);		//vecIntA : {2,4,6,8,10}
			transform(vecIntA.begin(),vecIntA.end(),vecIntA.begin(), negate<int>() );
			return 0;
		}

