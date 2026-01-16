#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int superEggDrop(int k, int n) {
         vector<long long> dp(k + 1, 0);
        int moves = 0;

        while (dp[k] < n) {
            moves++;
            for (int e = k; e >= 1; e--) {
                dp[e] = dp[e] + dp[e - 1] + 1;
            }
        }
        return moves;
}
int main(){
 int k=1;
 int n=2;
 cout<<superEggDrop(k,n)<<"\n";
}