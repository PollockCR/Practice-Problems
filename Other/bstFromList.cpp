// Implementation of a BST that can be constructed from a list of pre-order traversal

class BST
{
  public: 
    BST(){ root = NULL };
    BST( const List &aList );
    void insert( int );
  private:
    class Node
    {
      Node( int, Node*, Node* ) ;
      int data;
      Node* left;
      Node* right;
    };
    void insertHelper( int, Node* );
    
};

BST::BST( const List &aList )
{
  ListNode* aIt = aList.head;
  while( aIt != NULL )
  {
    insertHelper( aIt->data, root );
  }
}

void BST::insertHelper( int val, Node* ptr )
{
  if( ptr == NULL )
  {
    ptr = new Node( val, NULL );
  }
  else if( val > ptr-> data )
  {
    insertHelper( val, ptr->right );
  }
  else 
  {
    insertHelper( val, ptr->left );
  }
} 
