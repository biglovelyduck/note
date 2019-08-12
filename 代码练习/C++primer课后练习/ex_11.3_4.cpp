#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

//! Exercise 11.4
//忽略大小写和标点 
void word_count_pro(std::map<std::string, int> &m)
{
    std::string word;
    while(std::cin >> word)
    {
        for(auto& ch : word)
            ch = tolower(ch);
        //word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        //std::remove_if(word.begin(), word.end(), ispunct);
        ++m[word];
    }
    for (const auto &e : m)
        std::cout << e.first << " : " << e.second <<"\n";
}

//! Exercise 11.3
void ex11_3()
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while(std::cin >> word)
        ++word_count[word];

    for (const auto &elem : word_count)
        std::cout << elem.first << " : " << elem.second <<"\n";
}

int main()
{
    std::map<std::string, int> m;
    word_count_pro(m);

    return 0;
}
