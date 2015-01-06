// https://www.hackerrank.com/challenges/countingsort2

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void countVals( vector<int> & );

int main() {
  vector<int> a;
  int numVals, i, val;
  cin >> numVals;
  for( i = 0; i < numVals; i++){
    cin >> val;
    a.push_back(val);
  }
  countVals( a );
  return 0;
}

void countVals( vector<int> &a ){
  vector<int> b (100, 0);
  int val;
  vector<int>::iterator it;
  int i, j;
  for( it = a.begin(); it != a.end(); it++ ){
    b[*it]++;
  }
  for( i = 0; i < b.size(); i++ ){
    for( j = 0; j < b[i]; j++){
      cout << i << ' ';
    }
  }
}
