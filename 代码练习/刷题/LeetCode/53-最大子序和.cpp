//53-最大子序和 
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
#include <queue>
using namespace std;
//最弱解法 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum(nums.size(),0);
        bool flag=false;
        for(int i=0;i<nums.size();i++)
        	sum[i]=(i>0)?(sum[i-1]+nums[i]):nums[i];
    	int ans=nums[0];
    	//sort(nums.begin(),nums.end());
    	//if(nums[0]>=0) return sum[nums.size()-1];
    	for(int i=0;i<sum.size();i++){
    		for(int j=i+1;j<sum.size();j++){
    			ans=max(ans,sum[j]-sum[i]);
    			ans=max(ans,sum[j]);
			}
		}
		return ans;
    }
};

//1.暴力
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int max=nums[0];//存最大值 
        int sum=0;//求和
        for(int i=0;i<nums.size();i++)
        {
            sum=0;
            for(int j=i;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum>max) max=sum;
            }
        }
        return max;
    }
};

//2.DP
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int res = INT_MIN;
        int sum = -1;			//表示当前位置的连续子序列最大和 
        for(int i = 0; i < nums.size(); ++i)
        {
            sum = max(nums[i], sum + nums[i]);
            res = max(sum, res);
        }
        return res;
    }
};

//3.分治，二分
class Solution{
public:
	int maxSubArray(vector<int>& nums){
		if(nums.empty()) return 0;
		return fenzhifa(nus,0,nums.size()-1);
	}
	
	int fenzhifa(vector<int> &nums,int left,int right){
		if(left>right) return INT_MIN;
		if(left==right) return nums[left];
		int mid=(left+right)/2;
		int l=fenzhifa(nums,0,mid-1);
		int r=fenzhifa(nums,mid+1,right);
		int t=nums[mid];
		
		int max_num=nums[mid];
		for(int i=mid-1;i>=left;i--)//整合左半部分
        {
            t+=nums[i];
            max_num=max(max_num,t);
        }
        t=max_num;
        for(int i=mid+1;i<=right;i++)//整合右半部分
        {
            t+=nums[i];
            max_num=max(max_num,t);
        }
        return max(max(r,l),max_num);
	}
}; 
 

int main(){
	vector<int> v={-1};
	Solution s;
	cout<<s.maxSubArray(v)<<endl;
	return 0;
}
