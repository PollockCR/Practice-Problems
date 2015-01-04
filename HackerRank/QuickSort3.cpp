// Found here: https://www.hackerrank.com/challenges/quicksort3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(vector <int> &, int, int);
void printAr(vector<int> ar);

int main() {
 vector <int>  _ar;
  int _ar_size;
  cin >> _ar_size;
  for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp); 
  }
  quickSort(_ar, 0, _ar_size);
  return 0;
}



void quickSort(vector <int>  &ar, int start, int end){
  int i, temp, piv, cur = start;
  if( end-start < 2 ){
  } else if ( end-start == 2 ){
    if( ar[start] > ar[end-1] ){
      temp = ar[end-1];
      ar[end-1] = ar[start];
      ar[start] = temp;
    }
  } else {
    piv = ar[end-1];
    for( i = start; i < end-1; i++ ){
      if( ar[i] < piv ){
        if( i != cur ){
          temp = ar[cur];
          ar[cur] = ar[i];
          ar[i] = temp;
        }
        cur++;
      }
    }
    if( ar[cur] > piv ){
      ar[end-1] = ar[cur];
      ar[cur] = piv;
    }
    printAr( ar );
    quickSort( ar, start, cur);
    quickSort( ar, cur, end);
  }
}

void printAr(vector<int> ar){
  for( int i = 0; i < ar.size(); i++ ){
    cout << ar[i] << ' ';
  }
  cout << endl;
}



