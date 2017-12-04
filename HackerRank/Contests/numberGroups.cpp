// https://www.hackerrank.com/contests/101hack52/challenges/number-groups/problem

#include <bits/stdc++.h>

using namespace std;

long sumOfGroup(int k) {
  long startIndex, i, sum = 0;
  for(i = 1; i < k; i++){
    startIndex += i;
  }
  for(i = startIndex; i < startIndex + k; i++){
    sum += (i * 2 + 1);
  }
  return sum;
}

int main() {
  int k;
  cin >> k;
  long answer = sumOfGroup(k);
  cout << answer << endl;
  return 0;
}
