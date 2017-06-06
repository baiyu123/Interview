#include <iostream>
#include <vector>

using namespace std;

struct node{
	int value;
	node* left == NULL;
	node* right == NULL;
};

void helper(node* currNode, int depth, vector<vector<int>>& result){
	if(currNode == NULL){
    return;
	}
	else{
		if(result.size() < depth+1){
			vector<int> temp;
			temp.push_back(currNode->value);
			resutl.push_back(temp);
		}
		else{
			result[depth].push_back(currNode->value);
		}
		helper(currNode->left, depth+1, result);
		helper(currNode->right, depth+1, result);
	}
}

vector<vector<int>> getList(node* root){
	vector<vector<int>> result;
	helper(root,0, result);
  return result;
}

int main(){
	node* root;
	vector<vector<int>> result = getList(root);
}