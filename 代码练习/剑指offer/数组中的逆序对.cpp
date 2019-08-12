//数组中的逆序对
#include <iostream>
#include <vector>
using namespace std;
class AntiOrder {
public:
    int count(vector<int> A, int n) {
        // write code here
        if(A.empty()||n<=0) return 0;
        vector<int> copy;
        for(int i=0;i<A.size();i++)
        	copy[i]=A[i];
        int count=InversePairsCore(A,copy,0,n-1);
        return count;
    }
    int InversePairsCore(vector<int>& data,vector<int>& copy,int start,int end){
    	if(start==end){
    		copy[start]=data[start];
    		return 0;
		}
		int length=(end-start)/2;
		int left=InversePairsCore(data,copy,start,start+length);
		int right=InversePairsCore(data,copy,start+length+1,end);
		
		//i初始化为前一段的最后一个数字的下标
		int i=start+length;
		//j 初始化为后一段的最后一个数字的下标
		int j=end;
		int indexCopy=end;
		int count=0;
		while(i>=start&&j>=start+length+1){
			if(data[i]>data[j]){
				copy[indexCopy--]=data[i--];
				count+=j-start-length;
			}
			else{
				copy[indexCopy--]=data[j--];
			}
		}
		for(;i>=start;i--)
			copy[indexCopy--]=data[i];
		for(;j>=start+length+1;j--)
			copy[indexCopy--]=data[j];
		
		return left+right+count; 
	}
}; 
