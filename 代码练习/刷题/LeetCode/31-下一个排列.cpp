//31-��һ������ 
//��ȫû˼·������������е����У�Ȼ���ҵ���һ�� 
//˼·��
/*�Ӻ���ǰ�ҵ���һ��С��ǰ���Ԫ�أ�Ȼ���ں����ҵ��ձ���������Ԫ�ؽ�����Ȼ��ת����*/ 
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
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i=0, j=0;
		for(i=nums.size()-1; i && nums[i-1]>=nums[i]; --i);
		if(i){
			for(j=nums.size()-1; i<j && nums[i-1]>=nums[j]; --j);
			swap(nums[i-1],nums[j]);
		}
		reverse(nums.begin()+(i-1==j?0:i),nums.end());
	}
};

