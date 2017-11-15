// https://www.hackerrank.com/contests/w35/challenges/triple-recursion

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n, m, k, i, j;
  cin >> n >> m >> k;
  vector<vector<int>> trip;
  trip.reserve(n);
  for(i = 0; i < n; i++){
    trip[i].reserve(n);
    if(i == 0){
      // case 1: i = 0, j = 0
      trip[0][0] = m;
    } else {
      // case 2: i = j
      trip[i][i] = trip[i-1][i-1]+k;
    }
  }

  // case 3: i > j
  for(j = 0; j < n; j++){
    for(i = j + 1; i < n; i++){
      trip[i][j] = trip[i-1][j]-1;
    }
  }

  // case 4: i < j
  for(i = 0; i < n; i++){
    for(j = i + 1; j < n; j++){
      trip[i][j] = trip[i][j-1]-1;
    }
  }

  // print matrix
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      cout << trip[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
