//#ifndef FGLUE_TMP_MAKE_VARIADIC_HH
//#define FGLUE_TMP_MAKE_VARIADIC_HH

//#include "apply.hh"
//#include "identity.hh"
//#include "variadic.hh"

//namespace FGlue
//{
////  template <class Operation>
////  struct VariadicBinary
////  {
////    template <class...> struct apply;

////    template <class Arg, class... Args>
////    struct apply<Arg,Args...>
////    {
////      using type = Apply<Operation,Arg,typename apply<Args...>::type>;
////    };

////    template <class Arg1, class Arg2>
////    struct apply<Arg1,Arg2>
////    {
////      using type = Apply<Operation,Arg1,Arg2>;
////    };
////  };


////  struct MakeBinaryVariadic
////  {
////    template <class Operation>
////    struct apply
////    {
////      using type = VariadicBinary<Operation>;
////    };
////  };
//}

//#endif // FGLUE_TMP_MAKE_VARIADIC_HH
