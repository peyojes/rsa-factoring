/**
  * @name main_test.cc
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
#include <gtest/gtest.h>

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
