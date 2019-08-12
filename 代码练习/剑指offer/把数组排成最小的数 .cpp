//�������ų���С���� 
/*����һ�����������飬����������������ƴ�������ų�һ������
��ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}��
���ӡ���������������ųɵ���С����Ϊ321323��*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*�ڴ泬�ޡ����� 
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
        sort(res.begin(), res.end(), greater<string>());//����
        return res;
    }
 
    void permutation(string A, vector<string>& res, int cur){
        int len = A.size();
        if(cur == len -1){//�����һ���ַ����Ͳ�����
            res.push_back(A);
            return;
        }
        for(int i = cur; i < len; ++i){
            swap(A[i], A[cur]);//����Ԫ��
            permutation(A, res, cur+1);//�ݹ����
            swap(A[i], A[cur]);//������
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
