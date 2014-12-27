/* Problem found here: https://www.hackerrank.com/challenges/insertionsort1
Given a sorted list with an unsorted number V in the right-most cell, can you write some simple code to insert V into the array so it remains sorted?
Print the array every time a value is shifted in the array until the array is fully sorted. The goal of this challenge is to follow the correct order of insertion sort.
Guideline: You can copy the value of V to a variable, and consider its cell "empty". Since this leaves an extra cell empty on the right, you can shift everything over until V can be inserted. This will create a duplicate of each value, but when you reach the right spot, you can replace a value with V.
Input Format 
There will be two lines of input:
s - the size of the array
ar - the sorted array of integers
Output Format 
On each line, output the entire array every time an item is shifted in it.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(vector <int>  ar);

int main(void) {
  vector <int>  _ar;
  int _ar_size;
  cin >> _ar_size;
  for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp); 
  }

  insertionSort(_ar);
   
  return 0;
}

void insertionSort( vector<int> ar ){
  int num = ar[ar.size()-1];
  int i = ar.size() - 2;
  while( i >= 0 && num < ar[i] ){
    ar[i+1] = ar[i];
    for( int j = 0; j < ar.size(); j++ ){
      cout << ar[j] << ‘ ‘;
    }
    cout << endl;
    i--;
  }
  ar[i+1] = num;
  for( int j = 0; j < ar.size(); j++ ){
      cout << ar[j] << ‘ ‘;
  }
}
