#include <iostream>
#include <vector>

using namespace std;

vector<int> calculatePrimes(int n){
  vector<int> results;
  vector<bool> lookup(n+1,true);
  lookup[0] = false;
  lookup[1] = false;
  for(int i = 2; i <= n; i++){
    if(lookup[i]) results.push_back(i);
    for(int j = i*2; j < lookup.size(); j+=i){
      lookup[j] = false;
    }
  }
  return results;
}

int main(){
  vector<int> primes;
  primes = calculatePrimes(100000);
  for(auto prime : primes){
    cout << prime << endl;
  }
  return 0;
}