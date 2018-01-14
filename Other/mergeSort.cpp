#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mergesort(vector<int> &nums);

vector<int> merge(vector<int> &dest, vector<int> &left, vector<int> &right);

int main(){
  int numSize, index, temp;
  vector<int> nums;
  cout << "How many numbers to sort? ";
  cin >> numSize;
  cout << "Enter " << numSize << " numbers:" << endl;
  for(index = 0; index < numSize; index++){
    cin >> temp;
    nums.emplace_back(temp);
  }
  nums = mergesort(nums);
  for(int num : nums){
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}

vector<int> mergesort(vector<int> &nums){
  if(nums.size() < 2){
    return nums;
  }
  int middle = nums.size() / 2, index;
  vector<int> left;
  vector<int> right;
  for(index = 0; index < middle; index++){
    left.push_back(nums[index]);
  }
  for(index = middle; index < nums.size(); index++){
    right.push_back(nums[index]);
  }
  mergesort(left);
  mergesort(right);
  return merge(nums, left, right);
}

vector<int> merge(vector<int> &dest, vector<int> &left, vector<int> &right){
  int destIndex = 0, leftIndex = 0, rightIndex = 0;
  // while both still have nums
  while(leftIndex < left.size() && rightIndex < right.size()){
    if(left[leftIndex] < right[rightIndex]){
      dest[destIndex++] = left[leftIndex++];
    } else {
      dest[destIndex++] = right[rightIndex++];
    }
  }
  // fill with remaining nums
  while(leftIndex < left.size()){
    dest[destIndex++] = left[leftIndex++];
  }

  while(rightIndex < right.size()){
    dest[destIndex++] = right[rightIndex++];
  }

  return dest;
}
