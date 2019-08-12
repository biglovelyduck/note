#include<iostream>
#include<cstdlib>
#include<ctime>
#include <iomanip>
#define random(a,b) (rand()%(b-a+1)+a)
#define N 500*1000
using namespace std;


int main()
{
	//srand((unsigned)time(NULL));//产生随机种子数 
	
//	int a=random(1,6); 
//    int b=random(1,6);
//    int c=random(1,6);
//    
//    cout<<a<<" "<<b<<" "<<c;	
//    for(int i=0;i<10;i++)
//    cout<<random(1,100)<<' ';
long long  sum=0;
srand((unsigned)time(NULL));//产生随机种子数 
for(int i=0;i<N;i++){
	int n=0,s=0;
	
	int a=random(1,6); 
    int b=random(1,6);
    int c=random(1,6);
    
    int w=random(1,6);
    
    if(w==a) n++;
    if(w==b) n++;
    if(w==c) n++;
    
    if(n==3) s=-10;
    else if(n==2) s= -2;
    else if(n==1) s=-1;
    else if(n==0) s=1;
    
    sum+=s;
//cout<<a<<b<<c<<endl;
}
double sum2=sum;
double N2=N;
cout<<setprecision(6)<<sum2/N<<endl;
//printf("%.7f",sum2/N2);
cout<<setprecision(6)<<sum2/N2<<endl;
    return 0;
}
