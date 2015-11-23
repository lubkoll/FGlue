#ifndef FGLUE_TMP_CREATE_MISSING_BASE_CLASSES_HH
#define FGLUE_TMP_CREATE_MISSING_BASE_CLASSES_HH

#include "apply.hh"
#include "delay.hh"
#include "isBaseOf.hh"
#include "make.hh"
#include "makeVariadic.hh"
#include "or.hh"
#include "storeIf.hh"
#include "variadic.hh"

namespace FGlue
{
  using VariadicIsBaseOfGenerator = Variadic< Make<IsBaseOf> , Delay<Or> >;

  using VariadicIsNotBaseOfGenerator = Variadic< Make<IsNotBaseOf> , Delay<And> >;


  template <class... ExistingBaseClasses>
  using VariadicIsBaseOf = Apply< VariadicIsBaseOfGenerator , ExistingBaseClasses... >;

  template <class... ExistingBaseClasses>
  using VariadicIsNotBaseOf = Apply< VariadicIsNotBaseOfGenerator , ExistingBaseClasses... >;


  template <class Operation, class... ExistingBaseClasses>
  using CreateMissingBaseClasses = Apply< Variadic<StoreIf<Operation>,Compose> , ExistingBaseClasses...>;


  template <class... Derived>
  struct BaseOf
  {
    template <class... OtherBases>
    using NotBaseOf = StoreIf< Apply< Delay<And> , VariadicIsBaseOf<Derived...> , VariadicIsNotBaseOf<OtherBases...> > >;
  };

  template <class... BaseClassCandidates>
  struct CreateMissingBases
  {
    template <class... Derived>
    struct BaseOf
    {
      template <class... OtherBases>
      using NotBaseOf = Apply< Variadic< typename FGlue::BaseOf<Derived...>::template NotBaseOf<OtherBases...> , Compose > , BaseClassCandidates... >;
    };
  };

//  template <class... BaseClassCandidates>
//  struct CreateMissingBases
//  {
//    template <class... Derived>
//    struct BaseOf
//    {
//      template <class... OtherBases>
//      using NotBaseOf = Apply< Variadic< FGlue::BaseOf2<Derived...>::NotBaseOf2<OtherBases...> , Compose > , BaseClassCandidates... >;
//    };
//  };
}

#endif // FGLUE_TMP_CREATE_MISSING_BASE_CLASSES_HH
