#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


////////////////////////anagram////////////////////////
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

///////////////////////search entry equal index ///////////////

int findEqualIndex(vector<int>& input){
	int left = 0;
	int right = input.size()-1;
	while(left < right){
		int mid = (left+right)/2;
		if(input[mid] == mid){
			return mid;
		}
		else if(input[mid] > mid){
			right = mid-1;
		}
		else{
			left = mid+1;
		}
	}
	return -1;
}
////////////////////cyclical sorted/////////////////////

int findKincyclical(int k, vector<int>& arr){
	int left = 0;
	int right = arr.size()-1;
	while(left<right-1){
		int mid = (left+right)/2;
		if(arr[mid]>arr[right]){
			left = mid;
		}
		else{
			right = mid;
		}
	}
	if(k > arr[right] && k < arr[arr.size()-1]){
		left = right;
		right = arr.size()-1;
	}
	else{
		left = 0;
		right--;
	}
	while(left<=right){
		int mid = (left+right)/2;
		cout << mid << endl;
		if(arr[mid]<k){
			left = mid+1;
		}
		else if(arr[mid] == k){
			return mid;
		}
		else{
			right = mid-1;
		}
	}
	return -1;
}
//////////////////////////compute squre root///////////////////

int computeSqr(int num){
	int left = 0;
	int right = num;
	while(left < right){
		int mid = (right+left)/2;
		if(mid*mid > num){
			right = mid-1;
		}
		else if(mid*mid == num){
			left = mid;
			break;
		}
		else{
			left = mid+1;
		}
	}
	return left;
}

int main(){
	
	cout << computeSqr(24) << endl;
}