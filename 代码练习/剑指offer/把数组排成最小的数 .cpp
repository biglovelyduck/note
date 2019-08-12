//把数组排成最小的数 
/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*内存超限。。。 
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
		string s="";
		if(numbers.size()<=0) return "";
		for(int i:numbers){
			s+=to_string(i);
		}
		vector<string> v=getPermutation(s);
		sort(v.begin(),v.end());
		return v[0];
    }
    vector<string> getPermutation(string A) {
        vector<string> res;
        if(A.size() == 0)
            return res;
        permutation(A, res, 0);
        sort(res.begin(), res.end(), greater<string>());//排序
        return res;
    }
 
    void permutation(string A, vector<string>& res, int cur){
        int len = A.size();
        if(cur == len -1){//到最后一个字符，就插入结果
            res.push_back(A);
            return;
        }
        for(int i = cur; i < len; ++i){
            swap(A[i], A[cur]);//交换元素
            permutation(A, res, cur+1);//递归调用
            swap(A[i], A[cur]);//换回来
        }
    }
};

int main(){
//	string s="";
//	s+=to_string(111);
//	cout<<s<<endl;
	vector<int> v;
	int a;
	while(cin >> a)
	{
		v.push_back(a);
		char c = cin.get();
		if(c == '\n')
			break;	
	}
	Solution *so=new Solution;
	so->PrintMinNumber(v);
	return 0;
}*/


class Solution {
 public:
     static bool cmp(int a,int b){
         string A="";
         string B="";
         A+=to_string(a);
         A+=to_string(b);
         B+=to_string(b);
         B+=to_string(a);
          
         return A<B;
     }
     string PrintMinNumber(vector<int> numbers) {
         string  answer="";
         sort(numbers.begin(),numbers.end(),cmp);
         for(int i=0;i<numbers.size();i++){
         	cout<<answer<<" ";
             answer+=to_string(numbers[i]);
         }
         return answer;
     }
 }; 
