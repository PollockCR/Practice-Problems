// Write a function to remove odd nodes from a singly linked list.

void removeOdds( list<int> &aList ){
  list<int>::iterator ptr = aList.begin();
  while( ptr != aList.end() ){
    if( *ptr % 2 != 0 ){
      ptr = aList.erase( ptr );
    } else {
      ++ptr;
    }
  }
}

