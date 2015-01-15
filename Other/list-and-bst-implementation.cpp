// Implementing data structures
// Just for practice as I would in an interview. These are not complete because I only implemented the more challenging functions. 

class List // without a cursor, also can be done with a cursor
{
  public: 
    List();
    ~List();
    void insert( int );
    bool remove( int );
  private:
    class Node
    {
      public:
        Node( int, Node* );
        int data;
        Node* next;
    };
    Node* head;
};

List::Node::Node( int val, Node* nval )
{
  data = val;
  next = nval;
}

List::List()
{
  head = NULL;
}

List::~List()
{
  while( head != NULL )
  {
    remove( head->data );
  }
}

void List::insert( int val )
{
  Node* ptr = head;
  if( head == NULL )
  {
    head = new Node( val, NULL );
  }
  else 
  {
    while( ptr->next != NULL )
    {
      ptr = ptr->next;
    }
    ptr->next = new Node( val, NULL );
  }
}

bool List::remove( int val )
{
  Node* ptr = head;
  if( ptr == NULL )
  {
    return false;
  }
  if( head->data == val )
  {
    delete ptr;
    head = NULL;
    return true;
  }
  while( ptr->next != NULL )
  {
    if( ptr->next->data == val )
    {
      Node* temp = ptr->next;
      ptr->next = temp->next;
      delete temp;
      return true;
    }
    ptr = ptr->next;
  }
  return false;
}

class BST
{
  public:
    BST();
    ~BST();
    void insert( int );
    bool remove( int );
  private:
    class Node
    {
      public:
        Node( int, Node*, Node* );
        int data;
        Node *left, *right;
    };
    Node* root;
    void insertHelper( int, Node* & );
    bool removeHelper( int, Node* & );
};

BST::Node::Node( int val, Node* l, Node* r )
{
  data = val;
  left = l;
  right = r;
}

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  while( root != NULL )
  {
    remove( root->data );
  }
}

void BST::insertHelper( int val, Node* &ptr )
{
  if( ptr == NULL )
  {
    ptr = new Node( val, NULL, NULL );
  }
  else if( ptr->data > val )
  {
    insertHelper( val, ptr->left );
  }
  else if( ptr->data < val )
  {
    insertHelper( val, ptr->right );
  }
}

bool BST::removeHelper( int val, Node* &ptr )
{
  if( ptr == NULL )
  {
    return false;
  }
  if( ptr->data > val )
  {
    return removeHelper( val, ptr->left );
  }
  if( ptr->data < val )
  {
    return removeHelper( val, ptr->right );
  }
  if( ptr->right == NULL && ptr -> left == NULL )
  {
    delete ptr;
    ptr = NULL;
    return true;
  }
  if( ptr -> right == NULL )
  {
    Node* temp = ptr->left;
    delete ptr;
    ptr = temp;
    return true;
  }
  if( ptr -> left == NULL )
  {
    Node* temp = ptr->right;
    delete ptr;
    ptr = temp;
    return true;
  }
  Node* temp = ptr->left;
  while( temp->right != NULL )
  {
    temp = temp->right;
  }
  ptr->data = temp->data;
  removeHelper( ptr->data, ptr->left );
  return true;
}
