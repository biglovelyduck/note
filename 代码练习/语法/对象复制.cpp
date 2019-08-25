//
#include <iostream> 

#include <cstring> 

using namespace std; 

class S

{         char p[10]; 

public:  

         S(char *a) {set(a); }  

         S & operator=(S &a) 

         {strcpy(p,a.p); return *this; }  

        void show(){cout<<p<<"-";} 

        ~S(){}  

        void set(char *s)

         {strcpy(p,s); } 

};  

int main()  

{S s1("abc"),s2("ABC"); 

s2=s1;  

s1.show(),s2.show();

return 0;}
