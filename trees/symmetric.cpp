#include <iostream>
#include "dataStructure.h"

using namespace std;


bool checkHelper(BTNode* left, BTNode* right){
  if(!left&&!right) return true;
  else if(!left||!right) return false;
  else{
    if(left->val != right->val) return false;
    return checkHelper(left->left, right->right)&&checkHelper(left->right, right->left);
  }
}

bool checkSymmetric(BTNode* root){
  return checkHelper(root->left, root->right);
}


int main(){
  BTNode* root = new BTNode(1);
  root->emplaceL(2)->emplaceR(3);
  root->emplaceR(2)->emplaceL(3)->emplaceL(4);
  cout << checkSymmetric(root) << endl;
  return 0;
}