#include <iostream>
#include "dataStructure.h"

using namespace std;

void reverseOrder(int start, int end, LLNode* root){
  LLNode* subHead = root;
  for(int i = 0; i < start; i++){
    subHead = subHead->next;
  }
  LLNode* currPrev = subHead;
  LLNode* curr = subHead->next;
  LLNode* currNext = curr->next;
  for(int i = start; i < end; i++){
    curr->next = currPrev;
    currPrev = curr;
    curr = currNext;
    if(currNext)currNext=currNext->next;
  }
  subHead->next->next = curr;
  subHead->next = currPrev;
}

int main(){
  LLNode* root = new LLNode(1);
  root->emplace(2)->emplace(3)->emplace(4)->emplace(5)->emplace(6);
  reverseOrder(2, 5, root);
  return 0;
}