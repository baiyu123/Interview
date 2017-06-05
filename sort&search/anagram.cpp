#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool greaterEqual(string left, string right){
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	if(left >= right) return true;
	return false;
}

void merge(vector<string>& arr, vector<string>& result,int left,int middle,int right){
	int resultInd = left;
	int leftptr = left;
	int rightptr = middle;
	while(leftptr <= middle && rightptr <= right){
		if(greaterEqual(arr[leftptr], arr[rightptr])){
			result[resultInd] = arr[rightptr];
			rightptr++;
		}
		else{
			result[resultInd] = arr[leftptr];
			leftptr++;
		}
		resultInd++;
	}
	if(rightptr == right){
		while(leftptr <= middle){
			result[resultInd] = arr[leftptr];
			leftptr++;
			resultInd++;
		}
	}
}

void mergesort(vector<string>& arr, vector<string>& result, int left, int right){
	if(left < right){
		int middle = (left+right)/2;
		mergesort(arr,result,left,middle);
		mergesort(arr, result, middle+1, right);
		merge(arr, result, left, middle, right);
	}
}

vector<string> sortAnagram(vector<string> arr){
	vector<string> result = arr;
	mergesort(arr,result,0, arr.size()-1);
	return result;
}



int main(){
	vector<string> arr;
	arr.push_back("abc");
	arr.push_back("cde");
	arr.push_back("cab");
	arr.push_back("ecd");
	arr.push_back("abb");
	vector<string> sortedArr = sortAnagram(arr);
	for(auto it : sortedArr){
		cout << it << endl;
	}
}