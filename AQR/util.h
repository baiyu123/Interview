#pragma once
#include <string>
#include <sstream>
#include <iostream>



//keep track of spending and profit from each symbol
class CompanyStock{
public:
	std::string symbol = "";
	double investment;
	int fillOwned;
public:
	CompanyStock(){
		symbol = "";
		investment = 0;
		fillOwned = 0;
	}

	CompanyStock(std::string name){
		symbol = name;
		investment = 0;
		fillOwned = 0;
	}
	std::string getName(){
		return symbol;
	}
	void Buy(int fillSize, double price){
		investment += fillSize*price;
		fillOwned += fillSize;
	}
	void Sell(int fillSize, double price){
		investment -= fillSize*price;
		fillOwned -= fillSize;
	}
	double calculatePNL(double currPrice){
		return ((currPrice*fillOwned)-investment);
	}
};

std::string delimit(int& start, char delimiter, std::string str){
	std::string result = "";
	for(int i = start; i < str.size(); i++){
		if(str[i] != delimiter){
			result+=str[i];
		}
		else{
			start = i;
			break;
		}
	}
	return result;
}

uint64_t stringTouint64_t(std::string str){
	uint64_t value;
	std::istringstream iss(str);
	iss >> value;
	return value;
}