#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

class BinaryTree{
protected:
  class Node{
  public:
    Node(int d, Node * l, Node * r) : data(d), left(l), right(r) {}
    int getData() {return data;}
    void setData(int d) {data = d;}
    Node * & getLeft() {return left;}
    Node * & getRight() {return right;}
  protected:
    int data;
    Node * left;
    Node * right;
  };
  Node * root;
  void destructorHelper(Node* &root);
  bool insertHelper(Node * &root, int d);
  bool removeHelper(Node * &root, int d);
  Node* searchHelper(Node * root, int d);
  void showHelper(Node * root, int level);
  int heightHelper(Node * root);
public:
  BinaryTree() {root = NULL;}
  ~BinaryTree();
  bool insert(int d);
  bool remove(int d);
  Node* search(int d);
  void showStructure();
  int height();
};

BinaryTree::~BinaryTree(){
  if(root != NULL){
    destructorHelper(root);
  }
}

void BinaryTree::destructorHelper(Node* &root){
  if(root->getLeft() != NULL){
    destructorHelper(root->getLeft());
  }
  if(root->getRight() != NULL){
    destructorHelper(root->getRight());
  }
  delete root;
  root = NULL;
}

bool BinaryTree::insert(int d){
  return insertHelper(root, d);
}

bool BinaryTree::insertHelper(Node* & root, int d){
  if(root == NULL){
    root = new Node(d, NULL, NULL);
    return true;
  } else if(root->getData() < d){
    return insertHelper(root->getRight(), d);
  } else if(root->getData() > d){
    return insertHelper(root->getLeft(), d);
  }
  return false;
}

bool BinaryTree::remove(int d){
  return removeHelper(root, d);
}

bool BinaryTree::removeHelper(Node * &root, int d){
  if(root == NULL){
    return false;
  } else if(root->getData() == d){
    // case 1: no children
    if(root->getLeft() == NULL && root->getRight() == NULL){
      delete root;
      root = NULL;
      return true;
    // case 2: only right child
    } else if(root->getLeft() == NULL){
      Node * ptr = root;
      root = root->getRight();
      delete ptr;
      ptr = NULL;
      return true;
    // case 3: only left child
    } else if(root->getRight() == NULL){
      Node * ptr = root;
      root = root->getLeft();
      delete ptr;
      ptr = NULL;
      return true;
    }
    // case 4: two children
    else {
      Node * temp;
      temp = root->getLeft();
      while(temp->getRight() != NULL){
        temp = temp->getRight();
      }
      root->setData(temp->getData());
      return removeHelper(root->getLeft(), temp->getData());
    }
  } else if(root->getData() < d){
    return removeHelper(root->getRight(), d);
  } else if(root->getData() > d){
    return removeHelper(root->getLeft(), d);
  }
  return false;
}

BinaryTree::Node* BinaryTree::search(int d){
  return searchHelper(root, d);
}

BinaryTree::Node* BinaryTree::searchHelper(Node * root, int d){
  if(root == NULL){
    return NULL;
  } else if(root->getData() == d){
    return root;
  } else if(root->getData() < d){
    return searchHelper(root->getRight(), d);
  } else {
    return searchHelper(root->getLeft(), d);
  }
}

void BinaryTree::showStructure(){
  if(root == NULL)
     cout << "Empty tree" << endl;
  else
  {
     cout << endl;
     showHelper(root,1);
     cout << endl;
  }
}

void BinaryTree::showHelper(Node * root, int level){
  int j;
  if(root != NULL){
    showHelper(root->getRight(),level+1);
    for(j = 0 ; j < level ; j++){
      cout << "\t";
    }
    cout << " " << root->getData();
    if ( ( root->getLeft() != 0 ) &&
         ( root->getRight() != 0 ) )
      cout << "<";
    else if ( root->getRight() != 0 )
       cout << "/";
    else if ( root->getLeft() != 0 )
       cout << "\\";
    cout << endl;
    showHelper(root->getLeft(),level+1);
  }
}

int BinaryTree::height(){
  return heightHelper(root);
}

int BinaryTree::heightHelper(Node * root){
  if(root == NULL){
    return 0;
  }
  return 1 + max(heightHelper(root->getLeft()),
                      heightHelper(root->getRight()));
}

int main(){
  BinaryTree bt;
  int num;
  char input;
  do{
    cout << "q: quit | i: insert | r: remove | s: search | p: show structure | h: height" << endl;
    cin >> input;
    switch (input) {
      case 'i':
        while( ! (cin >> num)){
          cout << "Error: enter a number to insert." << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        bt.insert(num);
        break;
      case 'r':
        while(! (cin >> num)){
          cout << "Error: enter a number to remove." << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        if(bt.remove(num)){
          cout << num << " removed." << endl;
        } else {
          cout << "Error: " << num << " not found." << endl;
        }
        break;
      case 's':
        while(! (cin >> num)){
          cout << "Error: enter a number to search for." << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        if(bt.search(num) != NULL){
          cout << num << " found." << endl;
        } else {
          cout << num << " not found." << endl;
        }
        break;
      case 'p':
        bt.showStructure();
        break;
      case 'h':
        cout << "Height is " << bt.height() << endl;
        break;
      default:
        break;
    }
  } while(input != 'q');
  return 0;
}
