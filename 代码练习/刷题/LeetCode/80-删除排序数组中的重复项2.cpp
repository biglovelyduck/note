//80-ɾ�����������е��ظ���2 
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
#include <regex>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		//�϶���˫ָ��
		if(nums.size()<=1) return nums.size();
		int current=1;	//����������Чλ�õ���� һλ
		for(int i=2;i<nums.size();i++){
			if(nums[i]!=nums[current-1]){
				current+=1;
				nums[current]=nums[i];
			}
		} 
		return current+1;
    }
};
