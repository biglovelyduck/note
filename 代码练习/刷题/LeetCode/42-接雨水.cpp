//42-����ˮ
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

//1.��������������ÿ��ˮλ���ҵ�����������ӽ�С�Ǹ� 
class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int size=height.size();
        for(int i=1;i<size-1;i++){
        	int max_left=0,max_right=0;
        	//search the left part for max bar size
        	for(int j=i;j>=0;j--) max_left=max(max_left,height[j]);
        	//search the right part for max bar size
        	for(int j=i;j<size;j++) max_right=max(max_right,height[j]);
        	ans+=min(max_left,max_right)-height[i];
		}
		return ans;
    }
};

//2.�ڱ����У����ǽ���Ϊ���ҵ����ֵ���Ҷ�Ҫɨ��һ�Σ��������ǿ�����ǰ�洢���ֵ
//��̬���
class Solution1 {
public:
    int trap(vector<int>& height) {
        //if(height==null) return 0;
        if(height.size()==0) return 0;
        int ans=0;
        int size=height.size();
        vector<int> left_max(size),right_max(size);
        left_max[0]=height[0];
		for(int i=1;i<size;i++) left_max[i]=max(height[i],left_max[i-1]);
		right_max[size-1]=height[size-1];
		for(int i=size-2;i>=0;i--) right_max[i]=max(height[i],right_max[i+1]); 
		for(int i=1;i<size-1;i++) ans+=min(left_max[i],right_max[i])-height[i];
		return ans;
    }
}; 

//3.ջ 
/*�����ڱ�������ʱά��һ��ջ�������ǰ�����ο�С�ڻ����ջ�������ο飬
���ǽ����ο��������ջ����˼�ǵ�ǰ�����ο鱻ջ�е�ǰһ�����ο�綨����
�����Ƿ���һ�����ο鳤��ջ�������ǿ���ȷ��ջ�������ο鱻��ǰ���ο��ջ��ǰһ�����ο�綨��
������ǿ��Ե���ջ��Ԫ�ز����ۼӴ𰸵� \text{ans}ans ��
*/ 
class Solution3 {
public:
    int trap(vector<int>& height) {
        //if(height==null) return 0;
        if(height.size()==0) return 0;
        stack<int> st;
        int ans=0,current=0;
        while(current<height.size()){
        	while(!st.empty()&&height[current]>height[st.top()]){
        		int top=st.top();
        		st.pop();				//����ջ��Ԫ�� 
        		if(st.empty()) break;
				int distance=current-st.top()-1;
				//���޶���Ԫ�ص�ջ��Ԫ�غ�current�Ƚ� 
				int  bounded_height=min(height[current],height[st.top()])-height[top];
				ans+=distance*bound_height;
			}
			st.push(current++);
		}
		return ans;
    }
};

//4.˫ָ�� 
class Solution4{
public:
	int trap(vector<int>& height){
		int left=0,right=height.size()-1;
		int ans=0;
		int left_max=0,right_max=0;
		while(left<right){
			if(height[left]<height[right]){
				height[left]>=left_max?(left_max = height[left]) : ans += (left_max - height[left]);
	            ++left;
	        }
	        else {
	            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
	            --right;
	        }
	    }
	    return ans;
		}
	}
};

int main(){
	return 0;
} 
