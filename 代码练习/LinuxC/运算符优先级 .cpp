//��������ȼ� 
#include <iostream>
using namespace std;
int main(){
	int x=4;
	x+=x-=x-x--;	//����x-(x--)==3-4 
	cout<<x<<endl;
	int i,y;
	for(y=0,x=1;x>++y;x=i++){
		cout<<"������"<<endl;	//������ 
	}
	cout<<i<<endl;
	int a,b,c;
	b=0x60;
	a=b>>4;
//	cout<<a<<endl;
	printf("%x",a);
	return 0;
}
