#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int>& rule, vector<char>& data){
  char temp1 = data[0];
  char temp2;
  for(int i = 0; i < rule.size(); i++){
    if(rule[i] == -1) continue;
    temp2 = data[i];
    data[i] = temp1;
    temp1 = temp2;
    int nextLoc = rule[i];
    while(rule[nextLoc] != -1){
      int currLoc = nextLoc;
      nextLoc = rule[nextLoc];
      temp2 = data[currLoc];
      data[currLoc] = temp1;
      temp1 = temp2;
      rule[currLoc] = -1;
    }
    
  }
}


int main(){
  vector<int> rule = {2,0,1,3};
  vector<char> data = {'a','b','c','d'};
  permute(rule, data);
  
  return 0;
}