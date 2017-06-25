#include <iostream>
#include "dataStructure.h"

using namespace std;

LLNode* reverseOrder(LLNode* root){
  LLNode* dummyHead = new LLNode(0);
  dummyHead->next = root;
  LLNode* currPrev = dummyHead;
  LLNode* curr = dummyHead->next;
  LLNode* currNext = curr->next;
  while(curr!= NULL){
    curr->next = currPrev;
    currPrev = curr;
    curr = currNext;
    if(currNext)currNext=currNext->next;
  }
  dummyHead->next->next = NULL;
  dummyHead->next = currPrev;
  return currPrev;
}

bool testPalindrome(LLNode* root){
  LLNode* fast = root;
  LLNode* slow = root;
  while(fast != NULL&&fast->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
  }
  if(fast == NULL){
    slow = reverseOrder(slow);
  }
  else{
    slow = reverseOrder(slow->next);
  }
  LLNode* curr = root;
  while(slow != NULL){
    if(curr->val != slow->val) return false;
    slow = slow->next;
    curr = curr->next;
  }
  return true;
}

int main(){
  LLNode* root = new LLNode(1);
  root->emplace(2)->emplace(3)->emplace(4)->emplace(2)->emplace(2)->emplace(1);
  cout << testPalindrome(root) << endl;
  return 0;
}