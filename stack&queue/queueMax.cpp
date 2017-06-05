#include <iostream>
#include <deque>

using namespace std;

class queueMax{
public:
	queueMax(){

	}
	void enqueue(int num){
		queue.push_front(num);
		while(!maxQueue.empty()){
			if(num > maxQueue.back()){
				maxQueue.pop_back();
			}
			else{
				break;
			}
		}
		maxQueue.push_back(num);
	}

	void pop(){
		if(queue.front()==maxQueue.front()){
			maxQueue.pop_front();
		}
		queue.pop_front();
	}

	int max(){
		return maxQueue.front();
	}
private:
	deque<int> queue;
	deque<int> maxQueue;
};

int main(){
	queueMax myQueue;
	myQueue.enqueue(2);
	myQueue.enqueue(1);
	myQueue.enqueue(4);
	cout << myQueue.max() << endl;
	myQueue.enqueue(3);
	myQueue.enqueue(7);
	cout << myQueue.max() << endl;
	myQueue.enqueue(5);
	myQueue.enqueue(3);
	for(int i = 0; i < 6; i++)
	myQueue.pop();

	cout << myQueue.max() << endl;
	return 0;
}