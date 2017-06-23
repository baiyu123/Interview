#include <iostream>
#include "dataStructure.h"

using namespace std;

LLNode* shiftByNum(int k, LLNode* root){
  LLNode* front = root;
  LLNode* back = root;
  for(int i = 0; i < k; i++){
    front = front->next;
  }
  while(front->next != NULL){
    front = front->next;
    back = back->next;
  }
  front->next = root;
  root = back->next;
  back->next = NULL;
  return root;
}

int main(){
  LLNode* root = new LLNode(2);
  root->emplace(3)->emplace(5)->emplace(3)->emplace(2);
  root = shiftByNum(5, root);
  return 0;
}