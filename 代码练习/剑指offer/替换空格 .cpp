//替换空格 
class Solution {
public:
	//length为字符串数组的总容量 
	void replaceSpace(char *str,int length) {
		if(str==nullptr||length<=0) return;
		
		int originalLength=0;	//字符串str的实际长度 
		int numberOfBlank=0;
		int i=0;
		while(str[i]!='\0'){
			++originalLength;
			
			if(str[i]==' ')	++numberOfBlank;
			++i;
		}
		//newLength为把空格替换为%20后长度
		int newLength=originalLength+numberOfBlank*2;
		if(newLength>length) return;
		
		int indexOfOriginal=originalLength;
		int indexOfNew=newLength;
		while(indexOfOriginal>=0&&indexOfNew>indexOfOriginal){
			if(str[indexOfOriginal]==' '){
				str[indexOfNew--]='0';
				str[indexOfNew--]='2';
				str[indexOfNew--]='%';
			}
			else{
				str[indexOfNew--]=str[indexOfOriginal];
			}
			indexOfOriginal--;
		} 
	}
};
