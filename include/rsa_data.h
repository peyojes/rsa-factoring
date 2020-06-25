/**
  * @name rsa_data.h
  * @author Pawel Jesionkowski
  * @copyright Copyright 2018 Pawel Jesionkowski. All rights reserved.
  */
#ifndef RSA_DATA_HPP_
#define RSA_DATA_HPP_

#include<iostream>

#include "number.h"

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
  void SetPublicKey(const Number& public_key);

 protected:
  void FindPrivateKey();
  void CalculateEulerFunction();
  Number private_key_;
  Number p_;
  Number q_;

 private:
  Number value_of_euler_fun_;
  Number public_key_;
  Number modulus_;
};

inline RsaData::RsaData(): p_(kZero), q_(kZero), value_of_euler_fun_(kZero),
  public_key_(kZero), private_key_(kZero), modulus_(kZero) {
}

inline RsaData::RsaData(const Number &p, const Number &q)
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

inline void RsaData::SetPublicKey(const Number &public_key) {
  public_key_ = public_key;
}

inline void RsaData::FindPrivateKey() {
  if (value_of_euler_fun_ == 0 || public_key_ == 0) {
    std::cout << "Wronge input params(public_key or value_of_euler_fun is 0)"
                 "in FindPrivateKey function\n";
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

inline void RsaData::CalculateEulerFunction() {
  if (p_ == 0 || q_ == 0) {
    std::cout << "RsaData: Wronge input params(p_ or q_ is 0) in "
                 "CalculateEulerFunction function\n";
  }

  value_of_euler_fun_ = (p_ - 1) * (q_ - 1);
}

#endif  // RSA_DATA_HPP_
