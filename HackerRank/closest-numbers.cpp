// https://www.hackerrank.com/challenges/closest-numbers

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void quickSort(vector <int> &, int, int);
void findMinDif(vector<int> ar);

int main() {
  vector <int> ar;
  int arSize, i, val;
  cin >> arSize;
  for( int i=0; i < arSize; i++ ) {
    cin >> val;
    ar.push_back(val); 
  }
  quickSort( ar, 0, arSize );
  findMinDif( ar );
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
    quickSort( ar, start, cur);
    quickSort( ar, cur, end);
  }
}

void findMinDif( vector<int> ar ){
  int min = ar[1]-ar[0];
  int cur, i;
  vector<int> minPairs;
  int frontI, backI;
  for( frontI = 1, backI = 0; frontI < ar.size(); frontI++, backI++){
    cur = ar[ frontI ] - ar[ backI ];
    if( cur < min ){
      minPairs.clear();
      min = cur;
    }
    if( cur == min ){
      minPairs.push_back( ar[ backI ] );
      minPairs.push_back( ar[ frontI ] );
    }
  }
  for( i = 0; i < minPairs.size(); i++ ){
    cout << minPairs[i] << ' ';
  }
}
