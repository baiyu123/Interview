#include <iostream>
#include <vector>

using namespace std;

int getMaxProfit(vector<int>& prices){
  int maxProfit = 0;
  int locmin = INT_MAX;
  for(auto price : prices){
    locmin = min(price, locmin);
    maxProfit = max(maxProfit, price-locmin);
  }
  return maxProfit;
}

int getMaxProfitTwo(vector<int>& prices){
  int maxProfit = 0;
  int minPrice = INT_MAX;
  vector<int> forward(prices.size());
  vector<int> backward(prices.size());
  for(int i = 0; i < prices.size(); i++){
    minPrice = min(prices[i], minPrice);
    maxProfit = max(maxProfit, prices[i] - minPrice);
    forward[i]=(maxProfit);
  }
  
  int maxPrice = INT_MIN;
  maxProfit = 0;
  for(int i = prices.size()-1; i >= 0; i--){
    maxPrice = max(maxPrice, prices[i]);
    maxProfit = max(maxProfit,maxPrice-prices[i]);
    backward[i] = maxProfit;
  }
  maxProfit = 0;
  for(int i = 0; i < forward.size(); i++){
    if(forward[i]+backward[i] > maxProfit) maxProfit = forward[i] + backward[i];
  }
  return maxProfit;
}

int main(){
  vector<int> prices = {310,315,275,295,260,270,290,230,255,250};
  cout << getMaxProfitTwo(prices) << endl;
  return 0;
}