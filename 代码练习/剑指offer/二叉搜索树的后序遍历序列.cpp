//二叉搜索树的后序遍历序列 
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
//递归解法 
class Solution {
public:
	bool judge(vector<int>& a,int l,int r){
		if(l>=r) return true;
		int i=r;
		while(i>l&&a[i-1]>a[r]) --i;
		//i跳出循环的位置就是左子树的最右边+1
		for(int j=i-1;j>=l;--j) if(a[j]>a[r]) return false;
		return judge(a,l,i-1)&&judge(a,i,r-1);
	}
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.size()==0) return false;
		return judge(sequence,0,sequence.size()-1);
    }
};
*/

//非递归解法
class Solution{
	public:
		bool VerifySquenceOfBST(vector<int> v){
			int size=v.size();
			if(0==size) return false;
			int i=0;
			while(--size){
				while(v[i++]<v[size]);
				while(v[i++]>v[size]); 
				if(size>i) return false;
				i=0;
			} 
			return true;
		}
}; 
