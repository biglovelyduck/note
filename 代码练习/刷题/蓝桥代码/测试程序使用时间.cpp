#include<ctime>
#include<cstdio>
int main()
{
    int start = clock();
    //DO SOMETHING
    printf("%.3lf\n",double(clock()-start)/CLOCKS_PER_SEC);
}
