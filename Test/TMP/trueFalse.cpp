#include <gtest/gtest.h>
#include "fglue/TMP/trueFalse.hh"

using namespace FGlue;

TEST(TMP_Test,True)
{
  bool value = True::apply<>::type::value;
  ASSERT_TRUE( value );
  value = True::apply<int>::type::value;
  ASSERT_TRUE( value );
  value = True::apply<char,double>::type::value;
  ASSERT_TRUE( value );
}

TEST(TMP_Test,False)
{
  auto value = False::apply<>::type::value;
  ASSERT_FALSE( value );
  value = False::apply<int>::type::value;
  ASSERT_FALSE( value );
  value = False::apply<char,double>::type::value;
  ASSERT_FALSE( value );
}
