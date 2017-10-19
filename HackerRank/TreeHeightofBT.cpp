// https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree

/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
int height(Node* root) {
  if(root != NULL){
    int leftHeight = heightHelper(root->left,0);
    int rightHeight = heightHelper(root->right,0);
    return max(leftHeight, rightHeight);
  }
  return 0;
}

int heightHelper(Node* ptr, int heightSoFar){
  int leftHeight, rightHeight;
  if(ptr != NULL){
    heightSoFar++;
    leftHeight = heightHelper(ptr->left,heightSoFar);
    rightHeight = heightHelper(ptr->right,heightSoFar);
    return max(leftHeight, rightHeight);
  }
  return heightSoFar;
}
