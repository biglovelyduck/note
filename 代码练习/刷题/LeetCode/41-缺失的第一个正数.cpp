//41-ȱʧ�ĵ�һ������
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
class Solution {
public:
	int a[100000000]={0};
    int firstMissingPositive(vector<int>& nums) {
        for(auto i:nums){
        	if(i>0)  a[i]=1;
		}
        int i=1;
    	while(true){
    		if(a[i]==0) return i;
    		i++;
		}
    }
};

//ʹ��find 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int>::iterator result ;//����һ��������
        /*
        ����˼����Ǵ���С������1��ʼ���ε������ң���result��nums.end()��ʱ��
        �ʹ������������û���������  ��ô�����������ȱʧ����С������������
        ����Ƚϼ�� �뷨Ҳ�Ƚϼ�
*/
        for(int i=1 ; ;i++){
            result=find( nums.begin( ), nums.end( ),i );
            if(result==nums.end()){
                    return i;
            }
        }
        return 0;
    }
};

public int firstMissingPositive(int[] nums) {
        for (int i = 0; i < nums.length;) {
            if (nums[i] <= nums.length && nums[i] >= 1 && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            } else {
                i++;
            }
        }
        int i = 0;
        while (i < nums.length && i + 1 == nums[i])
            i++;
        return i + 1;
    }


