#include <iostream>
#include <string>

using namespace std;

string nextNum(string inputStr){
  string result = "";
  int count = 0;
  char temp = inputStr[0];
  for(int i = 0; i < inputStr.size(); i++){
    if(temp == inputStr[i]){
      count++;
    }
    else{
      result+= to_string(count)+temp;
      count = 1;
      temp = inputStr[i];
    }
  }
  result += to_string(count)+temp;
  return result;
}

string lookAndSay(int input){
  string inputStr = to_string(input);
  for(int i = 0; i < input; i++){
    inputStr = nextNum(inputStr);
  }
  return inputStr;
}

int main(){
  cout << lookAndSay(4) << endl;
}