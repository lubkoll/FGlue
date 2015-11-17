#include <gtest/gtest.h>

#include "fglue/TMP/trueFalse.hh"
#include "fglue/TMP/apply.hh"

using namespace FGlue;

TEST(TMP_Test,Apply)
{
  auto true_v = Apply<True>::value;
  auto false_v = Apply<False>::value;
  ASSERT_TRUE( true_v );
  ASSERT_FALSE( false_v );
}
