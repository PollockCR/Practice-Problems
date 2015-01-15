// Found here: https://code.google.com/codejam/contest/32016/dashboard#s=p0

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

long long int findMinProd( vector<long long int> &a, vector<long long int> &b );

int main()
{
  long long int i, j, numCases, numItems, temp, minProd;
  ifstream fin;
  ofstream fout;
  fout.open( "A-large-practice.out" );
  fin.open( "A-large-practice.in" );
  fin >> numCases;
  for( i = 0; i < numCases; i++ )
  {
    fin >> numItems;
    vector<long long int> a (numItems);
    vector<long long int> b (numItems);
    for( j = 0; j < numItems; j++ )
    {
      fin >> temp;
      a[ j ] = temp;
    }
    for( j = 0; j < numItems; j++ )
    {
      fin >> temp;
      b[ j ] = temp;
    }
    minProd = findMinProd( a, b );
    fout << "Case #" << i+1 << ": " << minProd << endl;
  }
  fin.close();
  fout.close();
  return 0;
}

long long int findMinProd( vector<long long int> &a, vector<long long int> &b )
{
  long long int total = 0, i;
  sort( a.begin(), a.end() );
  sort( b.begin(), b.end() );
  reverse( b.begin(), b.end() );
  for( i = 0; i < a.size(); i++ )
  {
    total = total + ( a[i] * b[i] );
  }
  return total;
}
