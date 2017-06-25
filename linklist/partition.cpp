#include <iostream>
#include "dataStructure.h"

using namespace std;


void partition(int k, LLNode* root){
  LLNode* smaller = NULL;
  LLNode* equal = NULL;
  LLNode* greater = NULL;
  LLNode* smallerHead = NULL;
  LLNode* equalHead = NULL;
  LLNode* greaterHead = NULL;
  LLNode* curr = root;
  while(curr!= NULL){
    if(curr->val<k){
      if(smallerHead == NULL){
        smallerHead = curr;
        smaller = smallerHead;
      }
      else{
        smaller->next = curr;
        smaller = curr;
      }
    }
    if(curr->val == k){
      if(equalHead == NULL){
        equalHead = curr;
        equal = equalHead;
      }
      else{
        equal->next = curr;
        equal = curr;
      }
    }
    if(curr->val > k){
      if(greaterHead == NULL){
        greaterHead = curr;
        greater = greaterHead;
      }
      else{
        greater->next = curr;
        greater = curr;
      }
    }
    curr = curr->next;
  }
  smaller->next = equalHead;
  equal->next = greaterHead;
  greater->next = NULL;
}

int main(){
  LLNode* root = new LLNode(3);
  root->emplace(2)->emplace(2)->emplace(11)->emplace(7)->emplace(5)->emplace(11);
  partition(7,root);
  return 0;
}