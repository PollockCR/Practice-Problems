class Stack{
  public:
    Stack();
    Stack( const Stack& );
    ~Stack();
    Stack& operator=( const Stack& );
    void push( int );
    bool pop( int& );
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

bool Stack::pop( int& value ){
  if( top == NULL ){
    return false;
  }
  value = pop->data;
  Node* temp = top->next;
  delete top;
  top = temp;
  return true;
}

class Queue{
  public:
    Queue();
    Queue( const Queue& );
    ~Queue();
    Queue& operator=( const Queue& );
    void enqueue( int );
    bool dequeue( int& );
    void clear();
  private:
  class Node{
    Node( int, Node* );
    int data;
    Node* next;
  };
  Node* front;
  Node* rear;
};

void Queue::enqueue( int value ){
  if( front == NULL ){
    front = rear = new Node( value, NULL );
  } else {
    rear->next = new Node( value, NULL );
    rear = rear->next;
  }
}

bool Queue::dequeue( int& value ){
  if( front == NULL ){
    return false;
  }
  value = front->data;
  Node* temp = front->next;
  delete front;
  front = temp;
  return true;
}
