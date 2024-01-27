#ifndef reob_H
#define reob_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

class Object { //create a class describing some real object of our world
public:
  Object(const std::string &name, double param);
  //must contain at least two data members: its name (string type) ant its characteristic parameter (age, speed, etc)
  std::string name_;
  double param_;

  bool operator==(const Object &other) const;
};

class MyPrint {//Develop a class MyPrint that would have a function call operator
// overloaded to print your class data members: the name and parameter.
public:
  void operator()(const Object &obj);
};

class MyPredicate {
public:
  MyPredicate(double value);
//create your own class for getting predicate function objects,
  bool operator()(const Object &obj);

  double value_;
};

class MyBinOp {
  //MyBinOp that provides the relevant binary operation. 
public:
  double operator()(double total, const Object &obj);
};
//create a function object of your own class MyUnOp
//for providing the relevant unary operation (for getting the parameter's values).
class MyUnOp {
public:
  double operator()(const Object &obj);
};
//class MyFunc to implement the necessary unary function operator. yi=xi-m
class MyFunc {
public:
  MyFunc(double mean);

  double operator()(double param);

  double mean_;
};



#endif