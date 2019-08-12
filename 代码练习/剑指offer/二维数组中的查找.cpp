#include <vector>
using namespace std;
//��ά�����еĲ���
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
        	//ÿ���ó����Ͻǵĵ����Ƚ�
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
