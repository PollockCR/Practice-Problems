// Write an algorithm to find the kth highest element from an array of random integers

#include <iostream>
using namespace std;

void quickSort( int [], int, int );
void kthHighest( int [], int, int ); 

int main(){
  int arSize, i, num, k;
  cout << "How many values? ";
  cin >> arSize;
  cout << "What kth highest value? ";
  cin >> k;
  cout << "Insert " << arSize << " values: "<< endl;
  int ar[ arSize ];
  for( i = 0; i < arSize; i++ ){
    cin >> num;
    ar[ i ] = num;
  }
  quickSort( ar, 0, arSize );
  cout << "The sorted values are : ";
  for( i = 0; i < arSize; i++ ){
    cout << ar[i] << ' ';
  }
  cout << endl << "The kth highest value is: ";
  kthHighest( ar, arSize, k );
  return 0;
}

void quickSort( int ar[], int start, int end ){
  int temp, piv, i, wall;
  int size = end - start;
  if( size <= 1 ){

  } else if ( size == 2 ){
    if( ar[start] > ar[end-1] ){
      temp = ar[start];
      ar[start] = ar[end-1];
      ar[end-1] = temp;
    }
  } else {
    piv = ar[end-1];
    wall = start;
    for( i = start; i < end; i++ ){
      if( ar[i] < piv ){
        if( wall != i ){
          temp = ar[wall];
          ar[wall] = ar[i];
          ar[i] = temp;
        }
        wall++;
      }
    }
    if( ar[wall] > piv ){
      ar[end-1] = ar[wall];
      ar[wall] = piv;
    }
    quickSort( ar, start, wall);
    quickSort( ar, wall+1, end);
  }
}

void kthHighest( int ar[], int arSize, int k ){
  cout << ar[ arSize - k ] << endl;
}
