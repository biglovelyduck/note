#include <iostream>
#include <string>
#include <memory>

using std::string; using std::unique_ptr;

int main()
{
    unique_ptr<string> p1(new string("pezy"));
    // unique_ptr<string> p2(p1); // copy
    //                      ^
    // Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
    //
    // unique_ptr<string> p3 = p1; // assign
    //                      ^
    // Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
    std::cout << *p1 << std::endl;
    p1.reset(nullptr);
}
