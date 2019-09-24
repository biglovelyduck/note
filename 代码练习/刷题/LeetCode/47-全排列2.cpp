//47-ȫ����2
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
//vectorȥ�أ�res.erase(unique(res.begin(),res.end()),res.end()); 
class Solution { 
public:
	vector<int> nums;
	vector<vector<int> > res;
	vector<int> path;
	void DFS(int level,vector<int> visitor){
		if(level<0){
			res.push_back(path);
			return;
		}
		for(int i=0;i<nums.size();i++){
			//����ȷ��i-1�����壬Ȼ���жϸ������Ƿ�Ϊ�ظ��ģ��������������ظ��ģ�
			//��ô���ж���ǰ����ַ��Ƿ񱻷��ʣ����û�����ʣ�����ֱ�ӽ���һ�������Ϳ����ˡ� 
			if(visitor[i] || i>0&&nums[i]==nums[i-1]&&!visitor[i-1]) continue;
			visitor[i]=1;
			path.push_back(nums[i]);
			DFS(level-1,visitor);
			path.pop_back();
			visitor[i]=0;
		}
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> visitor(nums.size(),0);
        this->nums=nums;
        DFS(nums.size()-1,visitor);
        return res;
    }
};
