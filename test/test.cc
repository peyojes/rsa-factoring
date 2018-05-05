#include <gtest/gtest.h>
#include "../src/prime.h"

TEST(testPrime, initianlPrime) {
//  Prime prime;
  EXPECT_EQ(0,0);
}

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
