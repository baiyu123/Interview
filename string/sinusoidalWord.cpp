#include <iostream>
#include <string>
#include <vector>

using namespace std;


string findSnakeString(string str){
  string result;
  for(int i = 1; i < str.size(); i += 4){
    result += str[i];
  }
  
  for (int i = 0; i < str.size(); i += 2) {
    result += str[i];
  }
  for (int i = 3; i < str.size(); i += 4) {
    result += str[i];
  }
  return result;
}


int main(){
  cout << findSnakeString("Hello World!") << endl;
  return 0;
}