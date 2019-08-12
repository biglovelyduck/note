//最长不含重复字符的子字符串
int longestSubstringWithourDuplication(const std::string& str){
	int curLen=0;
	int maxLen=0;
	int *position=new int[26];
	for(int i=0;i<26;i++){
		position[i]=-1;
	}
	for(int i=0;i<str.length();i++){
		int prevIndex=position[str[i]-'a'];
		if(prevIndex<0||i-prevIndex>curLen)
			++curLen;
		else{
			if(curLen>maxLen)
				maxLen=curLen;
			curLen=i-prevIndex;
		}
		position[str[i]-'a']=i;
	}
	if(curLen>maxLen)
		maxLen=curLen;
	delete[] position;
	return maxLen;
} 
