//____________________________________________________________________________
// Exercice C++ Lupin
//____________________________________________________________________________

#include "pch.h"
#include "../src/LoadAndSave.cpp"

#include <functional>

namespace Tests {

const std::vector<std::string> RANDOM_WORDS_WITH_DUPLICATES =
{
   "tiger",
   "hello",
   "lupin",
   "tiger",
   "water",
   "awesome",
   "bowl",
   "lupin",
   "hello",
   "tiger"
};

const std::vector<std::string> SORTED_RANDOM_WORDS_WITHOUT_DUPLICATES =
{
   "awesome",
   "bowl",
   "hello",
   "lupin",
   "tiger",
   "water"
};

const std::vector<std::string> SORTED_RANDOM_WORDS_WITH_DUPLICATES =
{
   "awesome",
   "bowl",
   "hello",
   "hello",
   "lupin",
   "lupin",
   "tiger",
   "tiger",
   "tiger",
   "water"
};

/// Success: LoandAndSave constructor sets correctly the expected list 
///          through listManipulation smart pointer according to input given
TEST(LoadAndSaveTest, Construction)
{
   using namespace Sources;

   std::unique_ptr<ListManipulations> listManipulations =
      std::make_unique<ListManipulations>();

   /// User input simulated with subsequent words and answer to sort order
   std::istringstream randomUserInput("tiger\nhello\nlupin\ntiger\nwater\nawesome\nbowl\nlupin\nhello\ntiger\nEndList\nA\n");

   LoadAndSave loadAndSave(randomUserInput, listManipulations);

   EXPECT_EQ(loadAndSave.GetListManipulationsPtr()->GetWordsList(), RANDOM_WORDS_WITH_DUPLICATES);
}

/// Success: LoadAndSave constructor throws in case pointer given is null
TEST(LoadAndSaveTest, ConstructionThrow)
{
   using namespace Sources;

   std::unique_ptr<ListManipulations> listManipulations =
      nullptr;

   
   /// User input simulated with subsequent words and answer to sort order
   std::istringstream randomUserInput("tiger\nhello\nlupin\ntiger\nwater\nawesome\nbowl\nlupin\nhello\ntiger\nEndList\nA\n");

   EXPECT_THROW(LoadAndSave loadAndSave(randomUserInput, listManipulations), std::invalid_argument);
}

/// Success: DisplayList manages to display and store sorted list, getting rid of duplicates
TEST(LoadAndSaveTest, DisplaySortedListWithoutDuplicates)
{
   using namespace Sources;

   std::unique_ptr<ListManipulations> listManipulations =
      std::make_unique<ListManipulations>();

   /// User input simulated with subsequent words and answer to sort order
   std::istringstream randomUserInput("tiger\nhello\nlupin\ntiger\nwater\nawesome\nbowl\nlupin\nhello\ntiger\nEndList\nA\n");

   LoadAndSave loadAndSave(randomUserInput, listManipulations);

   std::istringstream DuplicateAnswerinput("Y\n");

   // Test the method with the redirected std::cin
   loadAndSave.DisplaySortedList(DuplicateAnswerinput, "TestOutputFileWithoutDuplicates.txt");

   EXPECT_EQ(loadAndSave.GetListManipulationsPtr()->GetWordsList(), SORTED_RANDOM_WORDS_WITHOUT_DUPLICATES);
}

/// Success: DisplayList manages to display and store sorted list, keeping potential duplicates
TEST(LoadAndSaveTest, DisplaySortedListWithDuplicates)
{
   using namespace Sources;

   std::unique_ptr<ListManipulations> listManipulations =
      std::make_unique<ListManipulations>();

   /// User input simulated with subsequent words and answer to sort order
   std::istringstream randomUserInput("tiger\nhello\nlupin\ntiger\nwater\nawesome\nbowl\nlupin\nhello\ntiger\nEndList\nA\n");

   LoadAndSave loadAndSave(randomUserInput, listManipulations);

   std::istringstream DuplicateAnswerinput("N\n");

   // Test the method with the redirected std::cin
   loadAndSave.DisplaySortedList(DuplicateAnswerinput, "TestOutputFileWithDuplicates.txt");

   EXPECT_EQ(loadAndSave.GetListManipulationsPtr()->GetWordsList(), SORTED_RANDOM_WORDS_WITH_DUPLICATES);
}
} /// namespace Tests
