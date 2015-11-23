#include <gtest/gtest.h>

#include "fglue/TMP/and.hh"
#include "fglue/TMP/apply.hh"
#include "fglue/TMP/constant.hh"
#include "fglue/TMP/delay.hh"
#include "fglue/TMP/isDerivedFrom.hh"
#include "fglue/TMP/make.hh"
#include "fglue/TMP/makeVariadic.hh"
#include "fglue/TMP/or.hh"
#include "fglue/TMP/trueFalse.hh"
#include "fglue/TMP/variadic.hh"
#include "Test/testSetup.hh"

using namespace FGlue;
using namespace Test;

TEST(TMP_Test,Variadic_Logic_Apply)
{
  auto value = isTrue< Apply<Binary2Variadic<And>,True,True> >();
  ASSERT_TRUE(value);

  value = isTrue< Apply<Binary2Variadic<And>,True,True,True> >();
  ASSERT_TRUE(value);

  value = isTrue< Apply<Binary2Variadic<And>,True,True,False> >();
  ASSERT_FALSE(value);

  value = isTrue< Apply<Binary2Variadic<And>,True,False,True> >();
  ASSERT_FALSE(value);

  value = isTrue< Apply<Binary2Variadic<And>,False,True,True> >();
  ASSERT_FALSE(value);
}

TEST(TMP_Test,Make)
{
  using Operation = Apply< Make<IsDerivedFrom> , Base >;
  auto value = std::is_same< Operation , IsDerivedFrom<Base> >::value;
  ASSERT_TRUE(value);
}

TEST(TMP_Test,VariadicMakeFromTemplate)
{
  using Generator = Variadic< Make<IsDerivedFrom> , Delay<And> >;

  using Operation_BaseBase = Apply< Generator , Base , Base >;
  auto isBaseDerived = isTrue< Apply< Operation_BaseBase , Base > >();
  auto isDerivedDerived = isTrue< Apply< Operation_BaseBase , Derived > >();
  ASSERT_TRUE(isBaseDerived);
  ASSERT_TRUE(isDerivedDerived);

  using Operation_DerivedDerived = Apply< Generator , Derived , Derived >;
  isBaseDerived = isTrue< Apply< Operation_DerivedDerived , Base > >();
  isDerivedDerived = isTrue< Apply< Operation_DerivedDerived , Derived > >();
  ASSERT_FALSE(isBaseDerived);
  ASSERT_TRUE(isDerivedDerived);

  using Operation_BaseOther = Apply< Generator , Base , Other >;
  isBaseDerived = isTrue< Apply< Operation_BaseOther , Base > >();
  isDerivedDerived = isTrue< Apply< Operation_BaseOther , Derived > >();
  ASSERT_FALSE(isBaseDerived);
  ASSERT_FALSE(isDerivedDerived);
}

TEST(TMP_Test, Variadic_Generate_Logic_Apply)
{
  using Generator = Variadic< Make<IsDerivedFrom> , Delay<And> >;
  using Operation = Apply< Generator , Base , Base , Base >;
  auto value = isTrue< Apply< Variadic<Operation,And>, Base , Derived , Base > >();
  ASSERT_TRUE(value);

  using Operation2 = Apply< Generator , Base , Derived , Base >;
  value = isTrue< Apply< Variadic<Operation2,And>, Base , Derived , Base > >();
  ASSERT_FALSE(value);


//  using Operation = Variadic< Delay< MakeFromTemplate<IsDerivedFrom> > , Base, Derived >;
//  using Operation = Apply< Variadic<Delay<And>> , IsDerivedFrom<Base> , IsDerivedFrom<Derived> , IsDerivedFrom<Base> >;
//  value = isTrue< Apply<Operation,Base> >();
//  ASSERT_FALSE(value);

//  value = isTrue< Apply< Variadic<Delay<And>> , Is >()
}
