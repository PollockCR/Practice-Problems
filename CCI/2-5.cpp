// You have 2 numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1’s digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list. 

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

Node* addListDigits( Node* a, Node* b ){
  List total;
  Node* t = total.head;
  Node* tHead = tHead;
  int aNum = 0, bNum = 0, totalNum;
  int i, j;
  for( i = 0; a != NULL; i++ ){
    aNum = aNum + ((a->data)*(pow(10,i));
    a = a->next;
  }
  for( j = 0; b != NULL; j++ ){
    bNum = bNum + ((b->data)*(pow(10,j));
    b = b->next;
  }
  totalNum = aNum + bNum;
  while( totalNum > 0 ){
    t = new Node( totalNum%10, NULL );
    t = t->next;
    totalNum = totalNum/10;
  }
  return tHead;
}

// Given solution that doesn't make sense to me

Node* addLists( Node* l1, Node* l2, int carry ){
  if( l1 == NULL && l2 == NULL && carry == 0){
    return NULL;
  } 
  Node* result = new Node( 0, NULL );
  int value = carry;
  if( l1 != NULL ){
    value += l1->data;
    l1=l1->next;
  }
  if( l2 != NULL ){
    value += l2->data;
    l2=l2->next;
  }
  result->data = value%10;
  if( l1!=NULL || l2!=NULL ){
    Node* more = addLists( l1, l2, value/10 );
    result->next = more;
  }
  return result;
}
