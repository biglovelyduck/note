//��������1�ĸ��� 
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
     
     //��ţ�ƽⷨ
	 int NumberOf1(int n){
	 	int count=0;
	 	while(n){
	 		++count;
	 		n=(n-1)&n;
		 }
		 return count;
	 } 
};
