// https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
#include <queue>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void levelOrder(node * root) {
  queue<node*> treeQueue;
  if(root){
    treeQueue.push(root);
  }
  while(!treeQueue.empty()){
    node* tree = treeQueue.front();
    treeQueue.pop();
    cout << tree->data << ' ';
    if(tree->left){
      treeQueue.push(tree->left);
    }
    if(tree->right){
      treeQueue.push(tree->right);
    }
  }
}
