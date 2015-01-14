// Implementation of a linked list (without a cursor)
#include <iostream> 
using namespace std;

class List {
  public: 
    List(){ head = NULL; };
    void insert( int ); // insert at end
    bool remove( int ); // remove given value
    void reverse(); // reverse entire list, return new head
    void removeOdds();
    void printList();
  private:
    class Node {
      public: 
        Node( int val, Node* nextNode ){ data = val; next = nextNode; };
        Node* next;
        int data;
    };
    Node* head;
};

int main()
{
  int i;
  List a;
  for( i = 0; i < 10; i++ )
  {
    a.insert(i);
  }
  a.printList();
  a.removeOdds(); 
  a.printList(); 
  return 0;
}

void List::insert( int val ){ 
  Node* cursor = head;
  if( head == NULL ){
    head = new Node( val, NULL );
  } else {
    while( cursor -> next != NULL ){
      cursor = cursor -> next;
    }
    cursor -> next = new Node( val, NULL );
  }
}

bool List::remove( int val ){
  Node* cursor = head;
  while( cursor != NULL ){
    if( cursor -> data == val ){
      return true;
    } 
    cursor = cursor -> next;
  } 
  return false;
}

void List::reverse(){
  Node* prev = NULL;
  Node* cursor = head;
  Node* temp;
  while( cursor -> next != NULL ){
    temp = cursor -> next;
    cursor -> next = prev;
    prev = cursor;
    cursor = temp;
  }
  cursor -> next = prev;
  head = cursor;
}

void List::printList(){
  Node* ptr = head;
  while( ptr != NULL ){
    cout << ptr->data << ' ';
    ptr = ptr->next;
  }
  cout << endl;
}

void List::removeOdds()
{
  Node* ptr = head;
  Node* prev = NULL;
  while( ptr != NULL )
  {
    if( ptr->data % 2 != 0 )
    {
      if( ptr == head )
      {
        ptr = ptr -> next;
        delete head;
        head = ptr;
      }
      else
      {
        prev -> next = ptr -> next;
        delete ptr;
        ptr = prev -> next;
      }
    }
    else 
    {
      prev = ptr;
      ptr = ptr -> next;
    }
  }
}