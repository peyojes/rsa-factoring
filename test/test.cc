#include <gtest/gtest.h>
#include "../include/number.h"

TEST(Number, emptyInitialization) {
  Number num;
  EXPECT_EQ(0, num.toInt());
}

TEST(Number, integerInitialization) {
  Number num(0);
  EXPECT_EQ(0, num.toInt());
}


TEST(Number, stringInitialization) {
  Number num("0");
  EXPECT_EQ(0, num.toInt());
}

TEST(Number, IsPrime) {
  Number num(23);
  EXPECT_TRUE(num.IsPrime());
}


GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
