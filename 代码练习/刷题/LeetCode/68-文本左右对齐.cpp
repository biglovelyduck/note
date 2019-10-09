//68-文本左右对齐 
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
#include <queue>
#include<regex>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start=0,end=0;		//每行句子的第一个单词的索引和最后一个单词的索引
        string line="";			//每行
        vector<string> ret;	
		for(int i=0;i<words.size();i++){		//遍历每个单词 
			int len=words[i].length();
			if(line.empty()){	//是行的第一个单词就直接加进来 
				line+=words[i];
				if(i==words.size()-1) goto part;
				continue;
			}
			if(line.length()+words[i].length()<maxWidth){
				line+=" ";
				line+=words[i];
				if(i==words.size()-1) goto part;
				continue;						//一行没凑满 
			}
			i--;
			part:
				//超出了一行的长度就要重新分配位置，确定好空格要放置的位置
				int num=maxWidth-line.length();		//剩余要填充的空格的个数
				if(num==0) goto last;
				//cout<<"line:"<<line<<"  剩余的空格数:"<<num<<endl;
				int j=0;
				if(line.find(' ')==-1||line.find_first_of(' ')==line.find_last_of(' ')
					&&i==words.size()-1){
					while(num--) line+=" ";
					goto end;
				}
				for(;;j++){
					if(num==0) break;
					if(j==line.length()-1) j=0;	
					if(line[j]==' '){
						line.insert(j," ");	
						num--;	cout<<"此时的j:"<<j<<"  此时的line:"<<line<<"  此时的line长度:"<<line.length()<<endl;
						while(line[j]==' ')
							j++;  //cout<<"下一个j："<<j<<endl; 
						continue;				//插入下一个空格 
					}	
				}
			last:
				//多余空格插入完毕
				ret.push_back(line); 
				line.clear();
				//cout<<"下一个行首单词是："<<words[i+1]<<endl; 
		} 
		return ret;
    }
};

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int n = words.size();
		for (int i = 0; i < n;)
		{
			int len = 0, num = -1;//len是单词的总长度，num是空格的最少个数，也就是单词个数-1
			while (len + num <= maxWidth && i < n)
			{
				len += words[i].length();
				++num;
				++i;
			}
			if (len + num > maxWidth)
			{
				--i;
				--num;
				len -= words[i].length();
			}
			if (i != n)
			{
				i -= num + 1;
				int blank = maxWidth - len;
				if (num > 0)
				{
					vector<int> blanks = vector<int>(num, blank / num);
					for (int j = 0; j < blank%num; ++j)
					{
						blanks[j] += 1;
					}
					string s;
					int j;
					int m = blanks.size();
					for (j = 0; j < m; ++j)
					{
						s.append(words[i + j]);
						s.append(blanks[j], ' ');
					}
					for (; j < num + 1; ++j)
					{
						s.append(words[i + j]);
					}
					res.push_back(s);
				}
				else
				{
					string s = words[i];
					s.append(blank, ' ');
					res.push_back(s);
				}
			}
			else
			{
				i -= num + 1;
				string s;
				for (int j = 0; j < num; ++j)
				{
					s.append(words[i + j]);
					s.append(" ");
				}
				s.append(words[i + num]);
				s.append(maxWidth - len - num, ' ');
				res.push_back(s);
			}
			i += num + 1;
		}
		return res;
	}
};

int main(){
	Solution s;
	vector<string> v1={"Science","is","what","we","understand","well","enough","to",
	"explain","to","a","computer.","Art","is","everything","else","we","do"};
	vector<string> v={"Listen","to","many,","speak","to","a","few."};
	vector<string> ret=s.fullJustify(v,6);
	for(auto s:ret) cout<<s<<endl;
	return 0;
}
