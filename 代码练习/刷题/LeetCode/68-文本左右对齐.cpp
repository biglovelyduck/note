//68-�ı����Ҷ��� 
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
        int start=0,end=0;		//ÿ�о��ӵĵ�һ�����ʵ����������һ�����ʵ�����
        string line="";			//ÿ��
        vector<string> ret;	
		for(int i=0;i<words.size();i++){		//����ÿ������ 
			int len=words[i].length();
			if(line.empty()){	//���еĵ�һ�����ʾ�ֱ�Ӽӽ��� 
				line+=words[i];
				if(i==words.size()-1) goto part;
				continue;
			}
			if(line.length()+words[i].length()<maxWidth){
				line+=" ";
				line+=words[i];
				if(i==words.size()-1) goto part;
				continue;						//һ��û���� 
			}
			i--;
			part:
				//������һ�еĳ��Ⱦ�Ҫ���·���λ�ã�ȷ���ÿո�Ҫ���õ�λ��
				int num=maxWidth-line.length();		//ʣ��Ҫ���Ŀո�ĸ���
				if(num==0) goto last;
				//cout<<"line:"<<line<<"  ʣ��Ŀո���:"<<num<<endl;
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
						num--;	cout<<"��ʱ��j:"<<j<<"  ��ʱ��line:"<<line<<"  ��ʱ��line����:"<<line.length()<<endl;
						while(line[j]==' ')
							j++;  //cout<<"��һ��j��"<<j<<endl; 
						continue;				//������һ���ո� 
					}	
				}
			last:
				//����ո�������
				ret.push_back(line); 
				line.clear();
				//cout<<"��һ�����׵����ǣ�"<<words[i+1]<<endl; 
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
			int len = 0, num = -1;//len�ǵ��ʵ��ܳ��ȣ�num�ǿո�����ٸ�����Ҳ���ǵ��ʸ���-1
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
