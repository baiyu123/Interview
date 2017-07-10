#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <unordered_map>
#include <climits>

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

//////////////////2D sorted arrays//////////////
bool checkArray(int k, vector<vector<int>>& arr){
	int row = 0;
	int col = arr[0].size()-1;
	while(row < arr.size()&&col>=0){
		cout << arr[row][col] << endl;
		if(arr[row][col] > k){
			col--;
		}
		else if(arr[row][col] == k){
			return true;
		}
		else{
			row++;
		}
	}
	return false;
}

////////////////////kth largest//////////////

void printArr(vector<int>& arr){
	for(auto elem : arr){
		cout << elem << " ";
	}
	cout << endl;
}

int findKthLargest(int k, vector<int>& arr){
	int left = 0;
	int right = arr.size()-1;
	int start = 0;
	int end = right;
	while(start < end){
		left = start;
		right = end;
		int mid = (start+end)/2;
		int pivot = arr[mid];
		cout << start<< " "<< end << endl;
		while(left < right){
			while(arr[left] <= pivot && left < right) left++;
			while(arr[right] >= pivot && left < right) right--;
			cout << "left" << left << "right" << right << endl;
			if(left < right){
				swap(arr[left],arr[right]);
				left++;
				right--;
			}
		}
		if((arr[left] < arr[mid] && left > mid)||(arr[left] > arr[mid] && left < mid))
		swap(arr[mid],arr[left]);

	
		printArr(arr);
		if(arr.size()-left > k){
			start = left+1;
		}
		else if(arr.size()-left < k){
			end = left-1;
		}
		else{
			return arr[left];
		}
		cout << "start: " << start << "end: " << end << endl;
	}
	return arr[start];
}


///////////////////////find missing element/////////

int findMissingOrDuplicateElem(vector<int>& arr, int k){
	int arrXOR = 0;
	int comXOR = 0;
	for(int i = 0; i <= k; i++){
		comXOR = comXOR^i;
	}
	for(int i = 0; i < arr.size(); i++){
		arrXOR = arrXOR^arr[i];
	}
	return comXOR^arrXOR;
}

int findMissingAndDuplicateElem(vector<int>& arr, int k){
	int arrXOR = 0;
	int comXOR = 0;

	for(int i = 0; i < arr.size(); i++){
		arrXOR = arrXOR^arr[i];
		comXOR = comXOR^i;
	}
	int missingDupXOR = comXOR^arrXOR;
	int rightMost = missingDupXOR&~(missingDupXOR-1);
	arrXOR = 0;
	comXOR = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i]&~(arr[i]-1) & rightMost){
			arrXOR = arrXOR^arr[i];
		}
		if(i&~(i-1) & rightMost){
			comXOR = comXOR^i;
		}
	}
	
	int result1 = arrXOR^comXOR;
	int result2 = missingDupXOR^result1;
	return result2;
}

/////////////////////////////permute palindrom permute /////////////////////

bool testPalindromPermute(string input){
	int countArr[26] = {0};
	for(int i = 0; i < input.size(); i++){
		countArr[input[i]-'a']++;
	}
	bool ignoreMiddle = false;
	if(input.size()%2 == 1) ignoreMiddle = true;
	for(auto elem : countArr){
		if(elem%2 == 1){
			if(!ignoreMiddle) return false;
			ignoreMiddle = false;
		}
	}
	return true;
}
//////////////////////////////ISBN ///////////////////////////
class ISBN{
public:
	struct Book{
		int ISBN_num;
		int price;
		Book(int num, int p){
			ISBN_num = num;
			price = p;
		}
	};
	deque<Book> cache;
	unordered_map<int, deque<Book>::iterator> hashMap;
	int capacity;

	ISBN(int size){
		capacity = size;
	}
	int lookUp(int isbn){
		auto it = hashMap.find(isbn);
		if(it == hashMap.end()) return -1;
		Book tempBook(it->first, (*(it->second)).price);
		cache.push_front(tempBook);
		cache.erase(it->second);
		return (*(it->second)).price;
	}
	int insert(int isbn, int price){
		if(cache.size() >= capacity){
			hashMap.erase(hashMap.find(cache.back().ISBN_num));
			cache.pop_back();

		}
		Book tempBook(isbn, price);
		cache.push_front(tempBook);
		hashMap[isbn] = cache.begin();
	}
	bool remove(int isbn){
		auto it = hashMap.find(isbn);
		if(it == hashMap.end()) return false;
		cache.erase(it->second);
		hashMap.erase(it);
	}
};
 

 /////////////////k most frequent queries/////////////////

class compare{
public:
	bool operator()( pair<string, int> str1,  pair<string, int> str2){
		return str1.second > str2.second;
	}
};

string kMostFrequent(vector<string>& input, int k){
	unordered_map<string, int> map;
	priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pQueue;
	for(int i = 0; i < input.size(); i++){
		auto it = map.find(input[i]);
		if(it == map.end()){
			map[input[i]] = 1;
		}
		else{
			it->second++;

		}
	}

	for(auto elem : map){
		if(pQueue.size()>=k&&pQueue.top().second < elem.second){
			cout << elem.first << endl;
			pQueue.pop();
			pQueue.emplace(elem.first, elem.second);
		}
		if(pQueue.size() < k){
			pQueue.push(make_pair(elem.first, elem.second));
		}
	}
	return pQueue.top().first;
}

///////////////////////////nearest repeated dist///////////////////////////

int nearestRepeatedDist(vector<string>& input){
	unordered_map<string, int> map;
	int nearest = INT_MAX;
	for(int i = 0; i < input.size(); i++){
		auto it = map.find(input[i]);
		if(it != map.end()){
			int temp = i-it->second;
			it->second = i;
			nearest = min(temp,nearest);
		}
		else{
			map[input[i]] = i;
		}
	}
	return nearest;
}


int main(){
	vector<string> input = {"All","work","and","no","play","makes","for","no","work","no","fun","and","no","results"};
	cout << nearestRepeatedDist(input) << endl;
}