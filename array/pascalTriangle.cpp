#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > CalculatePascal(int n){
	vector<vector<int> > result;
	for(int i = 0; i <= n; i++){
		vector<int> row;
		for(int k = 0; k < i; k++){
			if(k==0||k == i-1) row.push_back(1);
			else{
				row.push_back(result[i-1][k]+result[i-1][k-1]);
			}
		}
		result.push_back(row);
	}
	return result;
}

int main(){
	vector<vector<int>> result = CalculatePascal(50);
	for(auto elems : result){
		for(auto elem : elems){
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}