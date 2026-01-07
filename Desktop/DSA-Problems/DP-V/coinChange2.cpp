#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<unsigned long long>dp(amount+1,0);
    dp[0]=1;
    for(int coin:coins){
    for(int i=1;i<=amount;i++){
            if(i-coin>=0){
                dp[i]+=dp[i-coin];
            }
        }
    }
   return (int)dp[amount];
    }

int main(){
    vector<int>coins={1,2,5};
    int amount=5;
    cout<<coinChange(coins,amount)<<"\n";
}