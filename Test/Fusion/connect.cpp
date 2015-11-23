#include <gtest/gtest.h>
#include <vector>

#include "fglue/Fusion/connect.hh"

using namespace FGlue;

struct TestData
{
  void setValue(int value)
  {
    value_ = value;
    for(auto* connection : connected_)
      connection->setValue(value_);
  }

  int getValue() const
  {
    return value_;
  }

  void attach(TestData& other)
  {
    connected_.push_back(&other);
  }

private:
  int value_ = 0;
  std::vector<TestData*> connected_;
};

struct A : TestData{};
struct B{};
struct C
{
  A a;
};

struct D
{
  B b;
};

TEST(Fusion,Connect)
{
  A a0, a1, a2;
  B b;

  ASSERT_EQ( a0.getValue() , 0 );
  Connector< IsDerivedFrom<TestData> >::from(a0).to(a1,a2,b);

  a0.setValue(2);
  ASSERT_EQ( a0.getValue() , 2 );
  ASSERT_EQ( a1.getValue() , 2 );
  ASSERT_EQ( a2.getValue() , 2 );
}
