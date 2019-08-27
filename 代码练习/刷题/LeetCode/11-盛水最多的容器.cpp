//11-ʢˮ�������� 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
using namespace std; 
//1.�ҵ�д������˫ָ�룬��ʱ������ 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int MaxArea=0;
        int len=height.size();
        //cout<<len<<endl;
		for(int i=0;i<len;i++){
			for(int j=len-1;j>i;j--){
				int lowHeight=min(height[i],height[j]);
				//cout<<"low:"<<lowHeight<<" "<<"i:"<<i<<" j:"<<j<<endl;;
				int area=lowHeight*(j-i);
				MaxArea=max(area,MaxArea);
			}
		} 
		return MaxArea;
    }
};
//��ȷ˫ָ��
class Solution1{
public:
	int maxArea(vector<int>& v){
		int maxarea=0,l=0,r=v.size()-1;
		while(l<r){
			maxarea=max(maxarea,min(v[l],v[r])*(r-l));
			if(v[l]<v[r])	l++;
			else r--;
		}
		return maxarea;
	}
}; 
int main(){
	Solution s;
	vector<int> v={1,8,6,2,5,4,8,3,7};
	cout<<s.maxArea(v);
	return 0;
}
