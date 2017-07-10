#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//////merge k arrays/////
class compare{
public:
	bool operator()(pair<vector<int>::iterator, vector<int>::iterator> aPair,pair<vector<int>::iterator, vector<int>::iterator> bPair){
		return *aPair.first > *bPair.first;
	}
};

vector<int> mergeKArray(vector<vector<int>>& arrays){
	priority_queue<pair<vector<int>::iterator, vector<int>::iterator>, vector<pair<vector<int>::iterator, vector<int>::iterator>>, compare> minHeap;
	vector<int> result;
	for(int i = 0; i < arrays.size(); i++){
		minHeap.push({arrays[i].begin(),arrays[i].end()});
	}
	
	while(!minHeap.empty()){
		int num = *minHeap.top().first;
		result.push_back(num);
		auto temp = minHeap.top();
		minHeap.pop();
		if(++temp.first != temp.second) minHeap.push(temp);
	}
	return result;
}
////////////////////////increasing-decreasing array//////////////

void printVec(vector<int>& arr){
	for(int elem : arr){
		cout << elem << endl;
	}
}
void printVec(vector<double>& arr){
	for(auto elem : arr){
		cout << elem << endl;
	}
}


vector<int> increaseDecrease(vector<int>& array){
	vector<vector<int>> increseArrays;
	vector<vector<int>> decreaseArrays;
	bool increase = true;
	vector<int> temp;
	for(int i = 0; i < array.size(); i++){
		temp.push_back(array[i]);
		if(i != array.size()-1){
			if(array[i+1] < array[i]&&increase){
				increase = false;
				increseArrays.push_back(temp);
				temp.clear();
			}
			else if(array[i+1] > array[i]&&!increase){
				increase = true;
				decreaseArrays.push_back(temp);
				temp.clear();
			}
		}
	}
	decreaseArrays.push_back(temp);
	cout << "increase: " << increseArrays.size() << endl;
	cout << "decrease: " << decreaseArrays.size() << endl;
	for(int i = 0; i < decreaseArrays.size(); i++){
		reverse(decreaseArrays[i].begin(), decreaseArrays[i].end());
		increseArrays.push_back(decreaseArrays[i]);
	}
	return mergeKArray(increseArrays);
}

class minComp{
public:
	bool operator()(int a, int b){
		return a > b;
	}
};

class maxComp{
public:
	bool operator()(int a, int b){
		return a < b;
	}
};

void almostSorted(int k, vector<int>& input){
	priority_queue<int, vector<int>, minComp> minHeap;
	for(int i = 0; i < k; i++){
		minHeap.push(input[i]);
	}
	for(int i = k; i < input.size(); i++){
		input[i-k] = minHeap.top();
		minHeap.pop();
		minHeap.push(input[i]);
	}
	for(int i = input.size()-k; i < input.size(); i++){
		input[i] = minHeap.top();
		minHeap.pop();
	}
}

////////////////////median of stream data////////////

vector<double> medianStream(vector<int>& data){
	priority_queue<int, vector<int>, maxComp> maxHeap;
	priority_queue<int, vector<int>, minComp> minHeap;
	vector<double> result;
	for(int i = 0; i < data.size(); i++){
		minHeap.push(data[i]);
		if(minHeap.size()-1 > maxHeap.size()){
			maxHeap.push(minHeap.top());
			minHeap.pop();
			result.push_back(((double)minHeap.top()+maxHeap.top())/2);
		}
		else{
			result.push_back(minHeap.top());
		}
	}
	return result;
}

//////////stack with heap////////////////
class TheStack{
public:
	int top(){
		return maxHeap.top().val;
	}
	void push(int val){
		heapElem elem;
		elem.time = timeStamp++;
		elem.val = val;
		maxHeap.push(elem);
	}
	void pop(){
		maxHeap.pop();
	}

private:
	int timeStamp = 0;
	struct heapElem{
		int time, val;
		bool operator<(const heapElem other) const{
			return time < other.time;
		}
	};
	priority_queue<heapElem, vector<heapElem>> maxHeap;
};


int main(){
	TheStack myStack;
	myStack.push(2);
	myStack.push(3);
	cout << myStack.top() << endl;
	myStack.pop();
	cout << myStack.top() << endl;
	return 0;
}
