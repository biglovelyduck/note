#include <iostream>
#include <string> 
#include <cstring> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int f( char x[]){
	string s(x);
	if(s.find("LOL")!=string::npos) return -1;//���� 
	if(s.find('*')==string::npos) return 0;//ƽ�� 
    bool ping=false;//�����޷�ƽ��
	for(int i=0;i<strlen(x);i++){
		if(x[i]=='*'){
			x[i]='L';//������L
			switch(f(x)){//ʣ�µľ��潻������ 
				case -1:
				    return 1;
				case 0:
				    ping=true;
			}
			x[i]='O';//������O
			switch(f(x)){
				case -1:
					return 1;
				case 0:
					ping=true;
			}
			
			x[i]='*';//���� 
		}
	}
	if(ping) return 0;
	return -1; 
}

int game(string s){
	char s1[50];
	return f(strcpy(s1, s.c_str()));
} 

int main(int argc, char** argv) {
	cout<<game("***")<<endl;
	cout<<game("LOL")<<endl;
	cout<<game("L**L***L")<<endl;
	cout<<game("L*****L")<<endl;
	return 0;
}
