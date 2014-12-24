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





// my solution (I think mine works, but it did not use push and pop as often as it should…)
void Stack::sortStack(){
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

// given solution 
Stack& sort( Stack s ){
  Stack r = new Stack();
  while( !isEmpty() ){
    int temp = s.pop(); // step 1
    while( !r.isEmpty() && r.peek() > temp ){ // step 2
      s.push( r.pop() );
    }
    r.push( temp ); // step 3
  }
  return r;
}
