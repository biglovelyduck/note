//��ӡ��1������nλ��
#include <bits/stdc++.h>
using namespace std;
bool Increment(char *number){
	bool isOverflow=false;
	int nTaskOver=0;
	int nLength=strlen(number);
	for(int i=nLength-1;i>=0;i--){
		int nSum=number[i]-'0'+nTaskOver;
		if(i==nLength-1)
			nSum++;
		if(nSum>=10){
			if(i==0){
				isOverflow=true;
			}
			else{
				nSum-=10;
				nTaskOver=1;
				number[i]='0'+nSum;
			}
		} 
		else{
			number[i]='0'+nSum;	//ֻ�����һλ����1���˳�ѭ�� 
			break; 
		}
	} 
	return isOverflow; 
}
void PrintNumber(char *number){
	bool isBeginning0=true;
	int nLength=strlen(number);
	for(int i=0;i<nLength;i++){
		if(isBeginning0&&number[i]!='0'){
			isBeginning0=false;
		}
		if(!isBeginning0){
			printf("%c",*(number+i));
			//printf("%c",*number);
			//break;
		}
	}
	cout<<" ";
}
void Print1ToMaxDigits(int n){
	if(n<=0) return;
	char* number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';
	while(!Increment(number))	//�ж��Ƿ��ڷ�Χ�ڿ��Լ�����1 
		PrintNumber(number);
	delete[] number;
}
//ȫ����ʵ��
void Print2(int n){
} 
int main(){
	int n;
	cin>>n;
	Print1ToMaxDigits(n);
}
