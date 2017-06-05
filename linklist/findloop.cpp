#include <iostream>

using namespace std;

struct Node{
	int val;
	Node*next = NULL;
};

Node* loopDetect(Node* head){
	Node* fastPtr = head;
	Node* slowPtr = head;
	Node* intersect = NULL;
	while(fastPtr->next != NULL && fastPtr->next->next != NULL){
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
		if(fastPtr == slowPtr){
			intersect = slowPtr;
			break;
		}
	}
	if(intersect == NULL)return NULL;
	slowPtr = head;
	while(slowPtr != intersect){
		slowPtr = slowPtr->next;
		intersect = intersect->next;
	}
	return intersect;
}

struct Node* addBefore(Node* nd,int val){
	struct Node* newNode = new Node();
	newNode->next = nd;
	newNode->val = val;
	return newNode;
}

int main(){
	struct Node* tail = new Node();
	struct Node* head = NULL;
	head = addBefore(tail,1);
	head = addBefore(head,2);
	head = addBefore(head,3);
	head = addBefore(head,4);
	struct Node* loopstart = head;
	head = addBefore(head,5);
	head = addBefore(head,6);
	tail->next = head;
	head = addBefore(loopstart,11);
	head = addBefore(head,12);
	head = addBefore(head,13);
	head = addBefore(head,14);
	Node* result = loopDetect(head);
	if(result) cout << result->val << endl;
	return 0;
}