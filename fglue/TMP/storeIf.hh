#ifndef FGLUE_TMP_STORE_IF_HH
#define FGLUE_TMP_STORE_IF_HH

#include <type_traits>
#include "apply.hh"
#include "empty.hh"
#include "isBaseOf.hh"
#include "isDerivedFrom.hh"
#include "trueFalse.hh"

namespace FGlue
{
  //! Stores its argument Type if Operation::template apply<Type>::type::value evaluates to true, else stores a Empty.
  template <class Operation>
  struct StoreIf
  {
    template <class Arg>
    struct apply
    {
      using type = typename std::conditional< isTrue< Apply<Operation,Arg> >() , Arg , Empty>::type;
    };
  };


  template <class Base>
  using StoreIfDerivedFrom = StoreIf< IsDerivedFrom<Base> >;

  template <class Base>
  using StoreIfNotDerivedFrom = StoreIf< IsNotDerivedFrom<Base> >;


  template <class Derived>
  using StoreIfBaseOf = StoreIf< IsBaseOf<Derived> >;

  template <class Derived>
  using StoreIfNotBaseOf = StoreIf< IsNotBaseOf<Derived> >;
}

#endif // FGLUE_TMP_STORE_IF_HH
