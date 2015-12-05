#include <gtest/gtest.h>
#include <vector>

// Copyright (C) 2015 by Lars Lubkoll. All rights reserved.
// Released under the terms of the GNU General Public License version 3 or later.

#include "fglue/TMP/isDerivedFrom.hh"
#include "fglue/Fusion/connect.hh"

#include "setup.hh"

using namespace FGlue;

TEST(Fusion,Connect)
{
  A a0, a1, a2;
  B b;

  ASSERT_EQ( a0.getValue() , 0 );
  Connector< IsDerivedFrom<TestData> >::from<TestData>(a0).to(a1,a2,b);

  a0.setValue(2);
  ASSERT_EQ( a0.getValue() , 2 );
  ASSERT_EQ( a1.getValue() , 2 );
  ASSERT_EQ( a2.getValue() , 2 );
}

TEST(Fusion,Deconnect)
{
  A a0, a1, a2;
  B b;

  ASSERT_EQ( a0.getValue() , 0 );
  Connector< IsDerivedFrom<TestData> >::from<TestData>(a0).to(a1,a2,b);

  a0.setValue(2);
  ASSERT_EQ( a0.getValue() , 2 );
  ASSERT_EQ( a1.getValue() , 2 );
  ASSERT_EQ( a2.getValue() , 2 );

  Deconnector< IsDerivedFrom<TestData> >::from<TestData>(a0).to(a1,b);

  a0.setValue(3);
  ASSERT_EQ( a0.getValue() , 3 );
  ASSERT_EQ( a1.getValue() , 2 );
  ASSERT_EQ( a2.getValue() , 3 );
}
