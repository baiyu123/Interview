#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int calculateHash(string str){
	int hash = 0;
	for(int i = 0; i < str.size(); i++){
		hash += str[i]*pow(26,str.size()-i-1);
	}
	return hash%131;
}


bool findSubString(string array, string target){
	int targetHash = calculateHash(target);
	int left = 0;
	int right = target.size();
	if(array.size() < target.size()){
		return false;
	}
	else if(array.size() == target.size()){
		return targetHash == calculateHash(array);
	}
	//get the initial window hash
	string temp = "";
	for(int i = 0; i < target.size(); i++){
		temp += array[i];
	}
	int windowHash = calculateHash(temp);
	if(windowHash == targetHash) return true;
	while(right < array.size()){
		windowHash *= 26;
		windowHash += (int)array[right];
		windowHash -= ((int)array[left])*pow(26,target.size());
		windowHash %= 131;
		if(windowHash<0) windowHash+=131;
		if(windowHash == targetHash) return true;
		left++;
		right++;
	}
	return false;
}

int main(){
	string array = "allaha";
	string target = "allah";
	cout << findSubString(array,target) << endl;
	return 0;
}