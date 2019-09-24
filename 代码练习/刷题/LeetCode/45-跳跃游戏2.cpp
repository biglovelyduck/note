//45-跳跃游戏2
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
//1.动态规划1 
class Solution {
public:
    int jump(vector<int>& nums) {
        const int N=nums.size();
        if(N<=1) return 0;
        vector<int> d(N,0);
        for(int i=1;i<N;i++){
        	int &ans=d[i];
        	ans=INT_MAX;
        	for(int j=0;j<i;j++){
        		if(j+nums[j]>=i) ans=min(ans,d[j]+1);
			}
		}
		return d[N-1];
    }
}; 

//2.顺藤摸瓜，贪婪,每次在可跳范围内选择更远的位置 
class Solution1{
public:
	int jump(vector<int> &nums){
		int end=0;	//表示当前能跳的边界
		int maxPosition=0;
		int steps=0;
		for(int i=0;i<nums.size()-1;i++){
			//找到能跳的最远的
			maxPosition=max(maxPosition,nums[i]+i);
			if(i==end){
				//遇到边界就更新边界并且步数+1
				end=maxPosition;
				steps++; 
			} 
		} 
		return steps;
	}
}; 

//3.顺藤摸瓜,从后往前找 ,超时 
class Solution2{
public:
	int jump(vector<int> &nums){
		int position=nums.size()-1;	//要找的位置
		int steps=0;
		while(position!=0){			//是否到了第0个位置 
			for(int i=0;i<position;i++){
				if(i+nums[i]>=position){
					position=i;
					steps++;
					break;
				}
			}
		} 
		return steps;
	}
}; 

//4.动态规划2 
/*设d[i]表示从位置0跳到位置i的最少跳跃次数。

从位置i能跳到位置区间S=[i+1,i+nums[i]]。用d[i] + 1更新位置区间S中的d值。

这是个O(N^2)的算法。
*/
class Solution3{
public:
	int jump(vector<int> &nums){
		const int N=nums.size();
		if(N<=1) return 0;
		vector<int> d(N+1,INT_MAX);
		d[0]=0;
		for(int i=0;i<N;++i){
			for(int j=i+1;j<=min(i+nums[i],N-1);++j){
				int &ans=d[j];
				ans=min(ans,d[j]+1); 
			}
		}
		return d[N-1];
	}
};

//5.DFS
class Solution4{
public:
	int jump(vector<int>& nums){
		const int N=nums.size();
		if(N<=1) return 0;
		vector<int> d(N+1,INT_MAX);
		d[0]=0;
		dfs(nums,d,0);
		return d[N-1];
	}
	void dfs(const vector<int>& A,vector<int> &d,int p){
		if(d[p] + 1 >= d[A.size() - 1]) return;
		for(int j=min((int)A.size()-1,p+A[p]);j>=p+1;--j){
            int& ans = d[j];
            if(d[p] + 1 >= d[A.size() - 1]) break;
            if(d[p] + 1 < ans){
                ans = d[p] + 1;
                if(ans + 1 < d[A.size() - 1]){
                    dfs(A,d,j);
                }
            }
        }
	}
};

//6.BFS
class Solution5{
public:
	    typedef pair<int,int> Pair;
    int jump(vector<int>& nums) {
        const int N = nums.size();
        if(N <= 1) return 0;
        vector<int> vis(N,0);
        queue<Pair> Q;
        Q.push(make_pair(0,0));
        vis[0] = 1;
        while(Q.size()){
            Pair cur=Q.front();Q.pop();
            if(cur.first == N - 1) return cur.second;
            for(int i = min(cur.first + nums[cur.first], N-1); i >= cur.first + 1; --i){
                if(!vis[i]){
                    if(i == N - 1) return cur.second + 1;
                    vis[i] = 1;
                    Q.push(make_pair(i,cur.second+1));
                }
            }
        }
        return -1;
    }
};

