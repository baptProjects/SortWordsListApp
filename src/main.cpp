//____________________________________________________________________________
// Exercice C++ Lupin
//____________________________________________________________________________

#include "../include/LoadAndSave.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <string>

int main()
{
    std::cout << "Please provide a list with words, tap enter for each word confirmed to be in the list\n" << std::endl;
    std::cout << "Type EndList to finish\n" << std::endl;

    auto myListManipulator{std::make_unique<Sources::ListManipulations>()};
    Sources::LoadAndSave loader(std::cin, myListManipulator);
    loader.DisplaySortedList(std::cin, "mySortedList.txt");
    return 0;
} /// namespace empty

