//____________________________________________________________________________
// Exercice C++ Lupin
//____________________________________________________________________________

#include "../include/LoadAndSave.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>

namespace Sources{


LoadAndSave::LoadAndSave(std::istream& inputStreamWordsList,
    std::unique_ptr<ListManipulations>& listManipulations)
    : mListManipulationsPtr(nullptr)

{
   if (listManipulations)
   {
      mListManipulationsPtr = std::move(listManipulations);
   }
   else
   {
      throw std::invalid_argument("null pointer listManipulations");
   }
    std::string line;
    std::vector<std::string> listLoaded;
    std::cout << "Please enter a word to fill the list in order for it to be sorted ('EndList' to finish)\n" << std::endl;

    int wordCount = 0; 
    while (true)
    {
        std::getline(inputStreamWordsList, line);
        if (line == "EndList") 
        {
            break;
        } 
        else 
        {
            std::istringstream iss(line);
            std::string word;
            wordCount = 0; // Reset wordCount for each line
            while (iss >> word) 
            {
                listLoaded.emplace_back(word);
                ++wordCount;
            }
        }

        if (wordCount > 1) 
        {
            std::cout << "Invalid input. Please enter one word at a time." << std::endl;
            listLoaded.clear(); // Clear the list as it contains more than one word
        }
    }
    mListManipulationsPtr->SetWordsList(listLoaded);

    char sortOrder;
    do
    {
        std::cout << "Do you want to sort them in ascending order (A) or descending order(B)\n. What do you want (A/D)" << std::endl;
        inputStreamWordsList >> sortOrder;
        /// Ensure this is uppercase
        sortOrder = std::toupper(sortOrder);
    } while (sortOrder != ASCENDING_ORDER && sortOrder != DESCENDING_ORDER);
    mListManipulationsPtr->SetSortOrder(sortOrder == ASCENDING_ORDER);
}

void LoadAndSave::DisplaySortedList(std::istream& listStream, const std::string& fileName)
{
    char duplicateRemovalWords;
    std::cout << "Do you want to remove potential duplicates in your sorted list before display?\n If you confirm you're willing to delete duplicates, answer Y. Otherwise, answer N\n What do you want?(Y/N)" << std::endl;
    listStream >> duplicateRemovalWords;

    mListManipulationsPtr->SortList();
    auto sortedList = mListManipulationsPtr->GetWordsList();

    if (duplicateRemovalWords == YES)
    {
        DeleteDuplicates(sortedList);
    }
    mListManipulationsPtr->SetWordsList(sortedList);
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        for (const auto& word : sortedList ) {
            outputFile << word << std::endl;
        }
        outputFile.close();
        std::cout << "Words have been written to the file: " << fileName << std::endl;
    }
    else
    {
        std::cerr << "Unable to open the file: " << fileName << std::endl;
    }
}

void LoadAndSave::DeleteDuplicates(std::vector<std::string>& wordsList)
{
    std::vector<std::string> uniqueWordsList;
    for (const auto &word : wordsList) 
    {
        if (std::find(uniqueWordsList.begin(), uniqueWordsList.end(), word) == uniqueWordsList.end()) 
        {
            uniqueWordsList.push_back(word);
        }
    }
    wordsList = uniqueWordsList;
}

ListManipulations* LoadAndSave::GetListManipulationsPtr() const
{
   return mListManipulationsPtr.get();
}
} /// namespace Sources
