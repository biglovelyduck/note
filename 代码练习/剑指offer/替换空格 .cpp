//�滻�ո� 
class Solution {
public:
	//lengthΪ�ַ�������������� 
	void replaceSpace(char *str,int length) {
		if(str==nullptr||length<=0) return;
		
		int originalLength=0;	//�ַ���str��ʵ�ʳ��� 
		int numberOfBlank=0;
		int i=0;
		while(str[i]!='\0'){
			++originalLength;
			
			if(str[i]==' ')	++numberOfBlank;
			++i;
		}
		//newLengthΪ�ѿո��滻Ϊ%20�󳤶�
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
