// https://www.hackerrank.com/challenges/ctci-bubble-sort
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bubbleSort(vector<int> &a, int n){
  int swapCount = 0;
  for(int i = 0; i < n; i++){
    int swapsThisRound = 0;
    for(int j = 0; j < n-1; j++){
      if(a[j] > a[j+1]){
        swap(a[j], a[j+1]);
        swapCount++;
        swapsThisRound++;
      }
    }
    if(swapsThisRound == 0){
      return swapCount;
    }
  }
  return swapCount;
}


int main() {
   int n, numSwaps;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
  numSwaps = bubbleSort(a,n);
  cout << "Array is sorted in " << numSwaps << " swaps." << endl;
  cout << "First Element: " << a[0] << endl;
  cout << "Last Element: " << a[n-1] << endl;
  return 0;
}
