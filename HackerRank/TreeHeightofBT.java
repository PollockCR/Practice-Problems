// https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree

/*
  class Node
    int data;
    Node left;
    Node right;
*/
static int height(Node root) {
if(root != null){
  int leftHeight = heightHelper(root.left, 0);
  int rightHeight = heightHelper(root.right, 0);
  return Math.max(leftHeight, rightHeight);
}
return 0;
}

static int heightHelper(Node ptr, int heightSoFar){
if(ptr != null){
  heightSoFar++;
  int leftHeight = heightHelper(ptr.left, heightSoFar);
  int rightHeight = heightHelper(ptr.right, heightSoFar);
  return Math.max(leftHeight, rightHeight);
}
return heightSoFar;
}
