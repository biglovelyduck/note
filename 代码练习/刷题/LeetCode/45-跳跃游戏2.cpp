//45-��Ծ��Ϸ2
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
//1.��̬�滮1 
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

//2.˳�����ϣ�̰��,ÿ���ڿ�����Χ��ѡ���Զ��λ�� 
class Solution1{
public:
	int jump(vector<int> &nums){
		int end=0;	//��ʾ��ǰ�����ı߽�
		int maxPosition=0;
		int steps=0;
		for(int i=0;i<nums.size()-1;i++){
			//�ҵ���������Զ��
			maxPosition=max(maxPosition,nums[i]+i);
			if(i==end){
				//�����߽�͸��±߽粢�Ҳ���+1
				end=maxPosition;
				steps++; 
			} 
		} 
		return steps;
	}
}; 

//3.˳������,�Ӻ���ǰ�� ,��ʱ 
class Solution2{
public:
	int jump(vector<int> &nums){
		int position=nums.size()-1;	//Ҫ�ҵ�λ��
		int steps=0;
		while(position!=0){			//�Ƿ��˵�0��λ�� 
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

//4.��̬�滮2 
/*��d[i]��ʾ��λ��0����λ��i��������Ծ������

��λ��i������λ������S=[i+1,i+nums[i]]����d[i] + 1����λ������S�е�dֵ��

���Ǹ�O(N^2)���㷨��
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

