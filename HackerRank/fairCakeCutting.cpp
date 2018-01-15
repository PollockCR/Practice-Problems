// https://www.hackerrank.com/contests/101hack51/challenges/fair-cake-cutting/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  double num, denom, a, piece;
  int peeps;
  cin >> num >> denom >> a;
  piece = num / denom;
  peeps = int(a / piece);
  cout << peeps;
  return 0;
}
