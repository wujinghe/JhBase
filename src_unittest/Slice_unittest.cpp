#include "JhBase/Slice.h"
#include "gtest/gtest.h"

using JhBase::Slice;

TEST(SliceTest, Construction)
{
    Slice s;
    EXPECT_EQ(0, s.size());
    EXPECT_EQ(NULL, s.data());

    const std::string kHello = "hello";
    Slice str(kHello);
    EXPECT_EQ(kHello.length(), str.size());
    EXPECT_STREQ(kHello, str.data);
}
