//#ifndef DUNE_TMP_FOR_EACH_HH
//#define DUNE_TMP_FOR_EACH_HH

//#include <type_traits>

//#include "dune/common/typetraits.hh"
//#include "logic.hh"

//namespace Dune
//{
//  namespace TMP
//  {
//    //! @cond
//    namespace Impl
//    {
//      template <class... Args>
//      struct Composer
//      {
//        template <class First, class Second,
//                  bool = !std::is_base_of< Empty , Apply<First,Args...> >::value,
//                  bool = !std::is_base_of< Empty , Apply<Second,Args...> >::value>
//        struct apply
//        {
//          using type = Empty;
//        };

//        template <class First, class Second>
//        struct apply<First,Second,true,false>
//        {
//          using type = Apply<First,Args...>;
//        };

//        template <class First, class Second>
//        struct apply<First,Second,false,true>
//        {
//          using type = Apply<Second,Args...>;
//        };

//        template <class First, class Second>
//        struct apply<First,Second,true,true>
//        {
//          struct type :
//              Apply<First,Args...>,
//              Apply<Second,Args...>
//          {};
//        };
//      };


//      template <class First, class Second>
//      struct Compose
//      {
//        template <class... Args>
//        struct apply
//        {
//          using type = Apply<Composer<Args...>,First,Second>;
//        };
//      };


//      template <class,class>
//      struct DefaultCombiner
//      {
//        template <class... Args>
//        struct apply
//        {
//          using type = Empty;
//        };
//      };
//    }
//    //! @endcond


//    //! Always returns Dune::Empty.
//    struct DefaultCombiner
//    {
//      template <class First, class Second>
//      struct apply
//      {
//        using type = Impl::DefaultCombiner<First,Second>;
//      };
//    };


//    /*!
//      @brief Composition of return types from meta-functions.

//      If both meta-functions return types different from Dune::Empty than a class that inherits from
//      both results is returned.
//      If both return Dune::Empty then returns Dune::Empty
//      Else returns the result that differs from Dune::Empty
//     */
//    struct Compose
//    {
//      template <class First, class Second>
//      struct apply
//      {
//        using type = Impl::Compose<First,Second>;
//      };
//    };


//    /*!
//      @tparam Operation operation to apply on each element of Sequence
//      @tparam Combiner combines the individual results
//     */
//    template <class Operation, class Combiner, class... Sequence>
//    struct VariadicForEach;

//    template <class Operation, class Combiner, class Element, class... Sequence>
//    struct VariadicForEach<Operation,Combiner,Element,Sequence...>
//    {
//      template <class... Args>
//      struct apply
//      {
//        using Combined = Apply< Combiner, Apply<Operation,Element>, VariadicForEach<Operation,Combiner,Sequence...> >;
//        using type = Apply<Combined,Args...>;
//      };
//    };

//    template <class Operation, class Combiner, class LastElement>
//    struct VariadicForEach<Operation,Combiner,LastElement>
//    {
//      template <class... Args>
//      struct apply
//      {
//        using type = Apply< Apply<Operation,LastElement> , Args...>;
//      };
//    };


//    /*!
//      @tparam Operation operation to apply on each argument to apply
//      @tparam Combiner combines the individual results
//     */
//    template <class Operation, class Combiner = DefaultCombiner>
//    struct VariadicApply
//    {
//      template <class... Args>
//      struct apply;

//      template<class Arg, class... Args>
//      struct apply<Arg,Args...>
//      {
//        using Combined = Apply< Combiner , Bind<Operation,Arg>, Bind< VariadicApply<Operation,Combiner> , Args... > >;
//        using type = Apply< Combined >;
//      };

//      template <class Arg>
//      struct apply<Arg>
//      {
//        using type =  Apply<Operation,Arg>;
//      };
//    };
//  }
//}

//#endif // DUNE_TMP_FOR_EACH_HH
