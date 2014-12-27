/* Write an algorithm to find the 3rd highest number from an array of random integers. */

// Are the numbers all unique? Assuming yes
// Is there at least three numbers in the array? Assuming yes

int thirdHighest( int ar[] ) const{
  int i;
  int first = ar[0], second = ar[0], third = ar[0];
  for( i = 1; i < ar.size(); i++ ){
    if( ar[i] > first ){
      third = second;
      second = first;
      first = ar[i];
    } else if( ar[i] > second ){
      third = second;
      second = ar[i]; 
    } else if( ar[i] > third ){
      third = a[i];
    }
  }
  return third;
}
