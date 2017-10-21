#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int nums[5];
  int minIndex = 0, maxIndex = 0;
  long minSum = 0, maxSum = 0;
  for(int i = 0; i < 5; i++){
    cin >> nums[i];
    if(nums[i] < nums[minIndex]){
      minIndex = i;
    }
    if(nums[i] > nums[maxIndex]){
      maxIndex = i;
    }
  }
  for(int i = 0; i < 5; i++){
    if(i != minIndex){
      maxSum += nums[i];
    }
    if(i != maxIndex){
      minSum += nums[i];
    }
  }
  cout << minSum << ' ' << maxSum;
  return 0;
}
