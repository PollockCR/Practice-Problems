// Write a function to find the kth highest number from an array of random integers

int kthHighest( int ar[], int size, int k )
{
  insertionSort( ar, 0, size );
  return ar[ size - k  ];
}

void insertionSort( int ar[], int size )
{
  int unsorted, val, loc;
  for( unsorted = 1; unsorted < size; unsorted++ )
  {
    val = ar[ unsorted ];
    loc = unsorted;
    while( loc > 0 && ar[ loc-1 ] > val )
    {
      ar[ loc ] = ar[ loc -1 ];
    }
    loc--;
    ar[ loc-1 ] = val;
  }
}
