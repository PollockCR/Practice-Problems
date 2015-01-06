// https://www.hackerrank.com/challenges/countingsort3

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
    cin.ignore(256, '\n');
  }
  countVals( a );
  return 0;
}

void countVals( vector<int> &a ){
  vector<int> b (100, 0);
  int val;
  vector<int>::iterator it;
  int i, j, total = 0;
  for( it = a.begin(); it != a.end(); it++ ){
    b[*it]++;
  }
  for( i = 0; i < b.size(); i++ ){
    total += b[i];
    cout << total << ' ';
  }
}

