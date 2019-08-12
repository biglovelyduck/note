//数值的整数次方 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool is_false=false;
	bool is_negative=false;
    double Power(double base, int exponent) {
    	if(base==0.0&&exponent<0){
    		is_false=true;
    		return 0.0;
		}
		if(exponent<0){
			is_negative=true;
			exponent=-exponent;
		} 
		double result=PoweWithUnsignedExponent(base,exponent); 
		if(is_negative) result=1.0/result; 
    	return result;
	}
    double PoweWithUnsignedExponent(double base,int exponent){
    	if(exponent==0) return 1;
    	if(exponent==1) return base;
    	double result=PoweWithUnsignedExponent(base,exponent>>1);
    	result*=result;
    	if(exponent&1==1) result*=base;
    	return result;
	}
};
