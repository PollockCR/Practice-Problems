// Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.

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

int List::remove( Node* ptr ) throw (logic_error){
  if( ptr == NULL ){
    throw logic_error(“Nothing to remove.”);
  }
  int value = ptr->data;
  if( ptr->next == NULL ){
    delete ptr;
    ptr = NULL;
    return value;
  }
  Node* temp = ptr->next;
  ptr->data = temp->data;
  ptr->next = temp->next;
  delete temp;
  return value;
}


