#include <gtest/gtest.h>

#include "fglue/TMP/and.hh"
#include "fglue/TMP/apply.hh"

using namespace FGlue;

TEST(TMP_Test,And)
{
  auto trueTrue = isTrue< Apply<And,True,True> >();
  auto trueFalse = isTrue< Apply<And,True,False> >();
  auto falseTrue = isTrue< Apply<And,False,True> >();
  auto falseFalse = isTrue< Apply<And,False,False> >();

  ASSERT_TRUE( trueTrue );
  ASSERT_FALSE( trueFalse );
  ASSERT_FALSE( falseTrue );
  ASSERT_FALSE( falseFalse );
}
