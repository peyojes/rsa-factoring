cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests test.cc 
		../lib/cbignum/Cbignum.cpp
		../lib/cbignum/Cbignum.h
		../lib/cbignum/Cbignumf.cpp
		../lib/cbignum/Cbignumf.h
		../lib/cbignum/Exarray.h
		../lib/cbignum/Exarray.cpp
)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread -lgmpxx -lgmp)
