#include <string>
#include <iostream>

#include "../include/number.h"

using std::string;
using std::cout;

int main(int argc, char **argv) {

  if (argc != 3) {
    cout << "Wrong input parameters!\n"
              "\tusage: a.out public_key value_of_euler_function\n";
    return 0;
  }
  string str_public_key = argv[1];
  string str_val_of_euler_func = argv[2];
  Number public_key(str_public_key),
         val_of_eul_fun(str_val_of_euler_func),
         it(2);
  cout << "Start program\n"
            "\tPublic key is: " << public_key << "\n"
            "\tValue of Euler function is: " << val_of_eul_fun << "\n";
  for (; it < val_of_eul_fun; it++) {
    if (((public_key * it) % val_of_eul_fun) == 1) {
      cout << "\nPrivate key is: " << it << "\n";
      break;
    }
  }
  cout << "\nFinished program.\n";

}
