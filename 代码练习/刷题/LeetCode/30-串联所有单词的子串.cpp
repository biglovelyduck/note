//30-�������е��ʵ��Ӵ�
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
//�Լ�д�ĳ�ʱ 
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
		//����ȫ����
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

//����˼·�����ַ�����ֳ�һ�����Ӵ����������������ж�ÿ���Ӵ��ĵ����Ƿ��ڵ��ʱ�map�� 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.size() == 0)//�ж�wordsΪ��,��Ϊ�����õ���words[0]
            return ret;
        
        int word_size = words[0].size();
        int word_num = words.size();
        
        unordered_map<string,int> m1;//����hashmap
        for(int i=0;i<word_num;i++)
            m1[words[i]]++;
        
        unordered_map<string,int> m2;
        for(int i=0; (i + word_size * word_num) <= s.size() ; i++){//��ȡ��s��������
            int j = 0;
            for(j=i;j < (i + word_size * word_num) ; j=j+word_size){//�ֶ��ж�
                string temp_str = s.substr(j,word_size);
                if(m1[temp_str] == 0){//m1��û�н�ȡ�Ĵ���ֱ������
                    break;
                }else{
                    m2[temp_str]++;
                    if(m1[temp_str] < m2[temp_str])//�ظ��������࣬Ҳ����
                        break;
                }
            }
            
            if(j == (i + word_size * word_num))//ÿһ�ζ����ϣ�������
                ret.push_back(i);
            
            m2.clear();//���m2
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
