#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void stableInsertionSort(list<int> &);

list<int>::iterator findMin(list<int> &, list<int>::iterator);

int main(){
  int numCount, num;
  list<int> nums;
  cout << "How many integers to sort? ";
  cin >> numCount;
  for(int i = 0; i < numCount; i++){
    cin >> num;
    nums.emplace_back(num);
  }
  stableInsertionSort(nums);
  for(int num: nums){
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}

void stableInsertionSort(list<int> &nums){
  int i, minVal;
  list<int>::iterator minIt, unsortedIt;
  for(unsortedIt = nums.begin(); unsortedIt != nums.end(); ){
    minIt = findMin(nums, unsortedIt);
    if(minIt != unsortedIt){
      nums.insert(unsortedIt, *minIt);
      nums.erase(minIt);
    } else {
      unsortedIt++;
    }
  }
}

list<int>::iterator findMin(list<int> &nums, list<int>::iterator unsortedIt){
  list<int>::iterator minIt = unsortedIt, it;
  for(it = unsortedIt; it != nums.end(); it++){
    if(*it < *minIt){
      minIt = it;
    }
  }
  return minIt;
}
