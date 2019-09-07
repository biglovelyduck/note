//29-�������
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
//�����Եݹ飬ջ����� 
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
    	//�����������߶��Ǹ��� 
    	if((dividend>0&&divisor>0)||(dividend<0&&divisor<0)){ 
			return (divide_long(abs_dividend-abs_divisor,abs_divisor)+1)>INT_MAX?INT_MAX:
											divide_long(abs_dividend-abs_divisor,abs_divisor)+1;
        }
		//һ��һ��
		else{			
			return -(divide_long(abs_dividend-abs_divisor,abs_divisor)+1)<INT_MIN?INT_MAX:
										-(divide_long(abs_dividend-abs_divisor,abs_divisor)+1);
		} 	
	}
};

//�˼�д��
int divide(int dividend, int divisor) {
        
    if (dividend == 0) return 0;
    
    //  ת��Ϊlong long�ͼ��㣬��ֹ INT32_MIN / -1 ���
    long long lldividend = dividend, lldivisor = divisor;
    long long cur_bit = 1, result = 0;
    
    //  ת��Ϊ�������㣬����жϷ���
    lldividend = abs(lldividend);
    lldivisor = abs(lldivisor);
    
    //  �Ƚ��������Ŵ� cur_bit ��
    //  ����Ҫ��֤������ <= ����
    while (lldividend >= lldivisor << 1) {
        lldivisor <<= 1;
        cur_bit <<= 1;
    }
    
    //  �������μ�ȥ�������� cur_bit ��
    //  ���� cur_bit ѭ��ִ�м���
    //  ֱ�� ����Ϊ 0 ���� cur_bit == 0
    while (cur_bit > 0 && lldividend > 0) {
        if (lldividend >= lldivisor) {
            lldividend -= lldivisor;
            result += cur_bit;
        }
        cur_bit >>= 1;
        lldivisor >>= 1;
    }
    
    //  �ж� result ����
    result = (dividend > 0 && divisor < 0 || 
              dividend < 0 && divisor > 0) ? - result : result;
    
    //  �ж��Ƿ������������ؽ��
    if (result > INT32_MAX) return INT32_MAX;
    return (int) result;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
        // ����
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
