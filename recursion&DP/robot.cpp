#include <iostream>
#include <vector>
#include "point.h"

using namespace std;

bool helper(vector<vector<bool> > &board, vector<Point>& path, int row, int col){
	if(col == board[0].size()-1&&row == board.size()-1){
		return true;
	}
	if(row >= board.size() || col >= board[0].size()){
		return false;
	}
	else if(!board[row][col]){
		return false;
	}
	else{
		bool succ = false;
		if(helper(board,path,row+1,col)){
			Point p(row,col);
			path.push_back(p);
			succ = true;
		}
		else if(helper(board,path,row,col+1)){
			Point p(row,col);
			path.push_back(p);
			succ = true;
		}
		return succ;
	}
}

vector<Point> getPath(vector<vector<bool> >board){
	vector<Point> path;
	Point currPos(0,0);
	helper(board,path,0,0);
	return path;
}

int main(){
	vector<vector<bool> > board;
	vector<bool> row  = {1,0,1,0,1};
	vector<bool> row2 = {1,1,0,1,1};
	vector<bool> row3 = {0,1,1,1,0};
	vector<bool> row4 = {0,0,0,1,1};
	board.push_back(row);
	board.push_back(row2);
	board.push_back(row3);
	board.push_back(row4);
	vector<Point> result = getPath(board);
	for(auto p : result){
		cout << p.x << p.y << endl;
	}
	return 0;
}