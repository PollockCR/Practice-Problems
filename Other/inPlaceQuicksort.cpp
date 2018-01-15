#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quicksort(vector<int> &nums, int cur, int g, int numCount);

int main(){
  int numCount, i, num;
  vector<int> nums;
  cout << "How many numbers to sort? ";
  cin >> numCount;
  cout << "Enter " << numCount << " numbers." << endl;
  for(i = 0; i < numCount; i++){
    cin >> num;
    nums.emplace_back(num);
  }
  quicksort(nums, 0, numCount-1, numCount);
  for(int num: nums){
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}

void quicksort(vector<int> &nums, int cur, int g, int numCount){
  int beg = cur, end = g, pivotIndex, pivot;
  if(g >= numCount || cur < 0 || g <= 0 || cur >= numCount){
    return;
  }
  if((g - cur) < 2){
    if(g != cur && nums[cur] > nums[g]){
      swap(nums[g], nums[cur]);
    }
    return;
  }
  // select and swap pivot
  pivotIndex = (g + cur) / 2;
  pivot = nums[pivotIndex];
  swap(nums[pivotIndex], nums[g]);
  g--;
  // move elements to g if >= pivot
  while(cur < g && g < nums.size()){
    if(nums[cur] >= pivot){
      swap(nums[cur], nums[g]);
      g--;
    } else {
      cur++;
    }
  }
  if(nums[g] < pivot){
    g++;
  }
  swap(nums[g], nums[end]);
  quicksort(nums, beg, g-1, numCount);
  quicksort(nums, g+1, end, numCount);
}
