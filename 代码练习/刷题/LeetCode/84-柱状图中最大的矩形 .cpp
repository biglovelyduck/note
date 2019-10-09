//84-柱状图中最大的矩形 
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
#include <regex>
#include <unordered_map>
using namespace std;
//暴力超时 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	int ans=0;
        for(int i=0;i<heights.size();i++){
        	int left=i-1,right=i+1;
        	while(left>=0&&heights[left]>=heights[i]) left--;
        	while(right<heights.size()&&heights[right]>=heights[i]) right++;
        	int len=right-left-1;
        	int area=len*heights[i];
        	if(area>ans) ans=area;
		}
		return ans;
    }
};

/*枚举所有的柱子对， 
public class Solution {
   public int largestRectangleArea(int[] heights) {
       int maxarea = 0;
       for (int i = 0; i < heights.length; i++) {
           int minheight = Integer.MAX_VALUE;
           for (int j = i; j < heights.length; j++) {
               minheight = Math.min(minheight, heights[j]);
               maxarea = Math.max(maxarea, minheight * (j - i + 1));
           }
       }
       return maxarea;
   }
}
*/

//分治
class Solution1{
public:
	int calc(vector<int> &heights,int start,int end){
		if(start>end) return 0;
		int minindex=start;
		for(int i=start;i<=end;i++)
			if(heights[minindex]>heights[i]) minindex=i;
		return max(heights[minindex]*(end-start+1),
				max(calc(heights,start,minindex-1),calc(heights,minindex+1,end))
				);
	}
	int largestRectangleArea(vector<int>& heights){
		return calc(heights,0,heights.size()-1);
	}
}; 

//滑动窗口
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        if (heights.size() == 1)
            return heights[0];
        int res = heights[0];
        int i = 1;
        while (i < heights.size()) {
            if (i < heights.size() - 1 && heights[i + 1] >= heights[i]) {
                ++i;
                continue;
            }
            int prev_height = heights[i];
            for (int j = i; j >= 0 && heights[j] > 0; --j) {
                if (heights[j] < prev_height)
                    prev_height = heights[j];
                if (prev_height * (i - j + 1) > res)
                    res = prev_height * (i - j + 1);
            }
            ++i;
        }
        return res;
    }
};
 
