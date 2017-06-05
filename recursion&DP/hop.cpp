#include <iostream>
#include <unordered_map>

using namespace std;

static unordered_map<int,int> myMap;

int numOfComb(int remaining){
	if(remaining < 0){
		return 0;
	}
	else if(remaining == 0){
		return 1;
	}
	else{
		auto it = myMap.find(remaining);
		if(it == myMap.end()){
			myMap[remaining] = numOfComb(remaining-1)+numOfComb(remaining-2)+numOfComb(remaining-3);
			it = myMap.find(remaining);
		}
		return it->second;
	}
}

int main(){
	cout << numOfComb(34) << endl;
	return 0;
}