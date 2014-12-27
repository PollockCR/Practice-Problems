/* Problem found here: https://www.hackerrank.com/challenges/insertionsort2
Problem Statement
In Insertion Sort Part 1, you sorted one element into an array. Using the same approach repeatedly, can you sort an entire unsorted array?
Guideline: You already can place an element into a sorted array. How can you use that code to build up a sorted array, one element at a time? Note that in the first step, when you consider an element with just the first element - that is already "sorted" since there's nothing to its left that is smaller than it.
In this challenge, don't print every time you move an element. Instead, print the array every time an element is "inserted" into the array in (what is currently) its correct place. Since the array composed of just the first element is already "sorted", begin printing from the second element and on.
Input Format 
There will be two lines of input:
s - the size of the array
ar - the list of numbers that makes up the array
Output Format 
On each line, output the entire array at every iteration
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

void insertionSort(int ar_size, int *  ar);
void sortOne( int *, int);

int main(void) {
   
    int _ar_size;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]); 
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}

void insertionSort(int ar_size, int * ar) {
  int i;
  for( i = 1; i < ar_size; i++ ){
    sortOne( ar, i );
    for( int j = 0; j < ar_size; j++ ){
      cout << ar[j] << ‘ ‘;
    }
    cout << endl;
  }
}

void sortOne( int * ar, int curSize ){
  int num = ar[curSize];
  int i = curSize - 1;
  while( i >= 0 && num < ar[i] ){
    ar[i+1] = ar[i];
    i--;
  }
  ar[i+1] = num;
}

