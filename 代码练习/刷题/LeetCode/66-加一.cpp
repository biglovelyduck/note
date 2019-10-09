//66-��һ
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
#include<regex>
using namespace std; 

//1.����long long���� 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num=0;
        for(int i=0;i<digits.size();i++) num=num*10+digits[i];
        num+=1;
        vector<int> ret;
        string s=to_string(num);
        for(int i=0;i<s.length();i++) ret.push_back(s[i]-'0');
        return ret;
    }
};

//2.�Ӻ���ǰ��,�Ժ��� 
class Solution1 {
public:
    vector<int> plusOne(vector<int>& digits) {
        string s;
        int len=digits.size();
        if(digits[len-1]<9){
        	digits[len-1]+=1;
        	return digits;
		}
		int a=1;
        for(int i=len-1;i>=0;i--){
        	if(digits[i]==9&&a==1){
        		 digits[i]=0;
        		 a=1;
			}
			else a=0;
		}
    }
};

//3. �Ӻ���ǰһ�α������ҵ���һ����Ϊ9������
class Solution2{
public:
	vector<int> plusOne(vector<int>& digits){
		int len=digits.size();
		for(int i=len-1;i>=0;i--){
			//�ҵ���һ����Ϊ9��������1���������ȫΪ0
			if(digits[i]!=9){
				digits[i]+=1;
				for(int j=i+1;j<len;j++) digits[j]=0;
				return digits;
			} 
		}
		vector<int> ans(len,0);
		ans.insert(ans.begin(),1);
		return ans;
	}
}; 

//4.���ǽ�λ
/*javaʵ�֣�
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        for(int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if(digits[i]!=0)
                return digits;
        }
        digits = new int[len + 1];
        digits[0] = 1;
        return digits;
    }
}

���ߣ�guanpengchn
���ӣ�https://leetcode-cn.com/problems/plus-one/solution/hua-jie-suan-fa-66-jia-yi-by-guanpengchn/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/ 
