// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

// no extra data structures implementation
// time complexity O( n ) where n is length of string (Linear/Brute Force). Space complexity O( 1 ).
bool allUniqueChars( String s ) const {
  if( s.length() > 256 ){
    return false;
  }
  bool charSet[ 256 ];
  for( int i = 0; i < s.size(); i++ ){
    if( charSet[ s[i] ] ){
      return false;
    }
    charSet[ s[i] ] = true;
  }
  return true;
}

// if done by checking each character to every other character, time complexity O( n^2 ) and O(1) space 
