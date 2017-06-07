#include <iostream>

using namespace std;

void writeBackward(string& str, int& index, string text){
  for(int i = text.size()-1; i >= 0; i--){
    str[index+i-text.size()+1] = text[i];
  }
  index -= text.size();
}

string encode(string& str){
  int extraSpace = 0;
  int leftPtr = str.size()-1;
  for(char elem : str){
    if(elem == '.') extraSpace += 2;
    else if(elem == ',') extraSpace += 4;
    else if(elem == '?') extraSpace += 12;
    else if(elem == '!') extraSpace += 15;
  }
  for(int i = 0; i < extraSpace; i++){
    str += ' ';
  }
  int rightPtr = str.size()-1;
  while(leftPtr != 0){
    if(str[leftPtr] == '.') writeBackward(str, rightPtr, "DOT");
    else if(str[leftPtr] == ',') writeBackward(str, rightPtr, "COMMA");
    else if (str[leftPtr] == '?') writeBackward(str, rightPtr, "QUESTION MARK");
    else if (str[leftPtr] == '!') writeBackward(str, rightPtr, "EXCLAMATION MARK");
    else{
      str[rightPtr] = str[leftPtr];
      rightPtr--;
    }
    leftPtr--;
  }
  return str;
}

int main(){
  string str ="Iwas,baiyu!and.Baixiao?---";
  cout << encode(str) << endl;
  return 0;
}