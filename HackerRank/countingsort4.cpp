// https://www.hackerrank.com/challenges/countingsort4

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void countVals( vector<int> &, vector<string> & );

int main() {
  vector<int> a;
  vector<string> aS;
  int numVals, i, val;
  string temp;
  cin >> numVals;
  for( i = 0; i < numVals; i++){
    cin >> val;
    a.push_back(val);
    cin >> temp;
    if( i < numVals/2 ){
      aS.push_back("-");
    } else {
      aS.push_back(temp);
    }
  }
  countVals( a, aS );
  return 0;
}

void countVals( vector<int> &a, vector<string> &aS ){
  vector< vector<string> > strs ( 100, vector<string>(0) );
  int val;
  vector<int>::iterator it;
  int i, j, total = 0;
  for( i = 0; i < a.size(); i++ ){
    strs[ a[i] ].push_back( aS[i] );
  }
  for( i = 0; i < strs.size(); i++ ){
    for( j = 0; j < strs[i].size(); j++ ){
      cout << strs[i][j] << ' ';
    }
  }
}

