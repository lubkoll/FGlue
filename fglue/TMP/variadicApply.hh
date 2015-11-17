#ifndef FGLUE_TMP_VARIADIC_APPLY_HH
#define FGLUE_TMP_VARIADIC_APPLY_HH

#include "apply.hh"
#include "bind.hh"
#include "combiner.hh"

namespace FGlue
{
  /*!
    @tparam Operation operation to apply on each argument to apply
    @tparam Combiner combines the individual results
   */
  template <class Operation, class Combiner = DefaultCombiner>
  struct VariadicApply
  {
    template <class... Args>
    struct apply;

    template<class Arg, class... Args>
    struct apply<Arg,Args...>
    {
      using type = Apply< Combiner , Apply<Operation,Arg>, Apply<VariadicApply<Operation,Combiner>,Args...> >;
//      using type = Apply< Combined >;
    };

    template <class Arg>
    struct apply<Arg>
    {
      using type = Apply<Operation,Arg>;
    };
  };
}

#endif // FGLUE_TMP_VARIADIC_APPLY_HH
