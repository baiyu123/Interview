#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <stack>
#include "dataStructure.h"
#include <thread>
#include <chrono>

using namespace std;

//////////////////////////////LCA/////////////

BTNode* LCAhelper(BTNode* currNode, BTNode* node1, BTNode* node2){
	if(currNode == NULL) return NULL;
	else if(currNode == node1 || currNode == node2){
		return currNode;
	}
	else{
		BTNode* n1 = LCAhelper(currNode->left, node1, node2);
		BTNode* n2 = LCAhelper(currNode->right, node1, node2);
		if((n1 == node1 && n2 == node2)||(n1 == node2&&n2 == node1)){
			return currNode;
		}
		else if(n1 == NULL) return n2;
		else return n1;
	}
}


/////////////////////binary sum/////////////////
int calculateBinarySum(BTNode* currNode, int sum){
	if(currNode == NULL){
		return sum;
	}
	else{
		sum = sum*2;
		if(currNode->val == 1){
			sum++;
		}
		int left = 0;
		int right = 0;
		left = calculateBinarySum(currNode->left, sum);
		right = calculateBinarySum(currNode->right, sum);
		if(currNode->left&&currNode->right) {
			return left+right;
		}
		else if(currNode->left){
		 	return left;
		}
		else{
			return right;
		}
	}
}

//////////////////////////inorder trasversal////////////


void inorderTraverse(BTNode* root){
	stack<pair<BTNode*,bool>> myStack;
	myStack.push({root,false});
	while(!myStack.empty()){
		pair<BTNode*,bool> currPair = myStack.top();
		myStack.pop();
		if(currPair.second == false){
			currPair.second = true;
			myStack.push(currPair);
			if(currPair.first->left){

				myStack.push({currPair.first->left,false});
			}
		}
		else{
			
			if(currPair.first->right){
				myStack.push({currPair.first->right, false});
			}
		}
		
	}
}


//////////////////////////find next inorder node///////////////
BTNode* findNextNode(BTNode* currNode){
	if(currNode->right != NULL){
		BTNode* ptr = currNode->right;
		while(ptr->left != NULL){
			ptr = ptr->left;
		}
		return ptr;
	}
	else{
		BTNode* ptr = currNode;
		BTNode* parentPtr = ptr->parent;
		while(parentPtr!=NULL&&ptr != parentPtr->left){
			ptr = parentPtr;
			parentPtr = parentPtr->parent;
		}
		return parentPtr;
	}
}
/////////////////////////in order traseverse with o(1) space///////

BTNode* findFirstNode(BTNode* root){
	BTNode* currNode = root;
	while(currNode->left != NULL){
		currNode = currNode->left;
	}
	return currNode;
}


void inorderOneSpace(BTNode* root){
	BTNode* currNode = findFirstNode(root);
	while(currNode != NULL){
		cout << currNode->val << endl;
		currNode = findNextNode(currNode);
	}
}


////////////////////Reconstruct tree pre and in order////////////
BTNode* reconstructHelper(vector<int>& preArr, vector<int>& inArr, int& preIndex, int inStart, int inEnd){
	if(inStart == inEnd){
		return new BTNode(inArr[inStart]);
	}
	BTNode* ptr = new BTNode(preArr[preIndex]);
	int mid = 0;
	for(int i = inStart; i <= inEnd; i++){
		if(inArr[i] == preArr[preIndex]){
			mid = i;
			break;
		}
	}
	if(mid-1 >= inStart)
	ptr->left = reconstructHelper(preArr,inArr,++preIndex,inStart, mid-1);
	if(mid+1 <= inEnd)
	ptr->right = reconstructHelper(preArr,inArr,++preIndex,mid+1,inEnd);
	return ptr;
}

BTNode* reconstructPreIn(vector<int>& preArr, vector<int>& inArr ){
	BTNode* root;
	int zero = 0;
	root = reconstructHelper(preArr,inArr,zero,0,inArr.size());
}

void preorderTraverse(BTNode* currNode){
	if(currNode == NULL) return;
	else{
		cout << currNode->val << endl;
		preorderTraverse(currNode->left);
		preorderTraverse(currNode->right);
	}
}
///////////////////////yelp 1/////////////////

class BusinessInfo{
public:
	int id;
	int rating;
	BusinessInfo(int id, int rating){
		this->id = id;
		this->rating = rating;
	}
	bool operator<(const BusinessInfo& other){
		return rating < other.rating;
	}
	bool operator>(const BusinessInfo& other){
		return rating > other.rating;
	}
};

vector<BusinessInfo> sortBusinessInfo(vector<BusinessInfo>& input){
	sort(input.begin(), input.end());
	return input;
}
////////////////////////////yelp 2///////////////////

vector<BusinessInfo> mergeTwoSortedList(vector<BusinessInfo>& list1, vector<BusinessInfo>& list2 ){
	vector<BusinessInfo> result;
	int ptr1 = 0;
	int ptr2 = 0;
	while(ptr1 < list1.size() && ptr2 < list2.size()){
		if(list1[ptr1]<list2[ptr2]){
			result.push_back(list1[ptr1]);
			ptr1++;
		}
		else{
			result.push_back(list2[ptr2]);
			ptr2++;
		}
	}
	if(ptr1 == list1.size()){
		while(ptr2 < list2.size()){
			result.push_back(list2[ptr2++]);
		}
	}
	else{
		while(ptr1 < list1.size()){
			result.push_back(list1[ptr1++]);
		}
	}
	return result;
}

///////////////////////yelp 3///////////////////////




 vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> nameMap;
        for(int i = 0; i < list1.size(); i++){
            nameMap[list1[i]] = i;
        }
        int min = INT_MAX;
        vector<string> results;
        for(int i = 0; i < list2.size(); i++){
            auto it = nameMap.find(list2[i]);
            if(it != nameMap.end()){
                int temp = it->second + i;
                if(temp < min){
                    min = temp;
                    results.clear();
                    results.push_back(it->first);
                }
                else if(temp == min){
                    results.push_back(it->first);
                }
            }
        }
        return results;
    }
////////////////////////yelp 4/////////////

string compressString(string str){
	string result = "";
	for(int i = 0; i < str.size(); i++){
		char curr = str[i];
		int count = 0;
		for(int j = i; j < str.size(); j++){
			if(str[j] != curr) break;
			count++;
		}
		result += to_string(count);
		result += curr;
		i += count-1;
	}
	return result;
}

int main(){
	// BTNode* root = new BTNode(1);
	// BTNode* node1 = new BTNode(2);
	// BTNode* node2 = new BTNode(3);
	// BTNode* node3 = new BTNode(4);
	// BTNode* node4 = new BTNode(5);
	// BTNode* node5 = new BTNode(6);
	// BTNode* node6 = new BTNode(7);
	// BTNode* node7 = new BTNode(8);
	// root->emplaceL(node1)->emplaceL(node2)->emplaceL(node3);
	// node2->emplaceR(node4);
	// node1->emplaceR(node5);
	// node5->emplaceR(node6)->emplaceL(node7);
	// vector<int> preorder = {8,2,6,5,1,3,4,7,9};
	// vector<int> inorder = {6,2,1,5,8,3,4,9,7};
	//BTNode* root1 = reconstructPreIn(preorder, inorder);
	//cout << root1->val << endl;
	//preorderTraverse(root1);
	////////yelp///////
	// BusinessInfo info1(101,1);
	// BusinessInfo info2(102,4);
	// BusinessInfo info3(103,6);
	// BusinessInfo info4(104,2);
	// BusinessInfo info5(105,3);
	// BusinessInfo info6(106,5);
	// vector<BusinessInfo> input1 = {info1, info2, info3};
	// vector<BusinessInfo> input2 = {info4, info5, info6};
	//vector<BusinessInfo> output = mergeTwoSortedList(input1, input2);
	
	// for(auto elem : output){
	// 	cout << elem.id << endl;
	// }

	string inputstr = "aaaaaaatttttttrrrrrreseeeiia";
	cout << compressString(inputstr) << endl;
}