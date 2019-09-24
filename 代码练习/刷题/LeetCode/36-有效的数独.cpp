//36-有效的数独 
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
//一次迭代,使用三个哈希表rows,columns,boxes 
//box_index = (row / 3) * 3 + columns / 3
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<int,int> > rows(9),columns(9),boxes(9);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				char num=board[i][j];		//每个字符
				if(num!='.'){
					int n=num-'0';
					int box_index=(i/3)*3+j/3;
					
					//每一个数组元素都是一个map 
					rows[i][n]++;
					columns[j][n]++;
					boxes[box_index][n]++;
					
					//检查
					if(rows[i][n]>1||columns[j][n]>1||boxes[box_index][n]>1) return false;
				} 
			}
		}
		return true; 
    }
};

//int main(){
//	Solution s;
//	vector<vector<char>> board={ {"5","3",".",".","7",".",".",".","."},
//  {"6",".",".","1","9","5",".",".","."
//  },
//  {".","9","8",".",".",".",".","6","."
//  },
//  {"8",".",".",".","6",".",".",".","3"
//  },
//  {"4",".",".","8",".","3",".",".","1"
//  },
//  {"7",".",".",".","2",".",".",".","6"
//  },
//  {".","6",".",".",".",".","2","8","."
//  },
//  {".",".",".","4","1","9",".",".","5"
//  },
//  {".",".",".",".","8",".",".","7","9"}
//};
//	cout<<s.isValidSudoku(board);
//	return 0;
//}

//分为三部分判断,行列框
class Solution1{
public:
	bool isValidSudoku(vector<vector<char> > board){
		for(int i=0;i<81;i++){
			if(!checkOnePos(board,i)) return false;
		}
		return true;
	}
	bool checkOnePos(vector<vector<char>> board,int pos){
		int row=pos/9,col=pos%9;
		if(board[row][col]=='.') return true;
		
		for(int i=0;i<9;i++){			//遍历当前位置的每列 
			if(i==col) continue;
			if(board[row][i]==board[row][col]) return false;
		}
		
		for(int i=0;i<9;i++){			//遍历当前位置的每行 
			if(i==row) continue;
			if(board[i][col]==board[row][col]) return false;
		} 
		
		int boxR=row/3,boxC=col/3;
		for(int i=3*boxR;i<3*boxR+3;i++){
			for(int j=3*boxC;j<3*boxC+3;j++){
				if(i==row&&j==col) continue;
				if(board[i][j]==board[row][col]) return false;
			}
		}
		
		return true;
	}
}; 

//使用bitset
class Solution2
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        char k;
        int num;
        bitset<9> hang;
        vector<bitset<9>> lie(9, hang), box(9, hang);
        for (int i = 0; i < 9; ++i) //行
        {
            for (int j = 0; j < 9; ++j) //列
            {
                k = board[i][j];
                if (k != '.')
                {
                    num = k - '0' - 1;
                    if (hang[num] == 0 && lie[j][num] == 0 && box[i / 3 * 3 + j / 3][num] == 0)
                        hang[num] = lie[j][num] = box[i / 3 * 3 + j / 3][num] = 1;
                    else
                        return 0;
                }
            }
            hang.reset();
        }
        return 1;
    }
};

