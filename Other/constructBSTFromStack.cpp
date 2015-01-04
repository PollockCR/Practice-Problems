/* Construct a binary search tree from a list/stack of it's pre-order traversal. */

/* Implementation 1:
Assuming: I have access to STL containers.
*/

set<int>& constuctFromStack( stack<int> a ){
  set<int> b;
  while( !a.empty() ){
    b.insert( a.pop() );
  }
 return *b;
}

/* Implementation 2:
Assuming: No access to STL containers.
*/

BST& constructFromStack( Stack a ){
  BST b;
  while( !a.empty() ){
    b.insert( a.pop() );
  }
  return *b;
}

// BST insert and constructor is in BST.cpp

int Stack::pop(){
  if( head == NULL ){
    return inf;
  } else {
    int d = head ->data;
    Node* temp = head->next;
    delete head;
    head = temp;
    return d;
  }
}

bool Stack::empty() const{
  return( head == NULL );
}
