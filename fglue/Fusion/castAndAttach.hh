// Copyright (C) 2015 by Lars Lubkoll. All rights reserved.
// Released under the terms of the GNU General Public License version 3 or later.

#ifndef FGLUE_FUSION_CAST_AND_ATTACH_HH
#define FGLUE_FUSION_CAST_AND_ATTACH_HH

#include "fglue/TMP/apply.hh"
#include "fglue/TMP/constant.hh"
#include "fglue/TMP/trueFalse.hh"

namespace FGlue
{
  namespace Fusion
  {
    template <class Source, class Decider = Constant<True> >
    struct CastAndAttach
    {
      CastAndAttach(Source& source)
        : source_(source)
      {}

      template <class Target>
      void operator()(Target& target)
      {
        if( isTrue< Apply<Decider,Source> >() )
          source_.attach(static_cast<Source&>(target));
      }

    private:
      Source& source_;
    };


    template <class Source, class Decider = Constant<True> >
    struct CastAndDetach
    {
      CastAndDetach(Source& source)
        : source_(source)
      {}

      template <class Target>
      void operator()(Target& target)
      {
        if( isTrue< Apply<Decider,Source> >() )
          source_.attach(static_cast<Source&>(target));
      }

    private:
      Source& source_;
    };
  }
}

#endif // FGLUE_FUSION_CAST_AND_ATTACH_HH
