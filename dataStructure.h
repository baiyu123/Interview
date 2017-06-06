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
