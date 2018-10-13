#ifndef RSA_DATA_HPP_
#define RSA_DATA_HPP_

#include "number.h"

#include<iostream>

class RsaData {
 public:
  RsaData();
  RsaData(const Number &p, const Number &q);

  Number GetP() const;
  Number GetQ() const;
  Number GetPublicKey() const;
  Number GetPrivateKey() const;
  Number GetValueOfEulerFunction() const;
  Number GetModulus() const;
  void SetModulus(const Number& mod);

protected:
  void FindPrivateKey();
  void CalculateEulerFunction();
  Number public_key_;

private:
  Number p_;
  Number q_;
  Number value_of_euler_fun_;
  Number private_key_;
  Number modulus_;
};

RsaData::RsaData(): p_(kZero), q_(kZero), value_of_euler_fun_(kZero),
  public_key_(kZero), private_key_(kZero), modulus_(kZero) {
}

RsaData::RsaData(const Number &p, const Number &q)
  :p_(p), q_(q), value_of_euler_fun_((p-1)*(q-1)), modulus_(p*q) {

  Number it = value_of_euler_fun_ / kTwo;
  for (; it < value_of_euler_fun_; it++) {
    if (it.IsRelativelyPrime(value_of_euler_fun_) &&
        ((it*it) % value_of_euler_fun_) != 1) {
      public_key_ = it;
      FindPrivateKey();
      break;
    }
  }
}

inline Number RsaData::GetP() const {
  return p_;
}

inline Number RsaData::GetQ() const {
  return q_;
}

inline Number RsaData::GetPublicKey() const {
  return public_key_;
}

inline Number RsaData::GetPrivateKey() const {
  return private_key_;
}

inline Number RsaData::GetValueOfEulerFunction() const {
  return value_of_euler_fun_;
}

inline Number RsaData::GetModulus() const {
  return modulus_;
}

inline void RsaData::SetModulus(const Number &mod) {
  modulus_ = mod;
}

inline void RsaData::FindPrivateKey() {
  if (value_of_euler_fun_ == 0 || public_key_ == 0) {
    std::cout << "Wronge input params(public_key or value_of_euler_fun is 0)"
                 "in function FindPrivateKey\n";
    return;
  }

  Number it(3);
  for (; it < value_of_euler_fun_; it++) {
    if (((public_key_ * it) % value_of_euler_fun_) == 1) {
      private_key_ = it;
      break;
    }
  }

  if (private_key_ == 0) {
    std::cout << "RsaData: Don't find private key.\n";
    return;
  }
}

void RsaData::CalculateEulerFunction() {
  if (p_ == 0 || q_ == 0) {
    std::cout << "RsaData: Wronge input params(p_ or q_ is 0) in "
                 "CalculateEulerFunction function\n";
  }

  value_of_euler_fun_ = (p_ - 1) * (q_ - 1);
}

#endif  // RSA_DATA_HPP_
