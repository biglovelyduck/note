//55-��Ծ��Ϸ
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
//1.����˼·������ÿһ������Ϊ������ĸ��Ӷ�����һ�Σ�������������Զ���벻�ϸ���
//�����һֱ�������ͳɹ� 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k=0;		//����������Զ�����index 
        for(int i=0;i<nums.size();i++){
        	if(i>k) return false;
        	k=max(k,i+nums[i]); 
		}
		return true;
    }
};

//2.���ݣ�ģ��,ģ�����з�����û�а취��������ʱ��ͻ��� 
class Solution1 {
public:
	bool canJumpFromPosition(int position,vector<int> &nums){
		if(position==nums.size()-1) return true;
		int furtherJump=min(position+nums[position],int(nums.size()-1));	//��ǰλ������������Զλ��
		for(int next=furtherJump;next>position;next--) {
			if(canJumpFromPosition(next,nums)) return true;
		}
		return false;
	}
    bool canJump(vector<int>& nums) {
		return canJumpFromPosition(0,nums);
    }
};

//3.�Զ����µ�DP���ǻ��ݵ��Ż�����¼��� 
class Solution {
public:
    bool jump(vector<int>& dp, int p, vector<int>& nums){
        if(dp[p])
            return dp[p] == 1? true: false;
        int j = (p + nums[p]) < (nums.size() - 1)? p + nums[p]: nums.size() - 1;
        for(int i = p + 1; i <= j; ++i)
            if(jump(dp, i, nums)){
                dp[i] = 1;
                return true;
            }
        dp[p] = -1;
        return false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = 1;
        return jump(dp, 0, nums);
    }
};

//4.����˼·���Ե����ϵ�DP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size() - 1] = 1;
        
        for(int i = nums.size() - 2; i >= 0; i--){
            int jump = (i + nums[i]) < (nums.size() -1)? i + nums[i]: nums.size() - 1;
            for(int j = i + 1; j <= jump; j++){
                if(dp[j] == 1){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};



