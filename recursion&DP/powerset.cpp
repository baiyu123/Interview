#include <iostream>
#include <vector>
#include <string> 

using namespace std;

void helper(string& input, int index, vector<string>& vec, string currStr){
	if(index == input.size()){
		vec.push_back(currStr);
		return;
	}
	else{
		helper(input, index+1, vec, currStr);
		currStr += input[index];
		helper(input, index+1, vec, currStr);
	}
}

vector<string> findSubset(string input){
	vector<string> vec;
	helper(input,0,vec, "");
	return vec;
}

int main(){
	string set = "abcdef";
	vector<string> vec = findSubset(set);
	for(auto str : vec){
		cout << str << endl;
	}
	cout << vec.size() << endl;
	return 0;
}