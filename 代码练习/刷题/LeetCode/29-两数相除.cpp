//29-两数相除
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
//不可以递归，栈会溢出 
class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor==0) return INT_MAX;
    	return divide_long(dividend,divisor);	
    }
    
    int divide_long(long long dividend,long long divisor){
    	if(divisor==0) return INT_MAX;
    	long long abs_dividend=abs(dividend);
		long long abs_divisor=abs(divisor);
		if(abs_dividend<abs_divisor) return 0;
    	//都是正数或者都是负数 
    	if((dividend>0&&divisor>0)||(dividend<0&&divisor<0)){ 
			return (divide_long(abs_dividend-abs_divisor,abs_divisor)+1)>INT_MAX?INT_MAX:
											divide_long(abs_dividend-abs_divisor,abs_divisor)+1;
        }
		//一正一负
		else{			
			return -(divide_long(abs_dividend-abs_divisor,abs_divisor)+1)<INT_MIN?INT_MAX:
										-(divide_long(abs_dividend-abs_divisor,abs_divisor)+1);
		} 	
	}
};

//人家写的
int divide(int dividend, int divisor) {
        
    if (dividend == 0) return 0;
    
    //  转换为long long型计算，防止 INT32_MIN / -1 溢出
    long long lldividend = dividend, lldivisor = divisor;
    long long cur_bit = 1, result = 0;
    
    //  转换为整数计算，最后判断符号
    lldividend = abs(lldividend);
    lldivisor = abs(lldivisor);
    
    //  先将被除数放大 cur_bit 倍
    //  但是要保证被除数 <= 除数
    while (lldividend >= lldivisor << 1) {
        lldivisor <<= 1;
        cur_bit <<= 1;
    }
    
    //  除数依次减去被除数的 cur_bit 倍
    //  右移 cur_bit 循环执行减法
    //  直到 除数为 0 或者 cur_bit == 0
    while (cur_bit > 0 && lldividend > 0) {
        if (lldividend >= lldivisor) {
            lldividend -= lldivisor;
            result += cur_bit;
        }
        cur_bit >>= 1;
        lldivisor >>= 1;
    }
    
    //  判断 result 符号
    result = (dividend > 0 && divisor < 0 || 
              dividend < 0 && divisor > 0) ? - result : result;
    
    //  判断是否会溢出，并返回结果
    if (result > INT32_MAX) return INT32_MAX;
    return (int) result;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 特判
        if (divisor == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int signdiff = (dividend > 0) ^ (divisor >0);
        
        long t = abs((long)dividend);
        long d = abs((long)divisor);
        int result = 0;
        
        for (int i = 31; i >= 0; i --){
            if ((t >> i) >= d){
                result += 1 << i;
                t -= d << i;
            }
        }
        return signdiff ? -result : result;
    }
};

int main(){
	Solution s;
	cout<<s.divide(-100,-1);
	return 0;
} 
