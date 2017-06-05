#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int newVal){
		val = newVal;
		left = NULL;
		right = NULL;
	}
};

void helper(Node* curr, int depth, unordered_map<int,vector<int>>& map){
	if(curr==NULL) return;
	else{
		auto it = map.find(depth);
		if(it != map.end()){
			it->second.push_back(curr->val);
		}
		else{
			vector<int> temp;
			temp.push_back(curr->val);
			map[depth] = temp;
		}
		helper(curr->left, depth+1, map);
		helper(curr->right, depth+1, map);
	}
}

vector<vector<int>> getNodesWithDepth(Node* root){
	unordered_map<int,vector<int>> map;
	helper(root, 0, map);
	int depth = 0;
	vector<vector<int>> results;
	while(true){
		auto it = map.find(depth);
		if(it==map.end()) break;
		results.push_back(it->second);
		depth++;
	}
	return results;
}


int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->left->left = new Node(4);
	root->right = new Node(3);
	root->right->left = new Node(5);


	vector<vector<int>> results = getNodesWithDepth(root);
	for(int i = 0; i < results.size(); i++){
		for(int j = 0; j < results[i].size(); j++){
			cout << results[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}