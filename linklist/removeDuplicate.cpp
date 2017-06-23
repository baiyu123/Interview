#include <iostream>
#include "dataStructure.h"

using namespace std;

void removeDup(LLNode* root){
  LLNode* curr = root;
  while( curr->next != NULL){
    if(curr->val == curr->next->val){
      curr->next = curr->next->next;
    }
    else{
      curr = curr->next;
    }
  }
}

int main(){
  LLNode* root = new LLNode(1);
  root->emplace(2)->emplace(2)->emplace(3)->emplace(4)->emplace(4)->emplace(4);
  removeDup(root);
  return 0;
}