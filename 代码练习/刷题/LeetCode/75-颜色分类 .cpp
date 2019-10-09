//75-��ɫ���� 
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
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int a[3];
    	memset(a,0,sizeof(a));
    	for(int i=0;i<nums.size();i++) a[nums[i]]++;
    	int index=0;
    	for(int i=0;i<3;i++)
    		while(a[i]--) nums[index++]=i;
    }
};

class Solution1 {
  public:
  /*
  ������ɫ�������
  */
  void sortColors(vector<int>& nums) {
    // �������� idx < p0 : nums[idx < p0] = 0
    // curr �ǵ�ǰ����Ԫ�ص��±�
    int p0 = 0, curr = 0;
    // �������� idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};

