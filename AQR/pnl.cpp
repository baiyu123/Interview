#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdint.h>
#include <sstream>
#include <unordered_map>
#include "util.h"
#include <thread>
#include <chrono>

using namespace std;

class manager{
public:
	manager(string fill, string price, string output){
		fillPath = fill;
		pricePath = price;
		outputPath = output;
	}
	void calculatePNL(){
		ifstream fillFile(fillPath);
		ifstream priceFile(pricePath);

		//first price data
		priceData currPrice = parsePrice(priceFile);
		uint64_t currTime = currPrice.timeStamp;
		bool endOfPrice = false;
		while(true){
			if(currPrice.timeStamp == currTime)
			priceMap[currPrice.name] = currPrice;
			uint64_t prevTime;
			while(true){
			 	currPrice = parsePrice(priceFile);

			 	//update the map elem until the time is different than the current time
			 	if(currPrice.timeStamp != currTime||priceFile.eof()){
			 		prevTime = currTime;
			 		currTime = currPrice.timeStamp;
			 		break;
			 	}
			 	//update map
			 	auto priceIt = priceMap.find(currPrice.name);
			 	if(priceIt != priceMap.end()){
			 		priceIt->second = currPrice;
			 	}
			 	else{
			 		priceMap[currPrice.name] = currPrice;
			 	}
			}
			priceData currPrice = parsePrice(priceFile);
			fillData currFill;
			//this_thread::sleep_for(chrono::seconds(1));
			bool updatePrice = false;
			while(!fillFile.eof()&&!updatePrice){
			 	currFill = parseFill(fillFile);
			 	if(currFill.timeStamp > prevTime){
			 		printPNL();
			 		updatePrice = true;
			 	}
			 	processFillRequest(currFill);
			}
			if(!updatePrice){
				printPNL();
			}
			if(endOfPrice) break;
			if(priceFile.eof()){
				endOfPrice = true;
			}
		}
		fillFile.close();
		priceFile.close();
	}

private:
	//fill data from the fills file's line
	struct fillData
	{
		uint64_t timeStamp;
		std::string name;
		double price;
		int fillSize;
		std::string action;
	};
	//price data from the prices files
	struct priceData
	{
		uint64_t timeStamp;
		std::string name;
		double price;	
	};


	fillData parseFill(ifstream& file){
		string line;
		fillData data;
		if(file.is_open()){
			if(! file.eof()){
				getline(file, line);
				if(line.size() == 0)return data;
				int index = 2;
				data.timeStamp = stringTouint64_t(delimit(index, ' ',line));
				data.name = delimit(++index, ' ', line);
				data.price = stod(delimit(++index, ' ', line));
				data.fillSize = stringTouint64_t(delimit(++index, ' ',line));
				data.action = delimit(++index, ' ', line);
			}
		}
		return data;
	}

	priceData parsePrice(ifstream& file){
		string line;
		priceData data;
		if(file.is_open()){
			if(!file.eof()){
				getline(file, line);
				if(line.size() == 0) return data;
				int index = 2;
				data.timeStamp = stringTouint64_t(delimit(index, ' ', line));
				data.name = delimit(++index, ' ', line);
				data.price = stod(delimit(++index, ' ', line));
				//cout <<"count " << file.gcount() << endl;
				//cout << data.timeStamp << " " << data.name << " " << data.price << endl;
			}
		}
		return data;
	}

	void printPNL(){
		for(auto elem : companysMap){
			auto it = priceMap.find(elem.second.getName());
			if(it != priceMap.end())
		 	cout << elem.second.calculatePNL(it->second.price) << endl;
		}
	}

	void processFillRequest(fillData currFill){
		auto it = companysMap.find(currFill.name);
	 	if(it == companysMap.end()){
	 		CompanyStock compTemp(currFill.name);
	 		if(currFill.action == "B"){
	 			compTemp.Buy(currFill.fillSize, currFill.price);
	 		}
	 		else{
	 			compTemp.Sell(currFill.fillSize, currFill.price);
	 		}
	 		companysMap[currFill.name] = compTemp;

	 	}
	 	else{
	 		if(currFill.action == "B"){
	 			it->second.Buy(currFill.fillSize, currFill.price);
	 		}
	 		else{
	 			it->second.Sell(currFill.fillSize, currFill.price);
	 		}
	 	}
	}

	unordered_map<string, CompanyStock> companysMap;
	unordered_map<string, priceData> priceMap;
	string fillPath;
	string pricePath;
	string outputPath;


};


int main(){
	manager mag("testFill", "testprice","output");
	mag.calculatePNL();
	return 0;
}