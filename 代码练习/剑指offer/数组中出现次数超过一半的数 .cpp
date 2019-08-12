//数组中出现次数超过一半的数 
#include <vector>
#include <algorithm>
using namespace std;
//1.快排思想 
/*
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        // 因为用到了sort，时间复杂度O(NlogN)，并非最优
        if(numbers.empty()) return 0;
         
        sort(numbers.begin(),numbers.end()); // 排序，取数组中间那个数
        int middle = numbers[numbers.size()/2];
         
        int count=0; // 出现次数
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==middle) ++count;
        }
         
        return (count>numbers.size()/2) ? middle :  0;
    }
};*/
//2.数组性质
class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers){
		if(numbers.empty()) return 0;
		int len=numbers.size();
		int result=numbers[0];
		int times=1;
		for(int i=1;i<len;i++){
			if(times==0){
				result=numbers[i];
				times=1;
			}
			else if(numbers[i]==result) times++;
			else	times--;
		}
		//verify
		times=0;
		for(int i=0;i<len;i++){
			if(numbers[i]==result) times++;
		}
		return times*2>len?result:0;
	}
}; 
