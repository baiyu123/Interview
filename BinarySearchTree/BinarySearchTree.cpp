#include<iostream>
#include<vector>
#include<unordered_map>
#include<deque>
#include"datastructure.h"
#include<algorithm>
#include<sstream>

using namespace std;



void setRightSiblingHelper(BTNode* currNode, BTNode* rightSib) {
	if (currNode == NULL) return;
	else {
		currNode->rightSib = rightSib;
		setRightSiblingHelper(currNode->left, currNode->right);
		if(rightSib != NULL)
		setRightSiblingHelper(currNode->right, rightSib->left);
	}
}

void setRightSibling(BTNode* root) {
	setRightSiblingHelper(root->left, root->right);
	setRightSiblingHelper(root->right, NULL);
}

void findPathGoesDown(BTNode* currNode, int currSum, int target, vector<int> path, vector<vector<int>>& results) {
	if (currNode == NULL) return;
	currSum += currNode->val;
	path.push_back(currNode->val);
	if (currSum == target) {
		results.push_back(path);
	}
	else if (currSum > target) return;
	else {
		findPathGoesDown(currNode->left, currSum, target, path, results);
		findPathGoesDown(currNode->right, currSum, target, path, results);
	}
}

void findPathIterateRoot(BTNode* currNode,int target, vector<vector<int>>& results) {
	if (currNode == NULL) return;
	else {
		vector<int> emptyPath;
		findPathGoesDown(currNode,0,target, emptyPath, results);
		findPathIterateRoot(currNode->left, target, results);
		findPathIterateRoot(currNode->right, target, results);
	}
}

vector<vector<int>> findPath(BTNode* root, int target) {
	vector<int> path;
	vector<vector<int>> result;
	findPathIterateRoot(root, target, result);
	return result;

}



//////////////////////////////////////////////cache 2 ///////////////////////////////////////////////

class LRUCache {
public:
	class Node {
	public:
		int key;
		int val;
		Node(int newKey, int newVal) {
			key = newKey;
			val = newVal;
		}
	};

	LRUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {
		auto it = map.find(key);
		if (it != map.end()) {
			int result = (*(it->second)).val;
			moveFront(it->second);
			return result;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		
		auto it = map.find(key);
		if (it != map.end()) {
			(*(it->second)).val = value;
			moveFront(it->second);
		}
		else {
			if (m_list.size() == m_capacity) {
				auto it = map.find(m_list.back().key);
				map.erase(it);
				m_list.pop_back();
			}
			Node temp(key, value);
			m_list.push_front(temp);
			map[key] = m_list.begin();
		}
		
	}

	void moveFront(list<Node>::iterator it) {
		Node temp((*it).key, (*it).val);
		m_list.push_front(temp);
		map.erase((*it).key);
		m_list.erase(it);
		map[temp.key] = m_list.begin();
	}

	list<Node> m_list;
	unordered_map<int, list<Node>::iterator> map;
	int m_capacity;
};

int missingNumber(vector<int>& nums) {
	int xor;
	int orgXor;
	for (int i = 0; i < nums.size(); i++) {
		xor ^= nums[i];
	}
	for (int i = 0; i < nums[nums.size() - 1]; i++) {
		orgXor ^= i;
	}
	return xor^orgXor;
}
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	deque<int> myDeque;
	vector<int> result;
	if (nums.size() == 0) return result;
	for (int i = 0; i < k; i++) {
		if (myDeque.empty()) myDeque.push_back(nums[i]);
		else {
			while ( myDeque.size() > 0 && nums[i] > myDeque.back() ) {
				myDeque.pop_back();
			}
			myDeque.push_back(nums[i]);
		}
	}
	result.push_back(myDeque.front());
	for (int i = k; i < nums.size(); i++) {
		if (myDeque.front() == nums[i - k]) {
			myDeque.pop_front();
		}
		while (myDeque.size() > 0 && nums[i] > myDeque.back()) {
			myDeque.pop_back();
		}
		myDeque.push_back(nums[i]);
		result.push_back(myDeque.front());
	}
	return result;
}

int findNextNodeInBST(BTNode* root, int target) {
	BTNode* curr = root;
	int result;
	while (curr) {
		if (curr->val > target) {
			result = curr->val;
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	return result;
}


BTNode* reconstructBSTWithPreHelper(int leftBound, int rightBound, vector<int>& preOrder, int& index) {
	if (index >= preOrder.size()||preOrder[index] < leftBound || preOrder[index] > rightBound) {
		index--;
		return nullptr;
	}
	else {
		BTNode* currNode = new BTNode(preOrder[index]);
		currNode->left = reconstructBSTWithPreHelper(leftBound, currNode->val, preOrder, ++index);
		currNode->right = reconstructBSTWithPreHelper(currNode->val, rightBound, preOrder, ++index);
		return currNode;
	}

}

BTNode* reconstructBSTWithPre(vector<int>& preOrder) {
	int index = 0;
	return reconstructBSTWithPreHelper(INT_MIN, INT_MAX, preOrder, index);
}

////////////////////////////////////////////////////////////////////////draw bridge oa//////////////////////////////////////////////////
class node {
public:
	int elem;
	int count;
	node(int newElem, int newCount) : elem(newElem), count(newCount) {

	}
	bool operator<(const node& other) {
		return elem*count > other.elem*other.count;
	}
};
void deleteElems(int elem, vector<node>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].elem == elem+1 || vec[i].elem == elem-1|| vec[i].elem == elem) {
			vec.erase(vec.begin() + i);
			i--;
		}
	}
}

long maxPoints(vector < int > elements) {
	unordered_map<int, int> numToCount;
	vector<node> vecOfNode;
	for (int i = 0; i < elements.size(); i++) {
		auto it = numToCount.find(elements[i]);
		if (it != numToCount.end()) {
			it->second++;
		}
		else {
			numToCount[elements[i]] = 1;
		}
	}
	for (auto elem : numToCount) {
		node temp(elem.first, elem.second);
		vecOfNode.push_back(temp);
	}
	long result = 0;
	while (vecOfNode.size() != 0) {
		sort(vecOfNode.begin(), vecOfNode.end());
		result += vecOfNode[0].elem*vecOfNode[0].count;
		deleteElems(vecOfNode[0].elem, vecOfNode);
	}
	return result;
}

//////////////////////////////////////////////////rocket fuel////////////////////////////////////
struct Racer {
public:
	int ID;
	int startTime;
	int endTime;
	Racer(int id,int start, int end) : ID(id), startTime(start), endTime(end) {
		
	}

};

struct Point {
	int time;
	int ID;
	bool start;
	Point(int newTime, int id, bool isStart) : time(newTime), ID(id), start(isStart) {
	}
	bool operator<(const Point& other) {
		return time < other.time;
	}
};

class comp {
public:
	bool operator()(const pair<int,int>& left, const pair<int,int>& right) {
		return left.second < right.second;
	}
};



vector<pair<int, int>> CalculateScore(vector<Racer> input) {
	vector<pair<int, int>> result;
	unordered_map<int, int> IDToScore;
	vector<Point> ptVec;
	for (int i = 0; i < input.size(); i++) {
		IDToScore[input[i].ID] = 0;
		Point p1(input[i].startTime,input[i].ID, true);
		Point p2(input[i].endTime, input[i].ID, false);
		ptVec.push_back(p1);
		ptVec.push_back(p2);
	}
	sort(ptVec.begin(), ptVec.end());
	list<int> idList;
	for (int i = 0; i < ptVec.size(); i++) {
		if (ptVec[i].start) {
			idList.push_back(ptVec[i].ID);
		}
		else {
			int needRemove = ptVec[i].ID;
			for (list<int>::iterator it = idList.begin(); it != idList.end(); ++it) {
				if (*it == needRemove) {
					if (it != idList.begin()) {
						auto temp = --it;
						it++;
						idList.erase(it);
						it = temp;
					}
					else {
						idList.erase(it);
						it = idList.begin();
					}
					break;
				}
				else {
					auto mapIt = IDToScore.find(*it);
					mapIt->second++;
				}
			}
		}
	}
	for (auto it : IDToScore) {
		result.push_back(make_pair(it.first, it.second));
	}
	sort(result.begin(), result.end(), comp());
	return result;
}


int main() {
	//BTNode* root = new BTNode(1);
	//BTNode* b = root->emplaceL(2);
	//BTNode* i = root->emplaceR(3);
	//BTNode* c = b->emplaceL(4);
	//BTNode* f = b->emplaceR(5);
	//BTNode* j = i->emplaceL(6);
	//BTNode* m = i->emplaceR(7);

	//BTNode *root = new BTNode(1);
	//root->left = new BTNode(3);
	//root->left->left = new BTNode(2);
	//root->left->right = new BTNode(1);
	//root->left->right->left = new BTNode(1);
	//root->right = new BTNode(-1);
	//root->right->left = new BTNode(4);
	//root->right->left->left = new BTNode(1);
	//root->right->left->right = new BTNode(2);
	//root->right->right = new BTNode(5);
	//root->right->right->right = new BTNode(2);
	//vector<vector<int>> results = findPath(root, 5);
	//for (auto vec : results) {
	//	for (int i : vec) {
	//		cout << i << " ";
	//	}
	//	cout << endl;
	//}

	Racer r1(2,100,200);
	Racer r2(3,110,190);
	Racer r3(4,105,145);
	Racer r4(1,90,150);
	Racer r5(5,102,198);
	vector<Racer> vec = {r1,r2,r3,r4,r5};
	CalculateScore(vec);

	string str = "100 200 300";
	stringstream ss(str);
	int a;
	int b;
	ss >> a;
	ss >> b;
	cout << b << endl;



	return 0;
}