/* Write a problem to sort a stack in ascending order (with biggest items on top). You may use at most one additional stack to hold items, but you may not copy the elements into any other data structure (such as an array). The stack supports push, pop, peek and isEmpty */

class Stack{
  public:
    Stack();
    Stack( const Stack& );
    ~Stack();
    Stack& operator=( const Stack& );
    void push( int );
    Node* pop();
    void clear();
  private:
    class Node{
      Node(int, Node*);
      int data;
      Node* next;
    };
    Node* top;
};

void Stack::push( int value ){
  top = new Node( value, top );
}

int Stack::pop(){
  if( top == NULL ){
    return inf;
  }
  value = pop->data;
  Node* temp = top->next;
  delete top;
  top = temp;
  return value;
}

void sortStack(){
  Node *ptr = top;
  Stack source;
  int temp;
  Node* minPtr = top;
  while( !isEmpty() ){
    while( ptr != NULL ){
      if( ptr->data < minPtr->data ){
        minPtr = ptr;
      }
      ptr = ptr->next;
    }
    temp = minPtr->data;
    minPtr->data = top->data;
    top->data = temp;
    source.push( pop() );
    ptr = minPtr = top;
  }
  while( !source.isEmpty() ){
    push( source.pop() );
  }
}
