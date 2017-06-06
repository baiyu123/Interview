#include<iostream>
#include "dataStructure.h"

using namespace std;

struct balancedWithNumNodes{
  int numOfNodes;
  bool balanced;
  BTNode* result;
};

balancedWithNumNodes helper(BTNode* curr, int k){
  if(curr == NULL){
    return{0,true,NULL};
  }
  else{
    balancedWithNumNodes leftResult = helper(curr->left, k);
    balancedWithNumNodes rightResult = helper(curr->right, k);
    if(leftResult.balanced&&rightResult.balanced&&abs(leftResult.numOfNodes- rightResult.numOfNodes) > k){
        return {leftResult.numOfNodes+rightResult.numOfNodes+1, false, curr};
    }
    BTNode* result;
    if(leftResult.result!= NULL) result = leftResult.result;
    else result = rightResult.result;
    return{leftResult.numOfNodes+rightResult.numOfNodes+1, leftResult.balanced&&rightResult.balanced, result};
  }
}

BTNode* checkKBalance(BTNode* root, int k){
  return helper(root, k).result;
}

int main(){
  BTNode* root = new BTNode(314);
  root->emplaceR(6)->emplaceR(271)->emplaceR(28);
  root->right->emplaceL(2)->emplaceR(1)->emplaceL(401)->emplaceR(641);
  root->right->left->right->emplaceR(257);
  cout << checkKBalance(root, 3)->val << endl;
  return 0;
}
