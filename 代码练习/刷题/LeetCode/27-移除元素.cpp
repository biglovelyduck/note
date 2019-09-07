//27-ÒÆ³ýÔªËØ
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <stack>
using namespace std;
//1.Ë«Ö¸Õë 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
		int i=0;
		for(int j=0;j<nums.size();j++){
			if(nums[j]!=val){
				nums[i++]=nums[j];
			}
		}
		return i; 
    }
}; 

//2.Ë«Ö¸Õë 
class Solution{
	
};
