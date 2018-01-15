// https://www.hackerrank.com/contests/101hack52/challenges/construct-the-array/problem
#include <iostream>
using namespace std;

long tryNums(int n, int k, int x, int i, int prev){
  int j;
  int numWays = 0;
  if(i == n-1){
    return 1;
  }
  for(j = 1; j <= k; j++){
    if(j != prev){
      if(i == n-2){
        if(j != x){
          numWays += tryNums(n, k, x, i+1, j);
        }
      } else {
        numWays += tryNums(n, k, x, i+1, j);
      }
    }
  }
  return (long)numWays;
}

long countArray(int n, int k, int x) {
  return tryNums(n, k, x, 1, 1);
}

int main() {
    int n;
    int k;
    int x;
    cin >> n >> k >> x;
    long answer = countArray(n, k, x);
    cout << answer << endl;
    return 0;
}
