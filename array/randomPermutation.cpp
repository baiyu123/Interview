#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void permute(vector<int>& vec){
  srand(time(NULL));
  for(int i = 0; i < vec.size(); i++){
    int index = rand()%(vec.size()-i)+i;
    swap(vec[i],vec[index]);
  }
}

int main(){
  vector<int> myVec = {1,2,3,4,5,6,7};
  permute(myVec);
  for(auto elem : myVec){
    cout << elem << endl;
  }
  return 0;
}