//26-ɾ�����������е��ظ���
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
//˫ָ�� 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i=0;
        for(int j=1;j<nums.size();j++){
        	if(nums[j]!=nums[i]){
        		nums[++i]=nums[j];
			}
			//�����ȵĻ�j�ͻ�������� 
		}
		return i+1; 
    }
}; 
