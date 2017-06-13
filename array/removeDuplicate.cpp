#include <iostream>
#include <vector>

using namespace std;


void removeDuplicate(vector<int>& input){

  int write_i = 1;
  for(int i = 1; i < input.size(); ++i){
    if(input[write_i-1] != input[i]){
      input[write_i++] = input[i];
    }
  }
}

int removeElement(vector<int>& input, int key){
  int write_index = 0;
  for(int i = 0; i < input.size(); ++i){
    if(input[i]!=key){
      input[write_index++] = input[i];
    }
  }
  return write_index;
}


int main(){
  vector<int> str = {2,3,5,5,7,5,5,5};
  int num = removeElement(str, 5);
  
  return 0;
}