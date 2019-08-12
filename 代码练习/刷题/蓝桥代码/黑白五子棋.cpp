#include <iostream>
#include <fstream>
using namespace std;
int main(){
	int n;
	char a[15][15];
	bool hasB,hasW;
	cin>>n;
	while(n--){
		ifstream fin("H:\Test\in.txt");
		for(int i=0;i<15;i++){
			fin.getline(a[i],15);
		}
		for(int i=0;i<15;i++){
			for(int j=0;j<15;j++){
				cout<<a[i][j];
			}
		}
		//水平遍历
		for(int i=0;i<15;i++){
			for(int j=0;j<11;j++){
				if(a[i][j]==a[i][j+1]==a[i][j+2]==a[i][j+3]==a[i][j+4]=='B'){
					hasB=true;
					goto for1end;
				}
				if(a[i][j]==a[i][j+1]==a[i][j+2]==a[i][j+3]==a[i][j+4]=='W'){
					hasW=true;
					goto for1end;
				}
			}
		}
		for1end:
		//竖直遍历 
		for(int j=0;j<15;j++){
			for(int i=0;i<11;i++){
				if(a[i][j]==a[i][j+1]==a[i][j+2]==a[i][j+3]==a[i][j+4]=='B'){
					hasB=true;
					goto for2end;
				}
				if(a[i][j]==a[i][j+1]==a[i][j+2]==a[i][j+3]==a[i][j+4]=='W'){
					hasW=true;
					goto for2end;
				}
			}
		}
		for2end:
		//斜线遍历
		for(int i=0;i<15;i++){
			for(int j=0;j<15;j++){
				if(i+4<15&&i+4<15){
					if(a[i][j]==a[i+1][j+1]==a[i+2][j+2]==a[i+3][j+3]==a[i+4][j+4]=='B'){
						hasB=true;
						goto for3end;
					}
					if(a[i][j]==a[i+1][j+1]==a[i+2][j+2]==a[i+3][j+3]==a[i+4][j+4]=='W'){
						hasW=true;
						goto for3end;
					}	
				}
				if(i+4<15&&j-4>=0){
					if(a[i][j]==a[i+1][j-1]==a[i+2][j-2]==a[i+3][j-3]==a[i+4][j-4]=='B'){
						hasB=true;
						goto for3end;
					}
					if(a[i][j]==a[i+1][j-1]==a[i+2][j-2]==a[i+3][j-3]==a[i+4][j-4]=='W'){
						hasW=true;
						goto for3end;
					}	
				}
			}
		}
		for3end:
		if(hasB&&!hasW) cout<<"Black"<<endl;
		if(hasW&&hasB) cout<<"White"<<endl;
		if(hasB&&hasW) cout<<"Both"<<endl;
		if(!hasB&&!hasW) cout<<"None"<<endl; 
		fin.close(); 
	}
	return 0;
}
