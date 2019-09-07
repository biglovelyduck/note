//5070. 与目标颜色间的最短距离
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
using namespace std;
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int> >& queries) {
    	vector<int> v;
    	bool find_left=false;
    	bool find_right=false;
    	//遍历查询每一个操作 
        for(int i=0;i<queries.size();i++){
        	find_left=false;
        	find_right=false;
        	int index=queries[i][0];
        	int color=queries[i][1];
        	//cout<<"index:"<<index<<" color:"<<color<<endl;
        	if(find(colors.begin(),colors.end(),color)==colors.end()){
        		 v.push_back(-1);	//cout<<"没找到"<<endl;
        		 continue;
			}
			//走到这说明肯定是可以找到的 
        	int left=index,right=index;
        	int Min=-1; 
        	//先向左找 
        	while(left){
        		if(colors[left]==color){
        			find_left=true;
        			break;
				};
        		left--;
			}
			while(right<colors.size()){
				if(colors[right]==color){
					find_right=true;
					break;
				}
				right++;
			}
			if(find_left&&find_right){
				Min=min(index-left,right-index);
			}
			else if(find_left){
				Min=index-left;
			}
			else{
				Min=right-index;
			}
			v.push_back(Min);
		}
		return v;
    }
};

int main(){
	Solution s;
	vector<int> colors={1,2};
	vector<vector<int> > queries={{0,3}};
	vector<int> v=s.shortestDistanceColor(colors,queries);
	for(auto i:v)
		cout<<i<<" ";
	return 0;
}
