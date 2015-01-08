// https://www.hackerrank.com/challenges/cavity-map

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int dim, i, j;
  char temp;
  cin >> dim;
  char nums[dim][dim];
  for( i = 0; i < dim; i++){
    for( j = 0; j < dim; j++ ){
      cin >> temp;
      nums[i][j] = temp;
    }
  }
  for( i = 1; i < dim - 1; i++ ){
    for( j = 1; j < dim - 1; j++ ){
      temp = nums[i][j];
      if( nums[i-1][j] < temp && nums[i+1][j] < temp
       && nums[i][j+1] < temp && nums[i][j-1] < temp ){
        nums[i][j] = 'X';
      }
    }
  }
  for( i = 0; i < dim; i++ ){
    for( j = 0; j < dim; j++ ){
      cout << nums[i][j];
    }
    cout << endl;
  }
  return 0;
}



