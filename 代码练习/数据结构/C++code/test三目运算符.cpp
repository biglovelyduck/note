#include <iostream>
using namespace std;
int main(){
	int a[][4]={0};
	int value=0;
	int temp=a[0][0]?22:value++;
	cout<<temp<<" "<<value;
	return 0;
}
