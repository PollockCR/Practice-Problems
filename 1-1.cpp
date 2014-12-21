// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
bool allUniqueChars( String s ) const {
  for( int i = 0; i < s.size(); i++ ){
    if( s.rfind( s[ i ] ) != i ){
      return false;
    }
  }
  return true;
}

bool allUniqueChars( string s ) const {
  list<char> sList;
  int startSize;
  sList.assign( s.begin(), s.end() );
  startSize = sList.size();
  sList.sort();
  sList.unique;
  return( sList.size() == startSize );
}
