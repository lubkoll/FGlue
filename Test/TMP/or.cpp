#include <gtest/gtest.h>

#include "fglue/TMP/apply.hh"
#include "fglue/TMP/or.hh"
#include "fglue/TMP/trueFalse.hh"

using namespace FGlue;

TEST(TMP_Test,Or)
{
  auto trueTrue = isTrue< Apply<Or,True,True> >();
  auto trueFalse = isTrue< Apply<Or,True,False> >();
  auto falseTrue = isTrue< Apply<Or,False,True> >();
  auto falseFalse = isTrue< Apply<Or,False,False> >();

  ASSERT_TRUE( trueTrue );
  ASSERT_TRUE( trueFalse );
  ASSERT_TRUE( falseTrue );
  ASSERT_FALSE( falseFalse );
}
