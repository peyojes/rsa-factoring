#include <iostream>
#include <string>

#include "../include/csv.h"
#include "../include/factoring_method.h"
#include "../include/fermat_rsa_factoring.h"
#include "../include/pollard_rsa_factoring.h"
#include "../include/simple_rsa_factoring.h"
#include "../include/wisniewski_rsa_factoring.h"
#include "../include/cxxtimer.hpp"

using std::cout;
using std::string;
using io::CSVReader;
using cxxtimer::Timer;
int main(int argc, char *argv[]) {
  FactoringMethod *factoring;
  if (argc != 3) {
    cout << "Wrong input parameters!\n"
              "\tusage: a.out method_factoring file.csv\n"
            "method_factoring: fermat pollard simple_beg simple_mid wisniewski\n";
    return 0;
  }
  string method_factoring(argv[1]);

  FermatRsaFactoring fermat_rsa_factoring;
  PollardRsaFactoring pollard_rsa_factoring;
  SimpleRsaFactoringStartingFromBeginning simple_factoring_beg;
  SimpleRsaFactoringStartingFromMiddle simple_factoring_mid;
  WisniewskiRsaFactoring wisniewski_rsa_factoring;

  if (method_factoring == "fermat") {
    factoring = &fermat_rsa_factoring;
  } else if (method_factoring == "pollard") {
    factoring = &pollard_rsa_factoring;
  } else if (method_factoring == "simple_beg") {
    factoring = &simple_factoring_beg;
  } else if (method_factoring == "simple_mid") {
    factoring = &simple_factoring_mid;
  } else if (method_factoring == "wisniewski") {
    factoring = &wisniewski_rsa_factoring;
  } else {
    cout << "Wronge name of factoring method\n";
    return 0;
  }
  Timer timer;
  CSVReader<3> in(argv[2]);
  in.read_header(
        io::ignore_extra_column, "rsa_number","p", "q");
  string rsa_number, p, q;
  while (in.read_row(rsa_number, p, q)) {
    timer.reset();
    timer.start();
    factoring->SetModulus(rsa_number);
    factoring->Factoring();
    timer.stop();
    cout << "It has taken " << timer.count<std::chrono::seconds>() << " seconds." << std::endl;
    cout << "P: " << p << "\t" << factoring->GetP() << "\n";
    cout << "Q: " << q << "\t" << factoring->GetQ() << "\n";
//    cout << rsa_number << "\t" << p << "\t" << q << "\n";
  }
  return 0;
}
