#include <vector>
#include <utility>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    std::vector<std::pair<std::string, int>> vec;
    std::string str;
    int i;
    while (std::cin >> str >> i)
        vec.push_back(std::pair<std::string, int>(str, i));
        //vec.push_back(std::make_pair(str, i));
        //vec.push_back({str, i});
        //vec.emplace_back(str, i); //!!! easiest way.
    
    for (const auto &p : vec)
        std::cout << p.first << ":" << p.second << std::endl;
        return 0;
}
