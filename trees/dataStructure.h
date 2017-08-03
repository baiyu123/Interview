#pragma once


struct BTNode
{
  int val;
  BTNode* left;
  BTNode* right;
  BTNode* parent;
  BTNode(int newVal){
    val = newVal;
    left = NULL;
    right = NULL;
    parent = NULL;
  }
  BTNode* emplaceL(int num){
    left = new BTNode(num);
    left->parent = this;
    return left;
  }
  
  BTNode* emplaceR(int num){
    right= new BTNode(num);
    right->parent = this;
    return right;
  }

  BTNode* emplaceL(BTNode* node){
    left = node;
    node->parent = this;
    return node;
  }

  BTNode* emplaceR(BTNode* node){
    right = node;
    node->parent = this;
    return node;
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
