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

vector<int> quickSort(vector <int>);
void printAr(vector<int>);

int main(void) {
  vector <int>  _ar;
  int _ar_size;
  cin >> _ar_size;
  for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp); 
  }
  quickSort(_ar);
  return 0;
}

vector<int> quickSort(vector <int>  ar){
  int size = ar.size();
  vector<int> less, more, finar;
  int i, temp, p;
  if( size < 2 ){
    return ar;
  } else if ( size == 2 ){
    if( ar[0] > ar[1] ){
      temp = ar[1];
      ar[1] = ar[0];
      ar[0] = temp;
    }
    printAr( ar );
    return ar;
  } else {
    p = ar[0];
    for( i = 1; i < size; i++ ){
      if( ar[i] < p ){
        less.push_back(ar[i]);
      } else {
        more.push_back(ar[i]);
      }
    }
    less = quickSort( less );
    more = quickSort( more );
    finar.insert( finar.begin(), less.begin(), less.end() );
    finar.insert( finar.end(), p );
    finar.insert( finar.end(), more.begin(), more.end() );
    printAr( finar );
    return finar;
  }
}

void printAr(vector<int> ar){
  for( int i = 0; i < ar.size(); i++ ){
    cout << ar[i] << ' ';
  }
  cout << endl;
}
