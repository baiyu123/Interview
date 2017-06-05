#include <iostream>
#include <stack>

using namespace std;

int evaluate(int x, int y, char oprator){
	if(oprator == '+'){
		return x+y;
	}
	else if(oprator=='-'){
		return x-y;
	}
	else if(oprator=='x'){
		return x*y;
	}
	else{
		return x/y;
	}
}

int rpn(string str){
	stack<int> myStack;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '+'||str[i] == '-'||str[i] == 'x'||str[i]=='/'){
			int y = myStack.top();
			myStack.pop();
			int x = myStack.top();
			myStack.pop();
			int temp = evaluate(x,y,str[i]);
			cout << x << endl;
			myStack.push(temp);
		}
		else{
			myStack.push(str[i]-'0');
		}
	}
	return myStack.top();
}

int main(){
	string rpnstr = "34+2x1+";
	int val = rpn(rpnstr);
	cout << val << endl;
	return 0;
}