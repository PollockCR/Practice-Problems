// Implement an algorithm to find the kth to last element of a singly linked list. 

// Assuming: do not know how many elements in list, if there are less than k elements return home pointer, return pointer to kth to last element

class List{
  public:
    List();
    List( const List& );
    ~List();
    List& operator=( const List& );
    void insert( int );
    int remove();
    int getCursor() const;
    void clear();
  private:
    class Node{
      Node( int, Node* );
      int data;
      Node* next;
    };
    Node* head;
    Node* cursor;
};

Node* getKthToLast( int k ) const{
  if( head == NULL ){
    return head;
  }
  int numMoves = 0;
  Node* ptr = slowPtr = head;
  while( ptr -> next != NULL ){
    ptr = ptr -> next;
    numMoves++;
    if( numMoves >= k ){
       slowPtr = slowPtr -> next;
    }
  }
  return slowPtr;
}


