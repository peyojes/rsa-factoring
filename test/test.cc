#include <gtest/gtest.h>
#include "../include/prime.h"

TEST(initial, empty) {
  Prime prime;
  EXPECT_EQ(0,prime.toInt());
}

TEST(initial, integer) {
  Prime prime(1);
  EXPECT_EQ(1,prime.toInt());
}

TEST(initial, string) {
  Prime prime("0");
  EXPECT_EQ(0, prime.toInt());
}

TEST(multiplication, integer) {
  Prime prime(2);
  prime *= 2;
  EXPECT_EQ(4, prime.toInt());
}

TEST(multiplication, Prime) {
  Prime prime(2);
  prime *= prime;
  EXPECT_EQ(4, prime.toInt());
//  prime = prime * prime;
//  EXPECT_EQ(16, prime.get_si());
}

//TEST(EulerFunction, integer) {
//  Prime prime(3);
//  prime.EulerFunction(4);
//  EXPECT_EQ(6, prime.get_si());
//}

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
