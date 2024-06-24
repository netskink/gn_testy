// 
// Demo's building with a config directive
// 

#include <iostream>
#include <tuple>
#include <utility>    // c++11 forward swap is here
//#include <algorithm>  // c++98 swap is here

using namespace std;

// this requires c++11
//
// This code is from Simon Toth daily bite of c++
// medium article.
std::pair<double,int> fun() { return {4.2, 42}; }

struct Coord {
    int x;
    int y;

    // We can use std::tie to simplify some operations
    bool operator<(const Coord& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }
    bool operator==(const Coord& other) const {
        return std::tie(x, y) == std::tie(other.x, other.y);
    }
    // This swap code fails to build with the c++std17
    friend void swap(Coord& l, Coord& r) {
        std::swap(std::tie(l.x, l.y), std::tie(r.x, r.y));
    }
};


int main(int argc, char* argv[]) {

#ifdef VERBOSE
  printf("== main() ===\n");
#endif

  // Hmm. I expected this code to build with clang and it using
  // the stdc++=20 flag and not with the default gcc config
  // but it built with both compiler specifications.
  cout << "This code requires c++ std20" << endl;
  // EX4 - use of std::size requires -std=c++20
  float student_scores[] = {2.3, 4.1, 7.9, 8.2, 6.4};
  cout << "Size of array: " << std::size(student_scores) << endl;
  for (int i = 0; i < std::size(student_scores); i++) {
    cout << "student[" << i << "]:" << student_scores[i]  << endl;
  }
  cout << "Done." << endl;



    //
    // This code requires C++23
    //
    // This code fails to build when using the gcc clone.



    int x{};
    const double y{};

    // Creates a tuple of lvalue references
    auto t1 = std::tie(x, y);
    // decltype(t1) == std::tuple<int&, const double&>

    // std::tie can be used as a less elegant version
    // of structured bindings
    double i{}; int j{};
    std::tie(i,j) = fun();
    // i == 4.2, j == 42

    // std::ignore can be combined with std::tie to skip over some fields
    std::tie(std::ignore, j) = std::pair{0.0, 7};
    // i == 4.2, j == 7

    // We can use std::tie to re-use structured binding identifiers
    auto v = std::pair{4.2, 42};
    auto [m, n] = v; // copy of v
    // m == 4.2, n == 42

    std::tie(m, n) = std::pair{1.1, 2};
    // m == 1.1, n == 2

    auto& [p, q] = v; // in this case we have a reference to v
    std::tie(p, q) = std::pair{1.1, 2};
    // v == {1.1, 2}, p == 1.1, q == 2


    Coord a{1, 1}, b{1, 2};
    // (a < b) == true, (a == b) == false
    swap(a, b);
    // a == {1, 2}, b == {1, 1}




  return 0;
}
