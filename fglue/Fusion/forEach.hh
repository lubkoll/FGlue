// Copyright (C) 2015 by Lars Lubkoll. All rights reserved.
// Released under the terms of the GNU General Public License version 3 or later.

#ifndef FGLUE_FUSION_FOR_EACH_HH
#define FGLUE_FUSION_FOR_EACH_HH

#include "fglue/TMP/apply.hh"
#include "fglue/TMP/trueFalse.hh"

namespace FGlue
{
  namespace Fusion
  {
    template <class CompileTimeDecider, class Operation, class Arg, class... Args>
    auto forEach(Arg&& arg, Args&&... args)
    {
      if( isTrue< Apply<CompileTimeDecider,Arg> >() )
        Operation::apply(arg);
      forEach<CompileTimeDecider,Operation>(args...);
    }
  }
}

#endif // FGLUE_FUSION_FOR_EACH_HH
