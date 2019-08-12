#include <iostream>
#include <map>
#include <string>
#include <algorithm>



int main()
{
    //! define a map as required.
    std::map<std::string, std::vector<std::pair<std::string,std::string>>>
            famlies_map;
    //! declare three strings to store the input
    std::string lastName, childName, birthday;

    while([&](){//!   a lambda to read lastName and check if should quit

          std::cout << "last name:\n";
          std::cin >> lastName;

          return lastName != "@q";
}())
    {
        while([&](){//!   a lambda to read child name and birthday and check if should quit
              std::cout << "child's name:\n";
              std::cin  >> childName;
              std::cout << "his birthday:\n";
              std::cin  >> birthday;

              return childName != "@q" && birthday != "@q";
    }())
        {
            famlies_map[lastName].push_back({childName, birthday});
            //!        ^^^^^^^^^^           ^^^^^^^^^^^^^^^^^^^^^
            //!  use lastName as the key    create a pair using {}.
        }
    }

    //! print the content.
    for(const auto &e : famlies_map)
    {
        std::cout << e.first <<":\n";

        for (const auto &l : e.second)
        {
            std::cout << l.first << " "
                      << l.second << " ";
        }
    }

    return 0;
}
