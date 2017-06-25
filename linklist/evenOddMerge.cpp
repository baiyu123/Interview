#include <iostream>
#include "dataStructure.h"

using namespace std;

void evenOddMerge(LLNode* root){
  LLNode* oddPtr = root;
  LLNode* evenPtr = root->next;
  LLNode* evenRoot = evenPtr;
  while(oddPtr&&evenPtr){
    oddPtr->next = evenPtr->next;
    if(oddPtr->next)
    oddPtr = oddPtr->next;
    evenPtr->next = oddPtr->next;
    evenPtr = evenPtr->next;
  }
  oddPtr->next = evenRoot;
}

int main(){
  LLNode* root = new LLNode(1);
  root->emplace(2)->emplace(3)->emplace(4)->emplace(5)->emplace(6);
  evenOddMerge(root);
  return 0;
}