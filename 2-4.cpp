// Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.

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

List& partitionAround( int x, const List &copyList ){
  List a;
  List b;
  Node* ptr = copyList.head;
  Node* aPtr = a.head;
  Node* bPtr = b.head;
  while( ptr != NULL ){
    if( ptr->data < x ){
      aPtr = new Node( ptr->data, NULL );
      aPtr = aPtr->next;
    } else {
      bPtr = new Node( ptr->data, NULL );
      bPr = bPtr->next;
    }
    ptr = ptr->next;
  }
  aPtr = b.head;
  return a;
}
