#ifndef DUNE_TMP_FOR_EACH_HH
#define DUNE_TMP_FOR_EACH_HH

#include <type_traits>

#include "dune/common/typetraits.hh"
#include "logic.hh"

namespace Dune
{
  namespace TMP
  {



    /*!
      @tparam Operation operation to apply on each element of Sequence
      @tparam Combiner combines the individual results
     */
    template <class Operation, class Combiner, class... Sequence>
    struct VariadicForEach;

    template <class Operation, class Combiner, class Element, class... Sequence>
    struct VariadicForEach<Operation,Combiner,Element,Sequence...>
    {
      template <class... Args>
      struct apply
      {
        using Combined = Apply< Combiner, Apply<Operation,Element>, VariadicForEach<Operation,Combiner,Sequence...> >;
        using type = Apply<Combined,Args...>;
      };
    };

    template <class Operation, class Combiner, class LastElement>
    struct VariadicForEach<Operation,Combiner,LastElement>
    {
      template <class... Args>
      struct apply
      {
        using type = Apply< Apply<Operation,LastElement> , Args...>;
      };
    };
  }
}

#endif // DUNE_TMP_FOR_EACH_HH
