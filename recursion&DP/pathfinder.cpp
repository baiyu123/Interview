#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;
class pathFinder{
public:
	pathFinder(string fileLoc){
		parseFile(fileLoc);
		vector<char> temp;
		unordered_set<char> visited;
		recursivePath(temp, start, visited);
		for(int i = 0; i < allPaths.size(); i++){
			for(int j = 0; j < allPaths[i].size(); j++){
				cout << allPaths[i][j];
			}
			cout << endl;
		}
	}
private:
	char start;
	char end;
	vector<vector<char> > allPaths;
	unordered_map<char, vector<char> > nodesMap;
	void recursivePath(vector<char> v, char currNode, unordered_set<char> visited){
		if(currNode == end){
			v.push_back(currNode);
			allPaths.push_back(v);
			return;
		}
		else{
			visited.emplace(currNode);
			v.push_back(currNode);
			auto it = nodesMap.find(currNode);
			if(it != nodesMap.end()){
				vector<char> temp = it->second;
				for(int i =0; i < temp.size(); i++){
					if(visited.find(temp[i])==visited.end())
					recursivePath(v,temp[i],visited);
				}
			}
		}
	}
	void parseFile(string fileLoc){
		ifstream myfile;
		myfile.open(fileLoc);
		string line;
		getline(myfile, line);

		start = line[0];
		end = line[2];
		while(!myfile.eof()){
      		getline (myfile,line);
			processLine(line);
		}
		myfile.close();
	}
	void processLine(string line){
		char firstNode = line[0];
		vector<char> v;
		for(int i = 1; i < line.size(); i++){
			if(line[i] != ':' && line[i] != ' '){
				v.push_back(line[i]);
			}
		}
		nodesMap[firstNode] = v;
	}
};

int main(){
	pathFinder finder("input_1.txt");
	return 0;
}

