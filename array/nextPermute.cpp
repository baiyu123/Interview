#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void nextPermutation(vector<int>& perm){
  int maxNum = 0;
  for(int i = perm.size()-1; i >= 0; i--){
    
    if(maxNum > perm[i]){
      auto it = upper_bound(perm.rbegin(), perm.rend(), perm[i]);
      cout << *it<< "ddddd" << endl;
      swap(perm[i],*it);
      reverse(perm.begin()+i+1,perm.end());
      break;
    }
    maxNum = max(maxNum, perm[i]);

    
  }
}

int main(){
  vector<int> test = {6,2,1,5,4,3,0};
  nextPermutation(test);
  for(auto elem : test){
    cout << elem << endl;
  }
  return 0;
}