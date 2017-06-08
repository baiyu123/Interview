#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkValid(string str){
  if(str.empty()) return false;
  if(str.size()>1 && str[0] == '0') return false;
  if(stoi(str) > 255) return false;
  return true;
}

vector<string>GetPossibleIP(string input){
  string ip1;
  string ip2;
  string ip3;
  string ip4;
  vector<string> results;
  //i j k are size
  for(int i = 1; i <= 3;i++){
    if(i>input.size()) break;
    ip1 = input.substr(0,i);
    if(!checkValid(ip1)) continue;
    for(int j = 1; j <= 3; j++){
      if(i+j>input.size()) break;
      ip2 = input.substr(i,j);
      if (!checkValid(ip2)) continue;
      for(int k = 1; k <=3; k++){
        if(i+j+k>input.size()) break;
        ip3 = input.substr(i+j,k);
        if(!checkValid(ip3)) continue;
        else{
          ip4 = input.substr(i+j+k);
          if(checkValid(ip4)){
            string result = ip1+'.'+ip2+'.'+ip3+'.'+ip4+'.';
            results.push_back(result);
          }
        }
      }
    }
  }
  return results;
}


int main(){
  vector<string> result = GetPossibleIP("1234123");
  for(string str : result){
    cout<< str << endl;
  }
  return 0;
}