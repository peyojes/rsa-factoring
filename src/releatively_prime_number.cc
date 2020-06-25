/**
  * @name releatively_prime_number.cc
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
#include <string>
#include <iostream>

#include "../include/number.h"

using std::string;
using std::cout;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Wrong input parameters!\n"
              "\tusage: a.out number\n";
    return 0;
  }
  string str_number = argv[1];
  Number number(str_number), it(2);
  unsigned int count = 0;
  cout << "Start program\nInput pram is: " << number << "\n";
  for (; it < number; it++) {
    if (number.IsRelativelyPrime(it)) {
      cout << it << "\n";
      count++;
    }
  }
  cout << "\nFinished program. " << count << " number are relatively prime\n";
}
