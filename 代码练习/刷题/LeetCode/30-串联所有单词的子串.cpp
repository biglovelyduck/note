//30-串联所有单词的子串
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
#include <unordered_map>
using namespace std;
//自己写的超时 
class Solution {
public:
	vector<string> v;
	set<string> ss;
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> ret;
    	all(words);
        for(int i=0;i<v.size();i++){
        	//cout<<v[i]<<endl;
        	findAllSub(ret,s,v[i],0);
		}
		return ret;
    }
    void findAllSub(vector<int>& ret,string s,string sub,int start){
    	if(start==s.size()) return;
    	int index=s.find(sub,start);
    	//cout<<"sub:"<<sub<<" "<<"index:"<<index<<endl;
    	if(index!=s.npos){
    		ret.push_back(index);
    		findAllSub(ret,s,sub,index+1);
		}
	}
    void all(vector<string> &words){
		//生成全排列
		permutation(words,0,words.size()-1);
		for(auto s:ss)	v.push_back(s);
		//for(int i=0;i<v.size();i++)	cout<<v[i]<<endl;
	}
	void permutation(vector<string> &words,int k,int m){		
		if(k==m){
			string s;
			for(int i=0;i<words.size();i++)
				s+=words[i];
			ss.insert(s);
		}
		else{
			for(int j=k;j<=m;j++){
				swap(words[j],words[k]);
				permutation(words,k+1,m);
				swap(words[j],words[k]);
			}
		}
	}
};

//大神思路：将字符串拆分成一个个子串挨个遍历，挨个判断每个子串的单词是否在单词表map中 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.size() == 0)//判断words为空,因为下面用到了words[0]
            return ret;
        
        int word_size = words[0].size();
        int word_num = words.size();
        
        unordered_map<string,int> m1;//构造hashmap
        for(int i=0;i<word_num;i++)
            m1[words[i]]++;
        
        unordered_map<string,int> m2;
        for(int i=0; (i + word_size * word_num) <= s.size() ; i++){//截取的s符合题意
            int j = 0;
            for(j=i;j < (i + word_size * word_num) ; j=j+word_size){//分段判断
                string temp_str = s.substr(j,word_size);
                if(m1[temp_str] == 0){//m1中没有截取的串，直接跳出
                    break;
                }else{
                    m2[temp_str]++;
                    if(m1[temp_str] < m2[temp_str])//重复次数过多，也跳出
                        break;
                }
            }
            
            if(j == (i + word_size * word_num))//每一段都符合，则加入答案
                ret.push_back(i);
            
            m2.clear();//清空m2
        }
        return ret;
    }
};

int main(){
	Solution s;
	vector<string> words={"bar","foo",};
	string str="foobarfoobar";
	vector<int> ret=s.findSubstring(str,words);
	for(auto i:ret) cout<<i<<" ";
	return 0;
}
