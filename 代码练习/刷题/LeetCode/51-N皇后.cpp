//51-N»Êºó
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
class Solution {
public:
	void search(int n, int r, vector<string> &v, vector<vector<string>> &vv, vector<int> &forward,
 vector<int> &backward, vector<int> &columns)
    {
        if (r == n)
            vv.push_back(v);
        for (int c = 0; c < n; c++)
        {
            if (!forward[c + r] && !backward[r + n - c - 1] && !columns[c])
            {
                v[r][c] = 'Q';
                forward[c + r] = backward[r + n - c - 1] = columns[c] = 1;
                search(n, r + 1, v, vv, forward, backward, columns);
                forward[c + r] = backward[r + n - c - 1] = columns[c] = 0;
                v[r][c] = '.';
            }
        }
    }
	vector<vector<string>> solveNQueens(int n){ 
		vector<int> forward(2*n),backward(2*n),columns(n); 
		vector<vector<string>> vv;
        vector<string> v(n, string(n, '.'));
        search(n, 0, v, vv, forward, backward, columns);
        return vv;
	} 
};
