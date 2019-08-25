#include <iostream>

#include <cmath>

using namespace std;

int fun(int i)

{  int j,k,flag;

   flag = 1;

   k = sqrt(i);

   for (j = 2; j <= k; j++)

    {  if(i%j == 0)

        {flag=0;

           break;}    }

if (flag)     return 1;

else          return 0;}

int main()

{ int a=97;

  cout<<fun(a);}
