/* In the classic problem of the Towers of Hanoi, you have three towers and N disks of different sizes which can slide on any tower. The puzzle starts with disks sorted in ascending order of size from top to bottom (i.e., each disk sits on top of an even larger one). You have the following constraints: 1. Only one disk can be moved at a time. 2. A disk is slid off the top of one tower onto the next tower. 3. A disk can only be placed on top of a larger disk. Write a program to move the disks from the first tower to the last using stacks. */

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

// base case: when only want 1 item to be moved from stack

void solve(){
  moveTower( numDisks, s1, s3, s2 );
}

void moveTower( int diskNum, Stack begin, Stack end, Stack other ){
  if( diskNum == 1 ){
    moveDisk( begin, end );
  }else{
    moveTower( diskNum-1, begin, other, end );
    moveDisk( begin, end );
    moveTower( diskNum-1, other, end, begin );
  }
}

void moveDisk( Stack begin, Stack end ){
  end.push( begin.pop() );
}
