#include <vector>
using namespace std;
//二维数组中的查找
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        bool find=false;
        if(array.size()==0) return false;
        for(int i=0;i<array.size();i++)
        	if(array[i].size()==0) return false;
        int row=0;
        int columns=array[0].size();
        int rows=array.size();
        int column=columns-1;
        while(row<rows&&column>=0){
        	//每次拿出右上角的点来比较
			if(array[row][column]==target){
				find=true;
				break;
			} 
			else if(array[row][column]>target)
				--column;
			else
				++row;
		}
		return find;
    }
}; 
