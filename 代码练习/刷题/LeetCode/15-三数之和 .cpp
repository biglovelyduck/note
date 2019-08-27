//15-三数之和 
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
//1.暴力法 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	if(nums.size()<3) return {};
    	vector<vector<int> > res;
    	set<vector<int> > ret;	//去重 
        for(int i=0;i<nums.size()-2;i++){
        	for(int j=i+1;j<nums.size()-1;j++){
        		for(int k=j+1;k<nums.size();k++){
        			if(nums[i]+nums[k]+nums[j]==0){
        				vector<int> temp;
        				int a=(nums[i]<nums[j]?nums[i]:nums[j])<nums[k]?(nums[i]<nums[j]?nums[i]:nums[j]):nums[k];
        				int b=(nums[i]>nums[j]?nums[i]:nums[j])>nums[k]?(nums[i]>nums[j]?nums[i]:nums[j]):nums[k];
						int c=0-a-b;
						temp.push_back(a);
						temp.push_back(c);
						temp.push_back(b);
						ret.insert(temp);
					}
				}
			}
		}
		for(auto it:ret)
			res.push_back(it);
		return res;
    }
};

//暴力法的优化，直接查找第三个数是否存在
class Solution {
public:
    static bool cmp(const int&a,const int &b)
    {
        return a<b;
    }
    	vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        vector<int>::iterator it;
        vector<vector<int>> res;
        set<vector<int>> a;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) break;
            for(int j=i+1;j<nums.size();j++)
            {
                it=find(nums.begin()+j+1,nums.end(),0-nums[i]-nums[j]);
                if(it!=nums.end())
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(*it);
                    a.insert(temp);
                }
            }
        }
        for(auto k:a)
        {
            res.push_back(k);
        }
        return res;
    }
};

//对撞指针加排序加剪纸优化
class Solution{
public:
	vector<vector<int> > threeSum(vector<int>& nums){
		vector<vector<int>> res;
		sort(nums.begin(),nums.end());
		if(nums.empty()||nums.front()>0||nums.back()<0) return {};
		
		for(int i=0;i<nums.size();i++){
			int fix=nums[i];
			if(fix>0) break;
			if(i>0&&fix==nums[i-1]) continue;
			int l=i+1,r=nums.size()-1;
			while(l<r){
				if(nums[l]+nums[r]==-fix){
					if(l==i+1 || r==nums.size()-1){
		                res.push_back(vector<int>{nums[i],nums[l],nums[r]});
		                l++;r--;
		            }
		            else if(nums[l]==nums[l-1])
		                l++;
		            else if(nums[r]==nums[r+1])
		                r--;
		            else{
		                res.push_back(vector<int>{nums[i],nums[l],nums[r]});
		                l++;r--;
		            }
				}
				else if(nums[l]+nums[r]<-fix)
                    l++;
                else
                    r--;				
			}
		}
		return res;
	}
};

int main(){
	Solution s;
	vector<int> nums={-1,0,1,2,-1,-4}; 
	cout<<s.threeSum(nums).size()<<endl;
	return 0;
}
