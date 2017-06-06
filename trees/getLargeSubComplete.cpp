#include <iostream>

using namespace std;


struct Node
{
  int val;
  Node* left;
  Node* right;
  Node(int newVal){
    val = newVal;
    left = NULL;
    right = NULL;
  }
};

bool helper(Node* curr, Node* complete){
  if(curr->left == NULL&&curr->right != NULL) return false
}

Node* largestComplete(Node* root){
  Node* complete = NULL;
  helper(root, complete);
  return complete;
}


int main(){
  
  return 0;
}