#include <iostream>
#include <map>
#include <string>

using std::string;

int main()
{
    std::map<string, size_t> word_count;
    string word;
    while(std::cin >> word)
    {
        auto ret = word_count.insert({word,1});
        if(!ret.second) ++ret.first->second;
    }

    //! print the content of the map.
    for(const auto &w : word_count)
        std::cout << w.first << " " << w.second
                << ((w.second > 1) ? " times" : " time") << std::endl;
}

