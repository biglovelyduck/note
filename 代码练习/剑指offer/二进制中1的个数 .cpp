//二进制中1的个数 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	/*
     int  NumberOf1(int n) {
         int count=0;
         while(n){
         	if(n&1) count++;
         	n>>=1;
		 }
		 return count;
     }*/
     
     //最牛逼解法
	 int NumberOf1(int n){
	 	int count=0;
	 	while(n){
	 		++count;
	 		n=(n-1)&n;
		 }
		 return count;
	 } 
};
