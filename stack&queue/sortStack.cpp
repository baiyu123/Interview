#include <iostream>
#include <stack>

using namespace std;

stack<int> sortStack(stack<int> input){
	stack<int> result;
	while(!input.empty()){
		if(result.empty()){
			result.push(input.top());
			input.pop();
		}
		int temp = input.top();
		input.pop();
		if(temp > result.top()){
			while(!result.empty()&&result.top() < temp){
				input.push(result.top());
				result.pop();
			}
		}
		result.push(temp);
	}
	return result;
}

int main(){
	stack<int> input;
	input.push(3);
	input.push(8);
	input.push(2);
	input.push(9);
	input.push(7);
	stack<int> result = sortStack(input);
	while(!result.empty()){
		cout << result.top() << endl;
		result.pop();
	}
	return 0;
}