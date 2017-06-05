#include <iostream>
#include <string>

using namespace std;

bool check(string str1, string str2){
	int i = 0;
	int j = 0;
	int replace = 0;
	int removec = 0;
	while(i < str1.size() && j < str2.size()){
		//remove or insert
		if(str1[i] != str2[j]){
			if(j+1 < str2.size()&&str1[i]==str2[j+1]){
				removec++;
				j++;
			}
			else if(i+1 < str1.size()&&str1[i+1] == str2[j]){
				removec++;
				i++;
			}
			//or replace
			else{
				replace++;
			}
		}
		i++;
		j++;
	}
	if(i != str1.size()-1){
		removec += str1.size() - str2.size();
	}
	if(j != str2.size()-1){
		removec += str2.size() - str1.size();
	}
	if(removec + replace > 1){
		return false;
	}
	else{
		return true;
	}
}

int main(){
	string str1 = "pale";
	string str2 = "bake";
	cout << check(str1, str2) << endl;
	return 0;
}