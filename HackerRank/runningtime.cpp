// Problem: https://www.hackerrank.com/challenges/runningtime

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

void insertionSort(int ar_size, int *  ar);
int sortOne( int *, int);

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
  int i, numShifts = 0;
  for( i = 1; i < ar_size; i++ ){
    numShifts = numShifts + sortOne( ar, i );
  }
  cout << numShifts;
}

int sortOne( int * ar, int curSize ){
  int num = ar[curSize];
  int numShifts = 0;
  int i = curSize - 1;
  while( i >= 0 && num < ar[i] ){
    ar[i+1] = ar[i];
    i--;
    numShifts++;
  }
  ar[i+1] = num;
  return numShifts;
}





