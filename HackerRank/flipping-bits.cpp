// https://www.hackerrank.com/challenges/flipping-bits

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long int calcFlip( unsigned long int );

int main() {
  int numLines, i;
  unsigned long int num;
  cin numLines;
  while( numLines > 0 ){
    cin >> num;
    cout << calcFlip( num ) << endl;
    numLines--;
  }
  return 0;
}

unsigned long int calcFlip( unsigned long int val ){
  return 4294967295 - val;
}
