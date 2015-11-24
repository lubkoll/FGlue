// Copyright (C) 2015 by Lars Lubkoll. All rights reserved.
// Released under the terms of the GNU General Public License version 3 or later.

#include <gtest/gtest.h>

#include "fglue/Fusion/castAndAttach.hh"
#include "fglue/Fusion/applyIf.hh"
#include "fglue/TMP/constant.hh"
#include "fglue/TMP/trueFalse.hh"

#include "setup.hh"

using namespace FGlue;
using namespace FGlue::Fusion;

TEST(Fusion,CastAndAttach)
{
  A a, c;
  CastAndAttach<TestData> castAndAttach(c);

  castAndAttach(a);

  EXPECT_EQ( a.getValue() , 0 );
  c.setValue(2);
  EXPECT_EQ( a.getValue() , 2 );
}

TEST(Fusion,CastAndDetach)
{
  A a, c;
  CastAndAttach<TestData> castAndAttach(c);
  CastAndDetach<TestData> castAndDetach(c);

  castAndAttach(a);
  castAndAttach(a);

  EXPECT_EQ( a.getValue() , 0 );
  c.setValue(2);
  EXPECT_EQ( a.getValue() , 2 );

  castAndDetach(a);
  c.setValue(3);
  EXPECT_EQ( c.getValue() , 3 );
  EXPECT_EQ( a.getValue() , 2 );
}

TEST(Fusion,UnaryApplyIf)
{
  A a, c_true, c_false;
  UnaryApplyIf< CastAndAttach<TestData> , Constant<True> > castAndAttach_true(c_true);
  UnaryApplyIf< CastAndAttach<TestData> , Constant<False> > castAndAttach_false(c_false);

  castAndAttach_true(a);
  castAndAttach_false(a);

  EXPECT_EQ( a.getValue() , 0 );
  c_true.setValue(2);
  EXPECT_EQ( a.getValue() , 2 );
  c_false.setValue(3);
  EXPECT_EQ( a.getValue() , 2 );
}
