# Prime

## Prerequisites

You need to install gmp library. You can install it on Ubuntu with this command:
```
sudo apt-get install libgmp-dev
```

If you want run tests you need gtest library and cmake. You can install it on Ubuntu:

```
sudo apt-get install libgtest-dev
sudo add-apt-repository ppa:george-edison55/cmake-3.x
sudo apt-get update
sudo apt-get install cmake
```

## Run tests

If you want run tests you type this commands:
```
cd test 
cd cmake CMakeLists.txt
make
./runTests
```
