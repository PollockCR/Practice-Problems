// https://www.hackerrank.com/contests/w35/challenges/3d-surface-area

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int h, w, i, j;
  int area = 0;
  cin >> h >> w;
  vector<vector<int>> heights(h);
  // read in and determine individual surface area
  for(i = 0; i < h; i++){
    heights[i].reserve(w);
    for(j = 0; j < w; j++){
      cin >> heights[i][j];
      area += ((heights[i][j] * 4) + 2);
    }
  }
  // subtract overlap from same row
  for(i = 0; i < h; i++){
    for(j = 1; j < w; j++){
      area -= (2 * min(heights[i][j-1], heights[i][j]));
    }
  }
  // subtract overlap from same column
  for(i = 1; i < h; i++){
    for(j = 0; j < w; j++){
      area -= (2 * min(heights[i-1][j], heights[i][j]));
    }
  }
  cout << area;
  return 0;
}
