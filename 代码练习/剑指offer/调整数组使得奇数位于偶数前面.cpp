//调整数组使得奇数位于偶数前面
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size()==0) return;
        //把偶数删除后尾插进来
        vector<int>::iterator even=array.begin();
		int size=array.size();
		while(size){
			if(*even%2==0){
				int temp=*even;
				even=array.erase(even);
				array.push_back(temp);
			}
			else{
				even++;
			}
			size--;
		} 
    }
}; 
int main(){
	int a[7]={1,2,3,4,5,6,7};
	vector<int> v(a,a+7);
	Solution s;
	s.reOrderArray(v);
	for(int i=0;i<7;i++)
		cout<<v[i]<<" ";
	return 0;
}
