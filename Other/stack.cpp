#include <iostream>
using namespace std;

class Stack{
public:
  Stack() : head(nullptr){}
  ~Stack();
  void push(int data);
  bool pop(int &data);
  bool mthFromLast(int m, int &data);
  void display();

private:
  class Node{
  private:
    int data;
    Node * next;
  public:
    Node(int d, Node * n) : data(d), next(n){}
    int getData(){return data;}
    Node * getNext(){return next;}
  };
  Node * head;
};

Stack::~Stack(){
  Node *ptr = head;
  while(ptr){
    head = ptr->getNext();
    delete ptr;
    ptr = head;
  }
  head = nullptr;
}

void Stack::push(int data){
  if(head == nullptr){
    head = new Node(data, nullptr);
  } else {
    head = new Node(data, head);
  }
}

bool Stack::pop(int & data){
  if(head){
    data = head->getData();
    head = head->getNext();
    return true;
  } else {
    return false;
  }
}

void Stack::display(){
  Node * ptr = head;
  while(ptr){
    cout << ptr->getData() << ' ';
    ptr = ptr->getNext();
  }
  cout << endl;
}

bool Stack::mthFromLast(int m, int &data){
  Node * lead = head, * follow = head;
  if(!lead){
    return false;
  }
  for(int i = 0; i < m; i++){
    if(lead->getNext()){
      lead = lead->getNext();
    } else {
      return false;
    }
  }
  while(lead->getNext()){
    lead = lead->getNext();
    follow = follow->getNext();
  }
  data = follow->getData();
  return true;
}

int main(){
  Stack s;
  char input;
  int num, outNum;
  do{
    cout << "q: exit | p: push | o: pop | d: display | m: mth from last" << endl;
    cin >> input;
    switch(input){
      case 'p':
        cout << "Enter a number to push: ";
        while(!(cin >> num)){
          cout << "Error: Incorrect input." << endl;
          cin.clear();
        }
        s.push(num);
        break;
      case 'o':
        if(s.pop(outNum)){
          cout << "Popped " << outNum << " from the stack." << endl;
        } else {
          cout << "Error: No numbers on stack." << endl;
        }
        break;
      case 'd':
        cout << "Stack: ";
        s.display();
        break;
      case 'm':
        cout << "Enter a value for m: ";
        cin >> num;
        if(s.mthFromLast(num, outNum)){
          cout << "The mth from last number is: " << outNum << endl;
        } else {
          cout << "Error: less than " << num << " numbers on the stack." << endl;
        }
        break;
      default:
        cout << "Error: please enter q, p, o, or d." << endl;
        break;
    }
  } while(input != 'q');
  return 0;
}
