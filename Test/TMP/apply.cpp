#include <gtest/gtest.h>

#include "fglue/TMP/trueFalse.hh"
#include "fglue/TMP/apply.hh"
#include "fglue/TMP/constant.hh"

using namespace FGlue;

TEST(TMP,Apply)
{
  auto true_v = Apply< Constant<True> >::value;
  auto false_v = Apply< Constant<False> >::value;
  ASSERT_TRUE( true_v );
  ASSERT_FALSE( false_v );
}
