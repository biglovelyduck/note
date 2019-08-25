#include <bits/stdc++.h>
using namespace std;
/*1.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> v;
        for(int i=0;i<nums.size();i++){
        	for(int j=i+1;j<nums.size();j++){
        		if(nums[j]==target-nums[i])
        		{
        			v.push_back(i);
        			v.push_back(j);
				}
			}
		}
		return v;
    }
};*/

//2.Á½±é¹þÏ£ 
class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target){
		map<int,int> a;
		vector<int> b(2,-1);
		for(int i=0;i<nums.size();i++)
			//a.insert(map<int,int>::value_type(nums[i],i));	//new pair
			a.insert(pair<int,int>(nums[i],i));
		for(int i=0;i<nums.size();i++){
			if(a.count(target-nums[i])>0&&a[target-nums[i]]!=i){
				b[0]=i;
				b[1]=a[target-nums[i]];
				break;
			}
		}
		return b;
	} 
};

//3.Ò»±é¹þÏ£
class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target){
		map<int,int> a;
		vector<int> b(2,-1);
		for(int i=0;i<nums.size();i++){
			if(a.count(target-nums[i])>0){
				b[0]=a[target-nums[i]];
				b[1]=i;
				break;
			}
			a[nums[i]]=i;
		}
		return b;
	} 
};
