#include <gtest/gtest.h>

#include "fglue/TMP/and.hh"
#include "fglue/TMP/apply.hh"
#include "fglue/TMP/constant.hh"
#include "fglue/TMP/delay.hh"
#include "fglue/TMP/trueFalse.hh"
#include "fglue/TMP/variadic.hh"

using namespace FGlue;

TEST(TMP_Test, Delay)
{
  using Reference = Apply<And,True,True>;
  auto value = isTrue<Reference>();
  ASSERT_TRUE(value);

  using Delayed = Apply<Delay<And>,Constant<True>,Constant<True>>;
  value = isTrue< Apply<Delayed> >();
  ASSERT_TRUE(value);

  value = isTrue< Apply<Variadic<Delayed,And>,int,char,double> >();
  ASSERT_TRUE(value);
}
