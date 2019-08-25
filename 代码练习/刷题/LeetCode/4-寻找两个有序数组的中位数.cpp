//4-寻找两个有序数组的中位数
#include <algorithm> 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
const int MAX_N=1000;
//1.归并 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int i=0,j=0,index=0,s1=nums1.size(),s2=nums2.size();
        vector<int> v(s1+s2,0);
        while(i!=s1&&j!=s2){
        	if(nums1[i]<=nums2[j])	v[index++]=nums1[i++];
        	else v[index++]=nums2[j++];
		}
		while(i!=s1)	v[index++]=nums1[i++];
		while(j!=s2)	v[index++]=nums2[j++];
		if((s1+s2)%2==0)	return (double)(v[(s1+s2)/2-1]+v[(s1+s2)/2])/2.0;
    	return v[(s1+s2)/2];
    }
   
}; 

//2.归并，不开辟辅助内存
class Solution1{
public:
	double findMedianSortedArrays(vector<int> &nums1,vector<int> &nums2){
		int i=0,j=0,s1=nums1.size(),s2=nums2.size();
		int end1=(s1+s2-1)/2;	//奇数的中位数的位置
		int end2=(s1+s2)%2?-1:(s1+s2)/2;
		int begin=0;
		int num1,num2;
		while(i!=s1&&j!=s2){
			if(begin==end1){
				num1=nums1[i]<nums2[j]?nums1[i]:nums2[j];
				if(end2==-1) return num1;
			}
			if(begin==end2){
				num2=nums1[i]<nums2[j]?nums1[i]:nums2[j];
				return (double)(num1+num2)/2;
			}
			if(nums2[i]<nums2[j])	i++;
			else j++;
			begin++;
		} 
		//遍历完了其中某一个数组，但是还没有到中位数 
		while(i!=s1){
			if(begin==end1){
				num1=nums1[i];
				if(end2==-1)
					return num1;
			}
			if(begin==end2){
				num2=nums1[i];
				return (double)(num1+num2)/2;
			} 
			i++;
			begin++;
		}
		while(j!=s2){
			if(begin==end1){
				num1=nums2[j];
				if(end2=-1)
					return num1;
			}
			if(begin==end2){
				num2=nums2[j];
				return (double)(num1+num2)/2;
			}
			j++;
			begin++;
		}
	}
}; 

//3.二分
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int sz = nums1.size() + nums2.size();
        int sz1l = 0,sz1r = nums1.size();
        int sz1 = 0,sz2 = 0;
        while(sz1 <= nums1.size()){
            sz1 = (sz1l + sz1r) / 2;
            sz2 = sz / 2 - sz1; 
            int l1 = sz1 == 0 ? INT_MIN : nums1[sz1 - 1];
            int r1 = sz1 == nums1.size() ? INT_MAX : nums1[sz1];
            int l2 = sz2 == 0 ? INT_MIN : nums2[sz2 - 1];
            int r2 = sz2 == nums2.size() ? INT_MAX : nums2[sz2];
            if(l1 > r2)
                sz1r = sz1 - 1;
            else if(l2  > r1)
                sz1l = sz1 + 1;
            else{
                if(sz % 2 == 0){
                    l1 = l1 > l2 ? l1 : l2;
                    r1 = r1 < r2 ? r1 : r2;
                    return (double)(l1 + r1) / 2;
                }
                else{
                    r1 = r1 < r2 ? r1 : r2;
                    return r1;
                }
            }
                
        }
        
     
