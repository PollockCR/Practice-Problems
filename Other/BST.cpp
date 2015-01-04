/* Binary Search Tree Implementation */

class BST{
  public: 
    BST();
    ~BST();
    void insert( int );
    bool remove( int );
  private: 
    void insertHelper( Node* int );
    bool removeHelper( Node*, int );
    class Node{
      Node( int, Node*, Node* );
      int data;
      Node* left;
      Node* right;
    };
    Node* root;
}

BST::BST(){
  root = NULL;
}

BST::~BST(){
  while( root != NULL ){
    remove( root->data );
  }
}

void BST::insert( int val ){
  insertHelper( root, val );
}

void BST::insertHelper( Node* ptr, int val ){
  if( ptr == NULL ){
    ptr = new Node( val, NULL, NULL );
  } else if ( ptr->data > val ){
    insertHelper( val, ptr->left );
  } else {
    insertHelper( val, ptr->right );
  }
}

bool BST::remove( int val ){
  return removeHelper( root, val );
}

bool BST::removeHelper( Node* ptr, int val ){
  Node* temp;
  if( ptr == NULL ){
    return false;
  } else if( ptr->data > val ){
    return removeHelper( ptr->left, val );
  } else if( ptr->data < val ){
    return removeHelper( ptr->right, val );
  } else if ( ptr->right == NULL && ptr->left == NULL ){
    delete ptr;
    ptr = NULL;
    return true;
  } else if( ptr->right == NULL ){
    temp = ptr->left;
    delete ptr;
    ptr = temp;
    return true;
  } else if( ptr->left == NULL ){
    temp = ptr->right;
    delete ptr;
    ptr = temp;
    return true;
  } else {
    temp = ptr->left;
    while( temp->right != NULL ){
      temp = temp->right;
    }
    ptr->data = temp->data;
    removeHelper( ptr->left, ptr->data );
    return true;
  }
}

BST::Node::Node( int d, Node* l, Node* r ){
  data = d;
  left = l;
  right = r;
}
