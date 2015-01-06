// https://www.hackerrank.com/contests/w13/challenges/taum-and-bday

/*
Input:
1
10 10
1 1 1
Output:
20
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void findCost( unsigned long long int numB, unsigned long long int numW, unsigned long long int costB, unsigned long long int costW, unsigned long long int conv );

int main() {
  unsigned long long int numCases, numB, numW, costB, costW, conv;
  cin >> numCases;
  while( numCases > 0 ){
    cin >> numB >> numW >> costB >> costW >> conv;
    findCost( numB, numW, costB, costW, conv );
    numCases--;
  } 
  return 0;
}

void findCost( unsigned long long int numB, unsigned long long int numW, unsigned long long int costB, unsigned long long int costW, unsigned long long int conv ){
  unsigned long long int newCostB = costB;
  unsigned long long int newCostW = costW; 
  unsigned long long int totalCost; 
  if( costW + conv < costB ){
    newCostB = costW + conv;
  }
  if( costB + conv < costW ){
    newCostW = costB + conv;
  }
  totalCost = ( numB * newCostB ) + ( numW * newCostW );
  cout << totalCost << endl;
}
