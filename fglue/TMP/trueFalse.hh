#ifndef FGLUE_TRUE_FALSE_HH
#define FGLUE_TRUE_FALSE_HH

#include <type_traits>

namespace FGlue
{
  //! Template meta-function that always evaluates to std::true_type.
  struct True
  {
    template <class...>
    struct apply
    {
      using type = std::true_type;
    };
  };

  //! Template meta-function that always evaluates to std::false_type.
  struct False
  {
    template <class...>
    struct apply
    {
      using type = std::false_type;
    };
  };

  struct TrueFunction
  {
    template <class...>
    struct apply
    {
      using type = True;
    };
  };

  struct FalseFunction
  {
    template <class...>
    struct apply
    {
      using type = False;
    };
  };

  template <class Type>
  constexpr bool isTrue()
  {
    return std::is_same<Type,True>::value;
  }
}

#endif // FGLUE_TRUE_FALSE_HH
