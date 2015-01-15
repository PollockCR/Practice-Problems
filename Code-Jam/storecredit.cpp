// Found here: https://code.google.com/codejam/contest/351101/dashboard#s=p0

#include <iostream>
#include <fstream>
using namespace std;

void spend( int[], int, int, int&, int& );

int main()
{
  int i, j, numCases, budget, numItems, price;
  int in1 = -1, in2 = -1;
  ifstream fin;
  ofstream fout;
  fout.open( "A-large-practice.out" );
  fin.open( "A-large-practice.in" );
  fin >> numCases;
  for( i = 0; i < numCases; i++ )
  {
    fin >> budget >> numItems;
    int prices[ numItems ];
    for( j = 0; j < numItems; j++ )
    {
      fin >> price;
      prices[ j ] = price;
    }
    spend( prices, budget, numItems, in1, in2 );
    fout << "Case #" << i+1 << ": " << in1 + 1 << " " << in2+1 << endl;
  }
  fin.close();
  fout.close();
  return 0;
}

void spend( int prices[], int budget, int numItems, int &in1, int &in2 )
{
  int findMe, i, j;
  for( i = 0; i < numItems; i++ )
  {
    findMe = budget - prices[ i ];
    for( j = i+1; j < numItems; j++ )
    {
      if( prices[ j ] == findMe )
      {
        in1 = i;
        in2 = j;
        return;
      }
    }
  }
}
