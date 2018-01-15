#include <iostream>
#include <cmath>
#include <limits>
#include <stack>
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
  void preorderHelper(Node * root);
  void inorderHelper(Node * root);
  void postorderHelper(Node * root);
  void preorderNoRecursionHelper(Node * root);
  Node* findLowestCommonAncestorHelper(Node * root, int val1, int val2);
public:
  BinaryTree() {root = NULL;}
  ~BinaryTree();
  bool insert(int d);
  bool remove(int d);
  Node* search(int d);
  void showStructure();
  int height();
  void preorder();
  void inorder();
  void postorder();
  void preorderNoRecursion();
  Node* findLowestCommonAncestor(int val1, int val2);
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

void BinaryTree::preorder(){
  preorderHelper(root);
  cout << endl;
}

void BinaryTree::preorderHelper(Node * root){
  if(root != NULL){
    cout << root->getData() << ' ';
    preorderHelper(root->getLeft());
    preorderHelper(root->getRight());
  }
}

void BinaryTree::inorder(){
  inorderHelper(root);
  cout << endl;
}

void BinaryTree::inorderHelper(Node * root){
  if(root != NULL){
    inorderHelper(root->getLeft());
    cout << root->getData() << ' ';
    inorderHelper(root->getRight());
  }
}

void BinaryTree::postorder(){
  postorderHelper(root);
  cout << endl;
}

void BinaryTree::postorderHelper(Node * root){
  if(root != NULL){
    postorderHelper(root->getLeft());
    postorderHelper(root->getRight());
    cout << root->getData() << ' ';
  }
}

void BinaryTree::preorderNoRecursion(){
  preorderNoRecursionHelper(root);
  cout << endl;
}

void BinaryTree::preorderNoRecursionHelper(Node * root){
  if(root == NULL){
    return;
  }
  stack<Node *> nodes;
  nodes.push(root);
  while(!nodes.empty()){
    Node * parent = nodes.top();
    cout << parent->getData() << ' ';
    nodes.pop();
    if(parent->getRight()){
      nodes.push(parent->getRight());
    }
    if(parent->getLeft()){
      nodes.push(parent->getLeft());
    }
  }
}

BinaryTree::Node* BinaryTree::findLowestCommonAncestor(int val1, int val2){
  return findLowestCommonAncestorHelper(root, val1, val2);
}

BinaryTree::Node* BinaryTree::findLowestCommonAncestorHelper(Node * root, int val1, int val2){
  Node * parent = root;
  while(parent){
    if(parent->getData() > val1 && parent->getData() > val2){
      parent = parent->getLeft();
    } else if(parent->getData() < val1 && parent->getData() < val2){
      parent = parent->getRight();
    } else {
      return parent;
    }
  }
  return NULL;
}

int main(){
  BinaryTree bt;
  int num;
  char input;
  do{
    cout << endl;
    cout << "q: quit | i: insert | r: remove | s: search | p: show structure | h: height" << endl;
    cout << "f: find lowest common ancestor" << endl;
    cout << "0: preorder w/out recursion | 1: preorder | 2: in-order | 3: postorder" << endl;
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
      case 'f':
        int num1, num2;
        cout << "Enter two numbers in the tree: ";
        while(! (cin >> num1) || ! bt.search(num1)){
          cout << "Error: enter a number in the tree." << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        while(! (cin >> num2) || ! bt.search(num2)){
          cout << "Error: enter a number in the tree." << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "Lowest common ancestor to " << num1 << " and " << num2 << ": " << bt.findLowestCommonAncestor(num1, num2)->getData() << endl;
        break;
      case '0':
        cout << "Preorder traversal: ";
        bt.preorderNoRecursion();
        break;
      case '1':
        cout << "Preorder traversal: ";
        bt.preorder();
        break;
      case '2':
        cout << "Inorder traversal: ";
        bt.inorder();
        break;
      case '3':
        cout << "Postorder traversal: ";
        bt.postorder();
        break;
      default:
        break;
    }
  } while(input != 'q');
  return 0;
}
