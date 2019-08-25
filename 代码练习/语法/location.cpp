#include <iostream>

#include <functional>

using namespace std;

int main()

{ 

    int A[5] = {5,3,1,4,2} ;

    int *location ;

    int value ;

    cin >> value;

   
for(int i=0;i<5;i++)

  if(A[i]==value)

    location=&A[i];

    if (location != A + 5)

        cout << value << "是第"

             << (location-A)+1 << "个元素" << endl;

    else

        cout << "error" << endl;

    return 0;

}
