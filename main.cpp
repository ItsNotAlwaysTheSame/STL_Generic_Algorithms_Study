#include "reOb.h"

int main() {
  Object objects[] = { 
  // Create an array of objects of the designed class. 
  //Parameter's values may be defined at random.
    Object("John", 20),
    Object("Jane", 30),
    Object("Jim", 25),
    Object("Jack", 35),

  };
  //Create a vector of objects of the designed class by applying the parameterized constructor
  //   and copying the array's contents into the vector.
  std::vector<Object> v(objects, objects + sizeof(objects) / sizeof(Object));
  //Apply the generic algorithm for_each to print the vector contents.
  std::cout << "Vector Contents:" << std::endl;
  std::for_each(v.begin(), v.end(), MyPrint());//template< class InputIt, class UnaryFunction >
                                               //UnaryFunction for_each( InputIt first, InputIt last, UnaryFunction f );

//Find the first object in the vector whose parameter would be greater than a prescribed value.
  std::cout << "First Object with param greater than 30:" << std::endl;
  auto it = std::find_if(v.begin(), v.end(), MyPredicate(30));//template< class InputIt, class UnaryPredicate >
                                                              //InputIt find_if( InputIt first, InputIt last, UnaryPredicate p );

  if (it != v.end()) {
    MyPrint()(*it);
  }
//Try to find objects having the same names and being placed in your sequence successively. 
//Apply the algorithm adjacent_find, and print the first such an object if any.
  std::cout << "Adjacent Objects with same name:" << std::endl;
  it = std::adjacent_find(v.begin(), v.end()); //template< class ForwardIt >
                                              //ForwardIt adjacent_find( ForwardIt first, ForwardIt last );
  if (it != v.end()) {//If no such adjacent pair exists, the function returns the iterator last
    MyPrint()(*it);
  }
//Try to check the equality of the contents of your original array and the vector, applying the algorithm equal.
  std::cout << "Array and Vector contents equal? ";
  if (std::equal(objects, objects + sizeof(objects) / sizeof(Object), v.begin())) {//template< class InputIt1, class InputIt2 >
                                                                                  //bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 );
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
//Apply the algorithm search to establish location of the arbitrary subsequence in the vector range. 
//Define this subsequence as a part of the array. Print the subsequence found.
  std::cout << "Subsequence in Vector:" << std::endl;
  it = std::search(v.begin(), v.end(), objects + 1, objects + 3); //template< class ForwardIt1, class ForwardIt2 >
                                                                  //ForwardIt1 search( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last );
  if (it != v.end()) {
    std::for_each(it, it + 2, MyPrint());
  }
//Apply the algorithm accumulate in order to calculate the average (mean) value of
// the parameter data member of the vector's elements.
  std::cout << "Mean of paramters: " << std::endl;
double mean = std::accumulate(v.begin(), v.end(), double(), MyBinOp()) / v.size(); //template< class InputIt, class T, class BinaryOperation >
                                                                                    //T accumulate( InputIt first, InputIt last, T init, BinaryOperation op );
std::cout << mean << std::endl;
//Create a new vector v2 of double values with the same size as the original one, and fill in it 
//with the parameter values from the first vector. You should use the algorithm transform
std::cout << "Vector of parameter values: " << std::endl;
std::vector<double> v2(v.size());
std::transform(v.begin(), v.end(), v2.begin(), MyUnOp());//template< class InputIt, class OutputIt, class UnaryOperation >
                                                        //OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op );
for (const auto& val : v2) {
std::cout << val << " ";
}
std::cout << std::endl;
//Replace all old values xi of the vector v2 with the new ones yi = xi - m, where m is the mean value
std::cout << "Modified Vector of parameter values: " << std::endl;
std::transform(v2.begin(), v2.end(), v2.begin(), MyFunc(mean)); //unary_op
for (const auto& val : v2) {
std::cout << val << " ";
}
std::cout << std::endl;
//Sort the contents of v2 in ascending order. Apply the sort algorithm and print the result.
std::cout << "Sorted Vector of parameter values: " << std::endl;
std::sort(v2.begin(), v2.end()); //template< class RandomIt >
                                  //void sort( RandomIt first, RandomIt last );
for (const auto& val : v2) {
std::cout << val << " ";
}
std::cout << std::endl;

return 0;
}