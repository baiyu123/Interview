#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetWordHelper(string num, int currIndex, string result ,vector<string>& results, vector<string>& lookup){
  if(currIndex == num.size()){
    results.push_back(result);
  }
  else{
    string alphabet = lookup[num[currIndex]-'0'];
    for(int i = 0; i < alphabet.size(); i++){
      GetWordHelper(num, currIndex+1, result+alphabet[i], results, lookup);
    }
  }
}


vector<string> GetAllWords(string number){
  vector<string> lookup = {"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
  vector<string> result;
  GetWordHelper(number, 0, "", result, lookup);
  return result;
  
}


int main(){
  vector<string> result = GetAllWords("234512333");
  for(string str : result){
    cout << str << endl;
  }
  return 0;
}