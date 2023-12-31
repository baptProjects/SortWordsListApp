//____________________________________________________________________________
// Exercice C++ Lupin
//____________________________________________________________________________

#include "../include/ListManipulations.hpp"

#include <algorithm>


namespace Sources{

ListManipulations::ListManipulations():
   mIsAscendingOrder(true)
{
}

bool ListManipulations::IsAscendingOrder() const
{
    return mIsAscendingOrder;
}

std::vector<std::string> ListManipulations::GetWordsList() const
{
    return mWordsList;
}

void ListManipulations::SetWordsList(std::vector<std::string> wordsList)
{
    mWordsList = wordsList;
}

void ListManipulations::SetSortOrder(bool isAscending)
{
    mIsAscendingOrder = isAscending;
}

void ListManipulations::SortList()
{
    std::sort(mWordsList.begin(), mWordsList.end(), [isAscendingOrder = mIsAscendingOrder](const std::string& wordA, const std::string& wordB)
    {
        return isAscendingOrder ? wordA < wordB : wordA > wordB;
    });
}
} /// namespace Sources
