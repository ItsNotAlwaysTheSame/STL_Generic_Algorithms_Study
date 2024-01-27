#include "reOb.h"

  Object::Object(const std::string &name, double param) : name_(name), param_(param) {}

bool Object::operator==(const Object &other) const {//operator == must be overloaded for names
    return name_ == other.name_;
  }

void MyPrint::operator()(const Object &obj) {
    std::cout << "Name: " << obj.name_ << ", Param: " << obj.param_ << std::endl;
  }

  MyPredicate ::MyPredicate(double value) : value_(value) {}

bool MyPredicate :: operator()(const Object &obj) {
    return obj.param_ > value_;
  }

  double MyBinOp :: operator()(double total, const Object &obj) {
    return total + obj.param_;
  }

  
  double MyUnOp::operator()(const Object &obj) {
    return obj.param_;
  }

  MyFunc ::MyFunc(double mean) : mean_(mean) {}

  double MyFunc ::operator()(double param) {
    return param - mean_;
  }