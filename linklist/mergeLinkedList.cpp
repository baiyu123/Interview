#include <iostream>
#include "dataStructure.h"

using namespace std;

LLNode* mergeLists(LLNode* root1, LLNode* root2){
  LLNode* finalRoot = new LLNode(0);
  LLNode* curr;
  curr = finalRoot;
  while(root1 != NULL && root2 != NULL){
    if(root1->val > root2->val) {
      curr->next = root2;
      root2 = root2->next;
    }
    else{
      curr->next = root1;
      root1 = root1->next;
    }
    curr = curr->next;
  }
  if(root1 == NULL){
    curr->next = root2;
  }
  else{
    curr->next = root1;
  }
  return finalRoot->next;
}

int main(){
  LLNode* r1 = new LLNode(1);
  r1->emplace(4)->emplace(5)->emplace(7);
  LLNode* r2 = new LLNode(2);
  r2->emplace(3)->emplace(6);
  LLNode* root = mergeLists(r1, r2);
  return 0;
}
