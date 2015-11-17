#include <gtest/gtest.h>

#include "fglue/TMP/apply.hh"
#include "fglue/TMP/constant.hh"
#include "fglue/TMP/isDerivedFrom.hh"
#include "Test/testSetup.hh"

using namespace FGlue;
using namespace Test;

TEST(TMP_Test,IsDerivedFrom)
{
  auto baseBase =  isTrue<Apply<IsDerivedFrom<Base>,Base>>();
  auto baseDerived = isTrue<Apply<IsDerivedFrom<Base>,Derived>>();
  auto derivedBase = isTrue<Apply<IsDerivedFrom<Derived>,Base>>();

  ASSERT_TRUE( baseBase );
  ASSERT_TRUE( baseDerived );
  ASSERT_FALSE( derivedBase );
}

TEST(TMP_Test,IsNotDerivedFrom)
{
  auto baseBase =  isTrue<Apply<IsNotDerivedFrom<Base>,Base>>();
  auto baseDerived = isTrue<Apply<IsNotDerivedFrom<Base>,Derived>>();
  auto derivedBase = isTrue<Apply<IsNotDerivedFrom<Derived>,Base>>();

  ASSERT_FALSE( baseBase );
  ASSERT_FALSE( baseDerived );
  ASSERT_TRUE( derivedBase );
}
