// https://www.hackerrank.com/challenges/birthday-cake-candles/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
  int maxCandle;
  int maxCandleCount = 0;
  int numCandles;
  int tempCandle;
  cin >> numCandles;
  for(int i = 0; i < numCandles; i++)
  {
    cin >> tempCandle;
    if(i == 0){
      maxCandle = tempCandle;
    }
    if(maxCandle == tempCandle){
      maxCandleCount++;
    } else if(maxCandle < tempCandle){
      maxCandle = tempCandle;
      maxCandleCount = 1;
    }
  }
  cout << maxCandleCount;
  return 0;
}
