#include <gtest/gtest.h>

#include <vector>

#include "fglue/Macro/generateHasMemberCheck.hh"

GENERATE_MEM_FN_CHECK(setValue)
GENERATE_MEM_FN_CHECK(getValue)

#define GENERATE_OPTIONAL_CONNECTION(NAME) \
template <class Source, class Target, bool connectable = HasMemFn_set##NAME<Target>::value && HasMemFn_get##NAME<Source>::value> \
struct ConnectIfPossible \
{ \
  static void apply(const Source&, const Target&) \
  {} \
}; \
 \
template <class Source, class Target> \
struct ConnectIfPossible<Source,Target,true> \
{ \
  static void apply(Source& source, Target& target) \
  { \
    source.attach(target); \
  } \
}; \
 \
template <class Source, class Target> \
void connectIfPossible(Source& source, Target& target) \
{ \
  ConnectIfPossible<Source,Target>::apply(source,target); \
}

GENERATE_OPTIONAL_CONNECTION(Value)

//GENERATE_HAS_MEM_FN_CHECK(setValue)
//GENERATE_SETTER_PRESENCE_CHECK(Value)

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

template <class T>
auto generateSetterCheckValue()
{
  return HasMemFn_setValue<T>::value;
}

template <class T>
auto generateGetterCheckValue()
{
  return HasMemFn_getValue<T>::value;
}

TEST(Macro,GenerateSetterCheck)
{
  auto AhasSetter = generateSetterCheckValue<TestData>();
  ASSERT_TRUE(AhasSetter);
  auto BhasSetter = generateSetterCheckValue<B>();
  ASSERT_FALSE(BhasSetter);
}

TEST(Macro,GenerateGetterCheck)
{
  auto AhasGetter = generateGetterCheckValue<A>();
  ASSERT_TRUE(AhasGetter);
  auto BhasGetter = generateGetterCheckValue<B>();
  ASSERT_FALSE(BhasGetter);
}

TEST(Macro,ConnectConnectable)
{
  A a0, a1;
  a1.setValue(1);
  ASSERT_EQ( a0.getValue() , 0 );
  ASSERT_EQ( a1.getValue() , 1 );

  connectIfPossible(a0,a1);
  a0.setValue(2);
  ASSERT_EQ( a0.getValue() , 2 );
  ASSERT_EQ( a1.getValue() , 2 );
}

#include "fglue/Macro/undef.hh"
