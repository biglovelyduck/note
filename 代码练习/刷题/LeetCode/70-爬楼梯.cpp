//70-爬楼梯
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
//1.我的解法 ,超时 ，递归 
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        return climbStairs(n-1)+climbStairs(n-2); 
    }
};

//2.自底向上的DP
class Solution1{
public:
	int climbStairs(int n){
		long dp[n+1];
		dp[0]=1,dp[1]=2;
		for(int i=2;i<=n;i++){
			dp[i]=dp[i-1]+dp[i-2];
		}
		return dp[n-1];
	}
}; 

 
