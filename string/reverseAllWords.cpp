#include <iostream>

using namespace std;


string reverseSentence(string str){
  int index = 0;
  int left = 0;
  int right;
  while(index <= str.size()){
    if(str[index] == ' '||index == str.size()){
      right = index;
      reverse(str.begin()+left,str.begin()+right);
      left = index+1;
    }
    index++;
  }
  left = 0;
  reverse(str.begin(), str.end());
  return str;
}

int main(){
  string str = "BY loves Rainia";
  cout << reverseSentence(str) << endl;
  return 0;
}