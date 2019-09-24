//奇安信-结束进程树 
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
const int MAX_N=101;
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        queue<int> q{{kill}};
        map<int, vector<int>> m;
        for (int i = 0; i < pid.size(); ++i) {
            m[ppid[i]].push_back(pid[i]);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            res.push_back(t);
            for (int p : m[t]) {
                q.push(p);
            }
        }
        return res;
    }
};

int main(){
	Solution s;
	vector<int> pid,ppid; 
	int num;
	while(true){
		cin>>num;
		pid.push_back(num);
		if(cin.get()=='\n') break;
	} 
	while(true){
		cin>>num;
		ppid.push_back(num);
		if(cin.get()=='\n') break;
	}
	int kill;
	cin>>kill;
	cout<<s.killProcess(pid,ppid,kill).size();	
	return 0;
}
