#ifndef FGLUE_TMP_APPLY_HH
#define FGLUE_TMP_APPLY_HH

namespace FGlue
{
  /// @cond
  namespace ApplyImpl
  {
    template <class...> struct Apply;

    template <class Operation>
    struct Apply<Operation>
    {
      using type = typename Operation::template apply<>::type;
    };

    template <class Operation, class... Args>
    struct Apply<Operation,Args...>
    {
      using type = typename Operation::template apply<Args...>::type;
    };

    template <int,class...> struct ApplyN;

    template <int N, class FirstOperation, class SecondOperation, class... OperationsAndArgs>
    struct ApplyN<N,FirstOperation,SecondOperation,OperationsAndArgs...>
    {
      using type = typename ApplyN<N-1,typename Apply<FirstOperation,SecondOperation>::type,OperationsAndArgs...>::type;
    };

    template <class Operation,class... Args>
    struct ApplyN<1,Operation,Args...>
    {
      using type = typename Apply<Operation,Args...>::type;
    };
  }
  /// @endcond

  //! Convenient access to Operation::apply<Args...>::type.
  template <class... OperationAndArgs>
  using Apply = typename ApplyImpl::Apply<OperationAndArgs...>::type;

  //! Concatenate operations
  template <int N,  class... OperationsAndArgs>
  using ApplyN = typename ApplyImpl::ApplyN<N,OperationsAndArgs...>::type;

  template <class... OperationsAndArgs>
  using Apply2 = ApplyN<2,OperationsAndArgs...>;
}

#endif // FGLUE_TMP_APPLY_HH
