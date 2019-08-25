//c++直接二进制
#include<bitset>
#include<iostream>
int main()
{
 int c=1024;
 std::bitset<sizeof(int)*8> a(c); 
 std::cout<<a<<"\n";
 return 0;
}
 
