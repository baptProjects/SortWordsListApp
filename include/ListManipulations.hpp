//____________________________________________________________________________
// Exercice C++ Lupin
//____________________________________________________________________________

#include <istream>
#include <sstream>
#include <string>
#include <vector>

namespace Sources{

class ListManipulations
{
public:
/// Constructor
/// 
ListManipulations();

/// Destructor
~ListManipulations() = default;

/// \return whether sorting order is ascending or not
bool IsAscendingOrder() const;

/// \return the words list
std::vector<std::string> GetWordsList() const;

/// Setter for the words list
/// \param[in] wordsList the words list as vector
void SetWordsList(std::vector<std::string> wordsList);

/// Setter for the sorting order option
/// \param[in] isAscending boolean storing whether the sort is ascending or not
void SetSortOrder(bool isAscending);

/// Sort the words list according to ascending order
void SortList();

private:

/// Boolean stating whether sorting order is ascending or not
bool mIsAscendingOrder;

/// Vector gathering all given words
std::vector<std::string> mWordsList;
};
} /// namespace Sources