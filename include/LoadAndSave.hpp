//____________________________________________________________________________
// Exercice C++ Lupin
//____________________________________________________________________________

#include "ListManipulations.hpp"

#include <istream>
#include <string>
#include <vector>
#include <memory>

namespace Sources{

/// Forward Declaration
///{
class ListManipulations;
///}

const char YES = 'Y';
const char ASCENDING_ORDER = 'A';
const char DESCENDING_ORDER = 'D';

class LoadAndSave
{
public:
/// Constructor
/// \param[in] inputStreamWordsList stream to receive inputs to fill words List
/// \param[in] listManipulationsPtr pointer to ListManipulations
LoadAndSave(std::istream& inputStreamWordsList,
std::unique_ptr<ListManipulations>& listManipulationsPtr);

/// Destructor
~LoadAndSave() = default;

/// Display and store sorted list
/// \param[in] listStreamDuplicates stream stating if duplicates must be removed from list
/// \param[in] fileName the output file name
void DisplaySortedList(std::istream& listStreamDuplicates, const std::string& fileName);

ListManipulations* GetListManipulationsPtr() const;

private:
/// Remove duplicates from words list
/// \param[in] wordsList the words list
void DeleteDuplicates(std::vector<std::string>& wordsList);

/// Pointer to ListManipulations
std::unique_ptr<ListManipulations>  mListManipulationsPtr;
};
} /// namespace Sources