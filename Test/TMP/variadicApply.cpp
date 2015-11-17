#include <gtest/gtest.h>

#include "fglue/TMP/and.hh"
#include "fglue/TMP/apply.hh"
#include "fglue/TMP/combiner.hh"
#include "fglue/TMP/constant.hh"
#include "fglue/TMP/delay.hh"
#include "fglue/TMP/identity.hh"
#include "fglue/TMP/isBaseOf.hh"
#include "fglue/TMP/isDerivedFrom.hh"
#include "fglue/TMP/make.hh"
#include "fglue/TMP/storeIf.hh"
#include "fglue/TMP/trueFalse.hh"
#include "fglue/TMP/variadicApply.hh"
#include "Test/testSetup.hh"

using namespace FGlue;
using namespace Test;

TEST(TMP_Test,VariadicApply_Logical)
{
  auto value = Apply< Apply< VariadicApply<Constant<True>,And> , int > >::value;
  ASSERT_TRUE( value );

  value = Apply< Apply< VariadicApply<Constant<True>,And> , int , char > >::value;
  ASSERT_TRUE( value );

  value = Apply< Apply< VariadicApply<Constant<True>,And> , int , char > >::value;
  ASSERT_TRUE( value );

  value = isTrue< Apply< VariadicApply< IsBaseOf<Base> , And > , Derived > >();
  ASSERT_FALSE( value );

  value = isTrue< Apply< VariadicApply< IsBaseOf<Base> , And > , Base , Derived > >();
  ASSERT_FALSE( value );
}

TEST(TMP_Test, VariadicApply_BaseClasses)
{
  using Operation = VariadicApply< StoreIfDerivedFrom<Base> , Compose >;
  using Result0 = Apply< Operation , Other >;
  auto value = std::is_same<Empty,Result0>::value;
  ASSERT_TRUE(value);

  using Result1 = Apply< Operation , Other , Other >;
  value = std::is_same<Empty,Result1>::value;
  ASSERT_TRUE(value);

  using Result2 = Apply< Operation , Other , Base >;
  value = std::is_same<Base,Result2>::value;
  ASSERT_TRUE(value);

  using Result3 = Apply< Operation , Derived , Other >;
  value = std::is_same<Derived,Result3>::value;
  ASSERT_TRUE(value);

  using Result4 = Apply< Operation , Base , Derived , Other >;
  value = std::is_base_of<Derived,Result4>::value;
  ASSERT_TRUE(value);
  value = std::is_base_of<Base,Result4>::value;
  ASSERT_TRUE(value);
}


template <template <class...> class Operation>
struct ChainGenerator
{
  template <class... Args>
  struct apply
  {
    using type = Operation<Args...>;
  };
};

TEST(TMP_Test, VariadicApply_GenerateAndApplyOperation)
{
  using OperationGenerator = VariadicApply< ChainGenerator<IsDerivedFrom> , Delay<And> >;

  auto isBaseDerived = isTrue< Apply< Apply< OperationGenerator , Derived > , Base > >();
  auto isDerivedDerived = isTrue< Apply< Apply< OperationGenerator , Derived > , Derived > >();
  ASSERT_FALSE( isBaseDerived );
  ASSERT_TRUE( isDerivedDerived );

  isBaseDerived = isTrue< Apply< Apply< OperationGenerator , Base > , Base > >();
  isDerivedDerived = isTrue< Apply< Apply< OperationGenerator , Base > , Derived > >();
  ASSERT_TRUE( isBaseDerived );
  ASSERT_TRUE( isDerivedDerived );

  isBaseDerived = isTrue< Apply< Apply< OperationGenerator , Base , Derived > , Base > >();
  isDerivedDerived = isTrue< Apply< Apply< OperationGenerator , Base , Derived > , Derived > >();
  ASSERT_FALSE( isBaseDerived );
  ASSERT_TRUE( isDerivedDerived );

  isBaseDerived = isTrue< Apply< Apply< OperationGenerator , Base , Derived , Derived > , Base > >();
  isDerivedDerived = isTrue< Apply< Apply< OperationGenerator , Base , Derived , Derived > , Derived > >();
  ASSERT_FALSE( isBaseDerived );
  ASSERT_TRUE( isDerivedDerived );


//  using Result = Apply< OperationGenerator , Derived >;
//  auto value = std::is_same< IsDerivedFrom<Derived> , Result>::value;
//  ASSERT_TRUE(value);

//  using Combined = Apply< Make<And::apply> , Apply<Make<IsDerivedFrom>,Base>, Apply<Make<IsDerivedFrom>,Derived> >;

//  auto value = std::is_same< IsDerivedFrom<Base> , Apply<Make<IsDerivedFrom>,Base> >::value;
//  ASSERT_TRUE(value);

//  using Operation = Apply< OperationGenerator , Base , Derived >;
//  using Result0 = Apply< VariadicApply< Operation , Compose > , Base >;
//  auto value = std::is_same<Empty,Result0>::value;
//  ASSERT_TRUE(value);
}

//template<class ... OperationAndArgs>
//using Apply = typename ApplyImpl::Apply::type
//[with
//OperationAndArgs = {
//ApplyImpl::Apply<
//  Make<And::apply> ,
//  Impl::Bind<Make<IsDerivedFrom>, Test::Base>,
//  Impl::Bind<VariadicApply<Make<IsDerivedFrom>, Make<And::apply> >, Test::Derived>
//>::type}]’

