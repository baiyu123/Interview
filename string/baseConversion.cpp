#include <iostream>

using namespace std;

string baseConversion(string numStr, int b1, int b2){
  int sum = 0;
  string result = "";
  //convert to base 10
  for (int i = 0; i < numStr.size(); i++) {
    if(numStr[i]>='0'&&numStr[i]<='9'){
      sum = sum*b1 + numStr[i]-'0';
    }
    else{
      sum = sum*b1 + numStr[i]-'A'+10;
    }
  }
  //convert to base b2
  while(sum > 0){
    int temp = sum%b2;
    if(temp >= 10){
      result = (char)(temp-10+'A') + result;
    }
    else{
      result = (char)(temp+'0')+result;
    }
    sum = sum/b2;
  }
  return result;
}


int main(){
  string str = "11111111";
  cout << baseConversion(str, 2, 16) << endl;
  return 0;
}