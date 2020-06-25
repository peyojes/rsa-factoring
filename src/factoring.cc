/**
  * @name factoring.cc
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>

#include "../include/csv.h"
#include "../include/factoring_method.h"
#include "../include/fermat_rsa_factoring.h"
#include "../include/pollard_rsa_factoring.h"
#include "../include/simple_rsa_factoring.h"
#include "../include/wisniewski_rsa_factoring.h"
#include "../include/pollard_with_wisniewski_rsa_factoring.h"
#include "../include/cxxtimer.hpp"

using std::cout;
using std::string;
using io::CSVReader;
using cxxtimer::Timer;
using std::chrono::seconds;

const string CurrentDateTime();

class FactoringResult {
 public:
  FactoringResult(const Number& modulus, const Number& p, const Number& q,
                  const int64_t time);
  string GetLineToCsv();
 private:
  Number modulus_;
  Number p_;
  Number q_;
  int64_t time_;
};

class FileSaver {
 public:
  void SetFileName(const std::string& file);
  void SaveToFile(std::vector<FactoringResult>& results);
 private:
  string file_;
};

int main(int argc, char *argv[]) {
  FactoringMethod *factoring;
  if (argc != 4) {
    cout << "Wrong input parameters!\n"
              "\tusage: a.out method_factoring file.csv save_flag\n"
            "method_factoring: fermat pollard simple_beg simple_mid wisniewski "
            "pollard_wisniewski\n"
            "save_flag: true or false\n";
    return 0;
  }
  string method_factoring(argv[1]);

  FermatRsaFactoring fermat_rsa_factoring;
  PollardRsaFactoring pollard_rsa_factoring;
  SimpleRsaFactoringStartingFromBeginning simple_factoring_beg;
  SimpleRsaFactoringStartingFromMiddle simple_factoring_mid;
  WisniewskiRsaFactoring wisniewski_rsa_factoring;
  PollardWithWisniewskiRsaFactoring pollard_with_wisniewski_factoring;

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
  } else if (method_factoring == "pollard_wisniewski") {
    factoring = &pollard_with_wisniewski_factoring;
  } else {
    cout << "Wronge name of factoring method\n";
    return 0;
  }
  bool save_to_file = false;
  string save_flag(argv[3]);
  if (save_flag == "true") {
    save_to_file = true;
  }
  Timer timer;
  CSVReader<3> in(argv[2]);
  in.read_header(
        io::ignore_extra_column, "rsa_number", "p", "q");
  string rsa_number, p, q;
  std::vector<FactoringResult> results;
  FileSaver file_saver;

  string file_name = method_factoring + "_" + CurrentDateTime() + ".csv";
  file_saver.SetFileName(file_name);
  while (in.read_row(rsa_number, p, q)) {
    timer.reset();
    timer.start();
    factoring->SetModulus(rsa_number);
    factoring->Factoring();
    timer.stop();
    FactoringResult result(rsa_number, factoring->GetP(), factoring->GetQ(),
                           timer.count<seconds>());
    results.push_back(result);
    cout << "It has taken " << timer.count<std::chrono::seconds>()
         << " seconds." << std::endl;
    cout << "P: " << p << "\t" << factoring->GetP() << "\n";
    cout << "Q: " << q << "\t" << factoring->GetQ() << "\n";
    cout << "current data time " << CurrentDateTime() << "\n";
    if (save_to_file) {
      file_saver.SaveToFile(results);
    }
  }

  return 0;
}

const string CurrentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct, result;
    char buf[80];
    tstruct = *localtime_r(&now, &result);
    strftime(buf, sizeof(buf), "%d-%m-%Y_%X", &tstruct);

    return buf;
}

FactoringResult::FactoringResult(const Number &modulus,
    const Number &p, const Number &q, const int64_t time) {
  modulus_ = modulus;
  p_ = p;
  q_ = q;
  time_ = time;
}

std::string FactoringResult::GetLineToCsv() {
  string result = modulus_.toString() + "," + p_.toString() + "," +
      q_.toString() + "," + std::to_string(time_);
  return result;
}

void FileSaver::SetFileName(const std::string &file) {
  file_ = file;
}

void FileSaver::SaveToFile(std::vector<FactoringResult> &results) {
  std::ofstream output_file(file_);
  if (output_file.is_open()) {
    output_file << "rsa_number,p,q,time\n";
    for (FactoringResult result : results) {
      output_file << result.GetLineToCsv() + "\n";
    }
    output_file.close();
  }
}
