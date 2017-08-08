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
private:
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
				cout << line << endl;
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

public:
	void calculatePNL(string fillPath, string pricePath){
	ifstream fillFile(fillPath);
	ifstream priceFile(pricePath);

	//first price data
	priceData currPrice = parsePrice(priceFile);
	uint64_t currTime = currPrice.timeStamp;
	while(!priceFile.eof()){
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
		//cout << currPrice.price <<endl;
		fillData currFill;
		this_thread::sleep_for(chrono::seconds(1));
		bool updatePrice = false;
		while(!fillFile.eof()&&!updatePrice){
		 	currFill = parseFill(fillFile);
		 	//cout << currFill.price << endl;
		 	cout << "fillTime:" << currFill.timeStamp << " pricetime: " << prevTime << endl;
		 	if(currFill.timeStamp > prevTime){
		 		cout << "pnl1" << endl;
		 		printPNL();
		 		updatePrice = true;
		 	}
		 	processFillRequest(currFill);
		 	// for(auto elem : companysMap){
		 	// 	cout << "name: "<<elem.second.symbol << "investment: " << elem.second.investment << "fill own: " << elem.second.fillOwned << endl;
		 	// }
		}
		if(!updatePrice){
			cout << "pnl2" << endl;
			printPNL();
		}
	}
	fillFile.close();
	priceFile.close();
	}
};


int main(){
	manager mag;
	mag.calculatePNL("testFill", "testprice");
	return 0;
}