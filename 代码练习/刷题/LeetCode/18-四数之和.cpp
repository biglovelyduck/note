//18-����֮��
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


//Ҫ�������ü�֦�Ϳ�����ȥ�ظ�������ʹ��set 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	vector<vector<int>> vv;
    	set<vector<int> > s;
        sort(nums.begin(),nums.end());
        if(nums.size()<4) return {};
        int len=nums.size();
        for(int i=0;i<len-3;i++){
        	//ȥ�أ���֦
			if(i>0&&nums[i]==nums[i-1]) continue; 
			//�����һ���̶����ͺ���������С���ĺʹ���target������
			if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break; 
			//�����һ���̶����ͺ�������������ĺ�С��target��������һ������ 
			if(nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
        	for(int j=i+1;j<len-2;j++){
        		//ȥ�أ���֦
				if(j-i-1>0&&nums[j]==nums[j-1]) continue; 
				//���ǰ�����̶����ͺ�����������С���ĺʹ���target������
				if(nums[i]+nums[j]+nums[j+1]+nums[j+1]>target) break; 
				//���ǰ�����̶����ͺ���������������ĺ�С��target��������һ������
				if(nums[i]+nums[j]+nums[len-2]+nums[len-1]<target) continue;  
        		int start=j+1,end=len-1;
        		while(start<end){
        			int sum=nums[i]+nums[j]+nums[start]+nums[end];
        			vector<int> v;
        			if(sum==target){
        				v.push_back(nums[i]);
        				v.push_back(nums[j]);
        				v.push_back(nums[start]);
        				v.push_back(nums[end]);
        				sort(v.begin(),v.end());
        				s.insert(v);
        				//vv.push_back(v);
        				start++,end--;
					}
					else if(sum>target) end--;
					else start++;
				}
			}
		}
    	for(auto v:s){
    		vv.push_back(v);
		}
		return vv;
	}
};
