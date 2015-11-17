#include <gtest/gtest.h>

#include "fglue/TMP/apply.hh"
#include "fglue/TMP/not.hh"
#include "fglue/TMP/trueFalse.hh"

using namespace FGlue;

TEST(TMP_Test,Not)
{
  auto true_v = isTrue< Apply<Not,False> >();
  auto false_v = isTrue< Apply<Not,True> >();
  ASSERT_TRUE( true_v );
  ASSERT_FALSE( false_v );
}
