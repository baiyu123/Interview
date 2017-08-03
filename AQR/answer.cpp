#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <stack>
#include <sstream>

using namespace std;

int powerOfQ(int p, int q){
	int sum = p;
	bool odd = false;
	if(q % 2 == 1){
		odd = true;
		q--;
	}
	while(q > 1){
		sum = sum*sum;
		q = q/2;
	}
	if(odd) sum *= p;
	return sum;
}


/////////////////////////sort array//////////////////

enum arrType
{
	NUMBER,
	CHARACTER
};

bool isNumber(char a){
	if(a>= '0' && a <= '9') return true;
	return false;
}

void sortArray(string& str){
	if(str.size() == 0)return;
	int leftPtr = 0;
	int rightPtr = 0;
	arrType currType;
	if(isNumber(str[0])) currType = NUMBER;
	while(leftPtr < str.size()){
		if(currType == NUMBER){
			while(isNumber(str[rightPtr])&&rightPtr < str.size()) rightPtr++;
			currType = CHARACTER;
		}
		else{
			while(!isNumber(str[rightPtr])&&rightPtr < str.size()) rightPtr++;
			currType = NUMBER;
		}
		sort(str.begin()+leftPtr, str.begin()+rightPtr);
		leftPtr = rightPtr;
	}
	return;
}


///////////////////////count sort/////////////////////
string intToString(int a){
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}


string countSort(string arr){
	int count[10] = {0};
	string result ="";
	
	for(int i = 0; i < arr.size(); i++){
		count[arr[i]-'0']++;
	}
	
	for(int i = 0 ; i < 10; i++){
		cout << count[i] << endl;
		while(count[i] > 0){

			result += intToString(i);
			count[i]--;
		}
	}
	return result;
}

vector < int > sortIntegers(vector < int >& n) {
    vector<int> count = vector<int>(10, 0);
	vector<int> result;
	for(int i = 0; i < n.size(); i++){
		count[n[i]]++;
	}
	for(int i = 0 ; i < 10; i++){
		while(count[i] > 0){
			result.push_back(i);
			count[i]--;
		}
	}
	return result;
}



int main(){
	string str = "664553888266383392020";
	cout << countSort(str) << endl;
	return 0;
}