#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int maxProfit(vector<int>& prices) {
  int maxP = 0, bestBuy = prices[0];
  for(int val:prices){
    if(bestBuy < val){
      maxP = max(val-bestBuy, maxP);
    }
    bestBuy = min(bestBuy,val);
  }
  return maxP;
}

int main(){
  vector<int>prices={7,1,5,3,6,4};
  cout<<maxProfit(prices)<<"\n";
}