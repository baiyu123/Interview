#include <iostream>
#include <vector>

using namespace std;

bool helper(int index,vector<int>& input){
  if(index == input.size()-1) return true;
  else if(input[index] == 0) return false;
  else{
    for(int i = 1; i <= input[index]; i++){
        if(index+1 < input.size()&&helper(index+i, input)) return true;
    }
  }
  return false;
}

bool checkAdvance(vector<int>& input){
  return helper(0,input);
}

bool checkAdvanceIteration(vector<int>& input){
  int furthest = 0;
  for(int i = 0; i <= furthest&& i < input.size(); i++){
    furthest = max(furthest, i+input[i]);
  }
  return furthest >= input.size()-1;
}


int main(){
  vector<int> input = {3,0,1,0,2,0,1};
  cout << checkAdvanceIteration(input) << endl;
  return 0;
}