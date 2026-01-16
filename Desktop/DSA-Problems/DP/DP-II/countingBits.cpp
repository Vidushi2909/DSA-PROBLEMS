#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> countBits(int n) {
        vector<int>dp;
        for(int i=0;i<=n;i++){
            int x=i;
            int set=0;
            while(x>0){
                if(x&1==1){
                    set++;
                }
                x=x>>1;
            }
            dp.push_back(set);
        }
    return dp;
}

int main(){
    int n=5;
    vector<int>ans=countBits(n);
    for(int val:ans){
        cout<<val<<" ";
    }
    cout<<"\n";
}