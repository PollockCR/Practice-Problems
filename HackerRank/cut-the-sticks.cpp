// https://www.hackerrank.com/challenges/cut-the-sticks

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void cutSticks( vector<int> );

int main() {
  int numSticks, i, temp;
  vector<int> sticks;
  cin >> numSticks;
  for( i = 0; i < numSticks; i++ ){
    cin >> temp;
    sticks.push_back( temp );
  }
  cutSticks( sticks );
  return 0;
}

void cutSticks( vector<int> sticks ){
  if( !sticks.empty() ){
    cout << sticks.size() << endl;
    vector<int> newSticks;
    int sticksMin, i, temp;
    sticksMin = *(min_element(sticks.begin(), sticks.end()));
    for( i = 0; i < sticks.size(); i++ ){
      temp = sticks[i];
      if( temp - sticksMin > 0 ){
        newSticks.push_back( temp - sticksMin );
      }
    }
    cutSticks( newSticks );
  }
}


