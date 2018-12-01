#include <string>
#include <iostream>

#include "../include/number.h"

using std::string;
using std::cout;

int main(int argc, char **argv) {

  if (argc != 3) {
    cout << "Wrong input parameters!\n"
              "\tusage: a.out number number\n";
    return 0;
  }
  string str_number(argv[1]), str_number2(argv[2]);
  Number number(str_number), number2(str_number2), it(2);
  cout << "Result: " << number * number2 << "\n";
  return 0;
}
