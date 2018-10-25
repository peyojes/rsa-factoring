#include "../include/number.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include"../include/cxxtimer.hpp"
using std::cout;
using std::ofstream;
using std::vector;
using std::string;
using cxxtimer::Timer;

void SaveToFile(ofstream& file, const vector<string> numbers) {
  for (unsigned int it = 0; it < numbers.size(); it++) {
   file << numbers[it] << "\n";
  }
}

int main(int argc, char *argv[]) {

  if (argc != 4) {
    cout << "Wronge input parameters.\n"
         << "Usage: \tcalculate_prime_number.out begin_number end_number file\n";
    return 0;
  }

  Number begin(argv[1]);
  Number end(argv[2]);
  if (begin > end) {
    cout << "error: end number is greater than begin number\n";
    return 0;
  }


  ofstream file;
  file.open (argv[3], std::ios::out);
  if (!file.is_open()) {
    cout << "error: can not open the file with this name" << argv[3] << "\n";
    return 0;
  }

  Number actual(begin);
  if (!actual.IsPrime()) {
    actual.NextPrime();
  }
  Timer timer;
  timer.start();
  int counter = 0;
  vector<string> numbers;
  while (actual <= end) {
    numbers.push_back(actual.toString());
    actual.NextPrime();
    counter++;

    if (counter == 100) {
      counter = 0;
      cout << "Actual value: " << actual.toString() << "\n";
      SaveToFile(file, numbers);
      numbers.clear();
    }
  }
  SaveToFile(file, numbers);
  file.close();
  timer.stop();
  cout << "Time: " << timer.count<std::chrono::minutes>() << "\n";
  return 0;
}
