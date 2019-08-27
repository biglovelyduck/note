//9-回文数 
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
//1.聪明解法 
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0)) return false;
		int reverseNum=0;
		while(x>reverseNum){
			reverseNum=reverseNum*10+x%10;
			x/=10;
		}
		return x==reverseNum||x==reverseNum/10;
    }
};
//2.字符串解法
class Solution1 {
public:
    bool isPalindrome(int x) {
        long rev;
        if(x<0) return false;
        string str_x=to_string(x);
        std::reverse(str_x.begin(),str_x.end());
        stringstream out(str_x);
        out>>rev;
        return x==rev;
    }
}; 

//3.使用栈
class Solution{
public:
	int get_length(int x){
		int len=0;
		while(x){
			x/=10;
			len++;
		}
		reurn len;
		bool isPalindrome(int x) {
        if(x<0 ||(x%10==0&&x!=0)) return false;
        stack<int> mystack;//创建一个栈
        int l=get_length(x);//存放整数位数
        int p=0;//存放弹出的数据
        if(l%2==0)//偶数位操作
        {
            for(int i=0;i<l/2;i++)
            {
                p=x%10;
                x/=10;
                mystack.push(p);
            }
            for(int j=l/2;j<l;j++)
            {
                p=x%10;
                x/=10;
                if(p==mystack.top())
                {
                    mystack.pop();
                    continue;
                }
                else return false;
            }
            return true;
        }
        else//奇数位操作
        {
            for(int i=0;i<=l/2;i++)
            {
                p=x%10;
                x/=10;
                mystack.push(p);
            }
            mystack.pop();
            for(int j=l/2+1;j<l;j++)
            {
                p=x%10;
                x/=10;
                if(p==mystack.top())
                {
                    mystack.pop();
                    continue;
                }
                else return false;
            }
            return true;
        }
    }
	}
}; 
int main(){
//	int m;
//	cin>>m;
//	int n;
//	Solution s;
//	while(m--){
//		cin>>n;
//		cout<<s.isPalindrome(n)<<endl;
//	}
	Solution1 s;
	int m;
	cin>>m;
	while(m--){
		int n;
		cin>>n;
		s.isPalindrome(n);
	}
}
