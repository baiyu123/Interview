#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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


////////////////////longest contained interval ///////////////

int longestContainedInter(vector<int>& arr){
	unordered_set<int> set;
	for(int i = 0; i < arr.size(); i++){
		set.emplace(arr[i]);
	}
	int countMax = 0;
	for(int i = 0; i < arr.size(); i++){
		int count = 0;
		int offset = 0;
		while(true){
			auto it = set.find(arr[i]+offset);
			if(it != set.end()){
				count++;
				set.erase(it);
			}
			else{
				break;
			}
			offset++;
		}
		offset = -1;
		while(true){
			auto it = set.find(arr[i]+offset);
			if(it != set.end()){
				count++;
				set.erase(it);
			}
			else{
				break;
			}
			offset--;
		}
		countMax = max(count, countMax);
	}
	return countMax;
}

/////////////////////all string decomposition////////

string allStrDecomp(string sentence, vector<string>& words){
	unordered_map<string, int> wordMap;
	for(int i = 0; i < words.size(); i++){
		auto it = wordMap.find(words[i]);
		if(it != wordMap.end()){
			it->second++;
		}
		else{
			wordMap[words[i]] = 1;
		}
	}
	int size = words[0].size();
	int start = 0;
	int end = 0;
	for(int i = 0; i < sentence.size()-size; i++){
		unordered_map<string, int> tempMap = wordMap;
		auto it = tempMap.find(sentence.substr(i,size));
		if(it != wordMap.end()){
			start = i;
			int offset = 0;
			while(it != tempMap.end()){
				it->second--;
				if(it->second == 0){
					tempMap.erase(it);
				}
				offset++;
				if(offset*size+i > sentence.size()||tempMap.size() == 0){
					end = offset*size+i;
					break;
				}
				it = tempMap.find(sentence.substr(offset*size+i,size));
			}
			if(end-start == size*words.size()) break;
		}
	}
	return sentence.substr(start, end-start);
}


//////////////////////////Arrary intersect////////////

vector<int> computerArrsIntersect(vector<int>& arr1, vector<int>& arr2){
	int index1 = 0;
	int index2 = 0;
	int prevNum = 0;
	vector<int> result;
	while(index1<arr1.size() && index2<arr2.size()){
		if(arr1[index1] < arr2[index2]){
			index1++;
		}
		else if(arr1[index1] > arr2[index2]){
			index2++;
		}
		else if(arr1[index1]==arr2[index2]&&prevNum!=arr1[index1]){
			result.push_back(arr1[index1]);
			index1++;
			index2++;
			prevNum = arr1[index1];
		}
		else{
			index1++;
			index2++;
		}
	}
	return result;
}

//////////////////first name duplicate///////////
class Name{
public:
	string first_name, last_name;
	Name(string first, string last){
		first_name = first;
		last_name = last;
	}
	bool operator<(const Name& other){
		return this->first_name < other.first_name;
	}
	bool operator==(const Name& other){
		return this->first_name == other.first_name;
	}
};

void removeFirstNameDup(vector<Name>& arr){
	sort(arr.begin(),arr.end());
	for(int i = 0; i < arr.size()-1; i++){
		int next = i+1;
		while(arr[next] == arr[i]&&next < arr.size()){
			arr.erase(arr.begin()+next);
		}
	}
}

void printNameArr(vector<Name>& arr){
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i].first_name << " " << arr[i].last_name << endl;
	}
}

///////////////////////smallest non constructible value////////////
int smallestNonContructible(vector<int>& arr){
	int currVal = arr[0];
	int currSum = 0;
	sort(arr.begin(), arr.end());
	for(int i = 0; i < arr.size(); i++){
		if(currVal == arr[i]){
			currSum += arr[i];
		}
		else{
			currVal = arr[i];
			if(currSum < arr[i]-1){
				break;
			}
			currSum += arr[i];
		}
	}
	return currSum+1;
}

////////////////////maximum concurent////////////
class Event{
public:
	int Time;
	bool start;
	Event(int newTime, bool is_start){
		Time = newTime;
		start = is_start;
	}
	bool operator<(const Event& other){
		if(Time != other.Time){
			return Time < other.Time;
		}
		else{
			if(start) return false;
			return true;
		}
	}
};

int maxConcurrentEvent(vector<Event>& arr){
	sort(arr.begin(), arr.end());
	int count = 0;
	int maxCount = 0;
	for(int i = 0; i<arr.size(); i++){
		if(arr[i].start){
			count++;
		}
		else{
			count--;
		}
		maxCount = max(maxCount, count);
	}
	return maxCount;
}

///////////////////////merge interval//////////

class Interval{
public:
	int start;
	int end;
	Interval(int new_start, int new_end){
		start = new_start;
		end = new_end;
	}
	bool operator<(const Interval& other){
		return start < other.start;
	}
};


void printInteval(vector<Interval>& inte){
	for(int i = 0; i < inte.size(); i++){
		cout << "start: " << inte[i].start << " end: " << inte[i].end << endl;
	}
}


Interval UnionInterval(Interval inte1, Interval inte2){
	int left = min(inte1.start, inte2.start);
	int right = max(inte1.end, inte2.end);
	Interval inte(left, right);
	return inte;
}

vector<Interval> mergeInterval(vector<Interval>& input, Interval newInter){
	sort(input.begin(), input.end());
	vector<Interval> result;
	int left = 0;
	int right = 0;
	for(int i = 0; i < input.size(); i++){

		if((newInter.start >= input[i].start&&newInter.start <= input[i].end)||(newInter.end >= input[i].start&&newInter.end <= input[i].end)){
			left = i;
			break;
		}
		else if(newInter.start < input[i].start && newInter.end < input[i].start){
			left = i;
			break;
		}
		result.push_back(input[i]);
	}
	for(int i = left; i < input.size(); i++){
		if(newInter.end < input[i].start){
			right = i;
			break;
		}
		else{
			newInter = UnionInterval(newInter,input[i]);
		}
	}
	result.push_back(newInter);

	for(int i = right; i < input.size(); i++){
		result.push_back(input[i]);
	}
	return result;
}

vector<Interval> mergeIntervalOld(vector<Interval>& input, Interval newInter){
	sort(input.begin(), input.end());
	vector<Interval> result;
	int left = 0;
	int right = 0;
	for(int i = 0; i < input.size(); i++){
		result.push_back(input[i]);
		if(newInter.start < input[i].start){
			left = i;
			if(i>0&&newInter.start < input[i-1].end){
				result[i-1].end = result[i].end;
				result.pop_back();
			}
			input[i].start = newInter.start;
			break;
		}
	}
	printInteval(result);
	cout << "///////////" << endl;
	bool found = false;
	for(int i = left; i < input.size()-1; i++){
		if(found) result.push_back(input[i]);
		if(newInter.end < input[i].end){
			found = true;
			if(newInter.end > input[i].start){
				result.back().end = input[i].end;
			}
			else{
				result.back().end = newInter.end;
				result.push_back(input[i]);
			}
			//cout << result.back().start << result.back().end << endl;
		}
		
	}
	return result;
}



/////////////////sort repeated entry////////////

class person{
public:
	person(int newAge, string newName){
		age = newAge;
		name = newName;
	}
	int age;
	string name;
};

vector<person> sortRepeatedEntry(vector<person>& arr){
	unordered_map<int, vector<int>> map;
	for(int i = 0; i < arr.size(); i++){
		auto it = map.find(arr[i].age);
		if(it == map.end()){
			vector<int> temp = {i};
			map[arr[i].age] = temp;
		}
		else{
			it->second.push_back(i);
		}
	}
	vector<person> result;
	for(auto elem : map){
		for(int i = 0; i < elem.second.size(); i++){
			result.push_back(arr[elem.second[i]]);
		}
	}
	return result;
}
void sortRepeatedEntryLessSpace(vector<person>& arr){
	unordered_map<int, int> countMap;
	unordered_map<int, int> offsetMap;
	for(int i = 0; i < arr.size(); i++){
		auto it = countMap.find(arr[i].age);
		if(it == countMap.end()){
			countMap[arr[i].age] = 1;
		}
		else{
			it->second++;
		}
	}
	int offset = 0;
	for(auto elem : countMap){
		cout << "age: " << elem.first << "offset: " << offset << endl;
		offsetMap[elem.first] = offset;
		offset+= elem.second;
	}
	for(int i = 0; i < arr.size(); i++){
		auto it = offsetMap.find(arr[0].age);
		swap(arr[it->second],arr[0]);
		it->second++;
	}
}

void printPersonsArr(vector<person>& arr){
	for(person elem : arr){
		cout << elem.name << endl;
	}
}

////////////////////////cap salary/////////////////////
int calculateCap(vector<int>& salaries, int budget){
	sort(salaries.begin(),salaries.end());
	int sum = 0;
	int index = 0;
	int pay = 0;
	for(int i = 0; i < salaries.size(); i++){
		sum += salaries[i];
		pay = sum+salaries[i]*(salaries.size()-1-i);
		if(pay >= budget){
			index = i;
			break;
		}
	}
	int difference = pay - budget;
	return salaries[index]-(difference/(salaries.size()-index));
}

int main(){
	vector<int> salaries = {90,30,100,40,20,150};
	cout << calculateCap(salaries,290) << endl;
}