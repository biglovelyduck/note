#include<iostream> 

#include<cstring> 

using namespace std;

class Book  {  

      char*t;

      char a[10]; 

       int n;

public:

       Book( ){ }  

       Book(char*str1,char str2[10],int num)  { 

       int len=strlen(str1);

       t=new char[len+1];

       strcpy(t,str1);

       strcpy(a,str2);

       n=num;}  

       ~Book( )  {delete t;}  

        void print(ostream &output)  { 

         output<<t<<":";

         output<<a<<":";

         output<<n<<endl;}    

};

int main( )  {  

Book obj1("123","abc",100);

obj1.print(cerr);

return 0;}  
