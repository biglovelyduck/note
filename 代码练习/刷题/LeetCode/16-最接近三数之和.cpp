//16-最接近三数之和
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
using namespace std; 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //if(nums.size()<3) return 0;
        //为什么能想到的只有暴力。。。
		//正确思路：排序加上双指针
		sort(nums.begin(),nums.end());
		int start,end,min=0x3f3f3f3f;
		int result;
		for(int i=0;i<nums.size()-1;i++){
			//cout<<"--"<<endl;
			//if(nums[i]>target) break;
			start=i+1,end=nums.size()-1;
			while(start<end)
			{
				//cout<<"jinlai"<<endl;
				int sum=nums[i]+nums[start]+nums[end];
				if(min>abs(sum-target)){
					min=abs(sum-target);	//cout<<min<<endl;
					result=sum;
				}	
				if(sum<target)	start++;
				else if(sum>target)	end--;
				else return target;
			}
		} 
		return result;
    }
};

int main(){
	vector<int> nums={1,1,1,1};
	int target=0;
	Solution s;
	cout<<s.threeSumClosest(nums,target);
	return 0;
}
