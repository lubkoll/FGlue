
#include <utility>

template <class T>
using HasMemFn_XXX = decltype( std::declval<T>().XXX );
