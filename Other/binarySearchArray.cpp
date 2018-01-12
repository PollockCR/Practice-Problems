#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> &nums, int target);

bool binarySearchHelper(vector<int> &nums, int target, int lowerIndex, int upperIndex);

int main(){
  int sizeOfNums;
  int target;
  cout << "How many numbers to search?" << endl;
  cin >> sizeOfNums;
  vector<int> nums(sizeOfNums);
  for(int i = 0; i < sizeOfNums; i++){
    cin >> nums[i];
  }
  cout << "Enter a number to search for." << endl;
  cin >> target;
  if(binarySearch(nums, target)){
    cout << "Number " << target << " was found." << endl;
  } else {
    cout << "Your number was not found. Please try again." << endl;
  }
  return 0;
}

bool binarySearch(vector<int> &nums, int target){
  return binarySearchHelper(nums, target, 0, nums.size()-1);
}

bool binarySearchHelper(vector<int> &nums, int target, int lowerIndex, int upperIndex){
  int midIndex;
  if(lowerIndex > upperIndex){
    return false;
  }
  midIndex = (lowerIndex + upperIndex) / 2;
  if(nums[midIndex] == target){
    return true;
  } else if (nums[midIndex] > target){
    return binarySearchHelper(nums, target, lowerIndex, midIndex);
  } else {
    return binarySearchHelper(nums, target, midIndex, upperIndex);
  }
  return false;
}
