// Write code to remove duplicates from an unsorted linked list.

void removeDuplicates( list<int> myList ){
  map<int, bool> listMap;
  list<int>::iterator ptr = myList.begin();
  while( ptr != myList.end() ){
    if( listMap[ *ptr ].count > 0 ){
      ptr = myList.erase( ptr );
    }
    else{
      listMap.insert( pair<int,bool>(*ptr,true) );
      ptr++;
    }
  }
}
