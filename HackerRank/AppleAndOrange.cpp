// https://www.hackerrank.com/challenges/apple-and-orange/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int s, t;
  int a, b;
  int d;
  int m, n;
  int mCount = 0;
  int nCount = 0;
  cin >> s >> t;
  cin >> a >> b;
  cin >> m >> n;
  for(int i = 0; i < m; i++){
    cin >> d;
    if(a+d >= s && a+d <= t){
      mCount++;
    }
  }
  for(int i = 0; i < n; i++){
    cin >> d;
    if(b+d >= s && b+d <= t){
      nCount++;
    }
  }
  cout << mCount << endl;
  cout << nCount;
  return 0;
}
