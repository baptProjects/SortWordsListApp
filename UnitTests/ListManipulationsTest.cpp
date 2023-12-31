//____________________________________________________________________________
// Exercice C++ Lupin
//____________________________________________________________________________

#include "pch.h"
#include "../src/ListManipulations.cpp"

namespace Tests {

const std::vector<std::string> RANDOM_WORDS =
{
   "hello",
   "awesome",
   "bowl",
   "lupin",
   "tiger"
};

/// Success: ListManipulations constructor initializes successfully
///          mIsAscendingOrder member attribute without throwing
TEST(ListManipulationsTest, Construction)
{
   using namespace Sources;
   EXPECT_NO_THROW({
      auto listManipulationsObj = ListManipulations();
      EXPECT_EQ(listManipulationsObj.IsAscendingOrder(), true);
      });
}

/// Success: SetWordsList sets the input vector correctly
TEST(ListManipulationsTest, SetWordsList)
{
   using namespace Sources;
   auto listManipulationsObj = ListManipulations();
   listManipulationsObj.SetWordsList(RANDOM_WORDS);
   EXPECT_EQ(listManipulationsObj.GetWordsList(), RANDOM_WORDS);
}

/// Success: SetSortOrder sets the input sort order (ascending or descending)
TEST(ListManipulationsTest, SetSortOrder)
{
   using namespace Sources;
   auto listManipulationsObj = ListManipulations();
   /// Ascensing order is initialized true by default
   EXPECT_EQ(listManipulationsObj.IsAscendingOrder(), true);

   listManipulationsObj.SetSortOrder(false);
   EXPECT_EQ(listManipulationsObj.IsAscendingOrder(), false);
}

/// Success: SortList manages to sort the member words list as vector
TEST(ListManipulationsTest, SortList)
{
   using namespace Sources;
   using namespace Sources;
   auto listManipulationsObj = ListManipulations();
   listManipulationsObj.SetWordsList(RANDOM_WORDS);
   listManipulationsObj.SortList();

   const std::vector<std::string> expectedSortedList{ "awesome", "bowl", "hello", "lupin", "tiger" };

   EXPECT_EQ(listManipulationsObj.GetWordsList(), expectedSortedList);
}

} /// namespace Tests
