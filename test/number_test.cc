#include <gtest/gtest.h>
#include "../include/number.h"

TEST(Number, emptyInitialization) {
  Number num;
  EXPECT_EQ(0, num.toInt());
}

TEST(Number, integerInitialization) {
  Number num(1);
  EXPECT_EQ(1, num.toInt());
}


TEST(Number, stringInitialization) {
  Number num("1");
  EXPECT_EQ(1, num.toInt());
}

TEST(Number, numberInitialization) {
  Number num(3);
  Number num2(num);
  EXPECT_EQ(3, num2.toInt());
}

TEST(Number, IsPrime) {
  Number num(23);
  EXPECT_TRUE(num.IsPrime());
}

TEST(Number, IsPrime3) {
  Number num(3);
  EXPECT_TRUE(num.IsPrime());
}

TEST(Number, IsPrime4) {
  Number num(4);
  EXPECT_FALSE(num.IsPrime());
}

TEST(Number, IsPrime20False) {
  Number num("20");
  EXPECT_FALSE(num.IsPrime());
}

TEST(Number, NextPrime4) {
  Number num(4);
  num.NextPrime();
  EXPECT_EQ(5, num.toInt());
}

TEST(Number, NextPrime25) {
  Number num(25);
  num.NextPrime();
  EXPECT_EQ(29, num.toInt());
}

TEST(Number, IsReletivelyPrime9and16) {
  Number num9(9), num16(16);
  EXPECT_TRUE(num16.IsRelativelyPrime(num9));
  EXPECT_TRUE(num9.IsRelativelyPrime(num16));
}

TEST(Number, IsReletivelyPrimeFalse14and21) {
  Number num14(14), num21(21);
  EXPECT_FALSE(num14.IsRelativelyPrime(num21));
  EXPECT_FALSE(num21.IsRelativelyPrime(num14));
}

TEST(Number, IsReletivelyPrimeFalse2and14) {
  Number num14(14), num2(2);
  EXPECT_FALSE(num14.IsRelativelyPrime(num2));
  EXPECT_FALSE(num2.IsRelativelyPrime(num14));
}
