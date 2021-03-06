#include <iostream>
#include <functional> 
using namespace std; 
//数组中1~n中含有数字1出现的次数 
class Solution {
public:
    int powerbase10(unsigned int n){
        int res = 1;
        while(n){
            res *= 10;
            n--;
        }
        return res;
    }
    
    int NumberOf1Between1AndN(const string &str,int index){
	    if(str.size() == 0)    return 0;
	    ////遍历到最后一位  
	    if(index == static_cast<int>(str.size()) - 1){
	        if(str[index] == '0')
	            return 0;
	        return 1;
	    }
	
	    if(stoi(str.substr(index)) == 0)	//右边全是0 
	        return 0;
	
	    int count1,countOther;
	    int length = str.size() - index;
	    int firstDigit = str[index] - '0';	//最高位数字 
		//计算第一段 
	    if(firstDigit == 1)
	        count1 = stoi(str.substr(index + 1)) + 1;
	    else//大于1
	        count1 = powerbase10(length - 1);
	
	    countOther = firstDigit * (length - 1) * powerbase10(length - 2);
	    int countRecursive = NumberOf1Between1AndN(str,index + 1);
	
	    return count1 + countOther + countRecursive;
}
    
    int NumberOf1Between1AndN_Solution(int n)
    {
        string s = to_string(n);	//转换为string 
        
        return NumberOf1Between1AndN(s,0);
    }
};
