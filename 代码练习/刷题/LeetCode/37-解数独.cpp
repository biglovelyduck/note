//37-解数独
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
//回溯 
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0);		
    }
    bool dfs(vector<vector<char>> &board,int n){		//n取值0~80 
    	if(n>=81) return true;
    	int row=n/9,col=n%9;
    	if(board[row][col]!='.') return dfs(board,n+1);//找下一个点
		for(char k='1';k<='9';++k){
			if(check(board,row,col,k)){					//k是要填入的试探的字符且合法 
				char c=board[row][col];					//保存上一个字符 
				board[row][col]=k;
				if(dfs(board,n+1)) return true;
				board[row][col]=c;
			}
		} 
		return false; 
	}
	bool check(vector<vector<char>>& board, int i, int j, char k) {
        for (int row = 0; row < 9; ++row) if (board[row][j] == k) return false;
        for (int col = 0; col < 9; ++col) if (board[i][col] == k) return false;
        int x = i / 3 * 3,y = j / 3 * 3;
        for (int row = x; row < x + 3; ++row)
            for (int col = y; col < y + 3; ++col) if (board[row][col] == k) return false;
        return true;
    }
}; 
