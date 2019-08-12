//在数组中查找数字出现的次数 
#include <algorithm>
#include <vector> 
using namespace std;
class Solution{
public:	
	int findCount(vector<int>& v,int num){
		sort(v.begin(),v.end());
		vector<int>::iterator start,end;
		start=lower_bound(v.begin(),v.end(),num);
		end=upper_bound(v.begin(),v.end(),num);
		return end-start;
	}
};
