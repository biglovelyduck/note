//69-x的平方根
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
//1.库函数 
class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x); 
    }
}; 

//2.二分搜索 
class Solution1 {
public:
    int mySqrt(int x) {
        long long left=0,right=x;
		while(left<=right){
			long long mid=(left+right)/2;
			long long res=mid*mid;
			if(res==x) return mid;
			else if(res>x) right=mid-1;
			else left=mid+1;
			
			cout<<"left:"<<left<<" right:"<<right<<endl;
		} 
		return right;
    }
};

int main(){
	Solution1 s1;
	cout<<s1.mySqrt(4);
	return 0;
}
