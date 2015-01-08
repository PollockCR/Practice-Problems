// Write a function to remove odd nodes from a singly linked list.

void removeOdds( List &a ){
  Node* prev = NULL;
  Node* ptr = a.head;
  while( ptr != NULL ){
    if( ptr->data %2 != 0 ){
      if( ptr == a.head ){
        a.head = ptr->next;
        delete ptr;
        ptr = a.head;
      } else {
        prev->next = ptr->next;
        delete ptr;
        ptr = prev->next;
      }
    } else {
      prev = ptr;
      ptr = ptr->next;
    }
  }
}

class List{
  public:
    List(){ head = NULL; };
    ~List();
    Node* head;
    class Node{
      public:
        int data;
        Node* next;
        Node( int val, Node* nextVal ){
          next = nextVal;
          data = val;
        };
    };
};
