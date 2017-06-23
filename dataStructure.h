#pragma once


struct BTNode
{
  int val;
  BTNode* left;
  BTNode* right;
  BTNode(int newVal){
    val = newVal;
    left = NULL;
    right = NULL;
  }
  BTNode* emplaceL(int num){
    left = new BTNode(num);
    return left;
  }
  
  BTNode* emplaceR(int num){
    right= new BTNode(num);
    return right;
  }
};

struct LLNode{
  int val;
  LLNode* next;
  LLNode(int newVal){
    val = newVal;
    next = NULL;
  }
  LLNode* emplace(int num){
    next = new LLNode(num);
    return next;
  }
};
