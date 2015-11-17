#include <gtest/gtest.h>

#include "fglue/TMP/bind.hh"
#include "fglue/TMP/constant.hh"
#include "fglue/TMP/isBaseOf.hh"
#include "Test/testSetup.hh"

using namespace FGlue;
using namespace Test;

TEST(TMP_Test,Bind)
{
  using BoundBase = Apply< Bind , IsBaseOf<Derived > , Base >;
  auto isBaseOfDerived = isTrue< Apply< BoundBase > >();
  ASSERT_TRUE( isBaseOfDerived );

  using BoundDerived = Apply< Bind , IsBaseOf<Base> , Derived >;
  auto isBaseOfBase = isTrue< Apply< BoundDerived > >();
  ASSERT_FALSE( isBaseOfBase );
}
