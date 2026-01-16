#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void combinations(vector<int>&comb, vector<vector<int>>&ans, int n, int k, int start){
    if(comb.size()==k){
        ans.push_back(comb);
        return;
    }
    if(n-start+1 <k-comb.size()) return;
    for(int i=start;i<=n;i++){
        comb.push_back(i);
        combinations(comb,ans,n,k,i+1);
        comb.pop_back();
    }

}
int main(){
    int n=1,k=1;
    vector<int>comb;
    vector<vector<int>>ans;
    combinations(comb,ans,n,k,1);
    for(vector<int>part:ans){
        cout<<"[";
        for(int val:part){
            cout<<val;
        }
        cout<<"]";
        cout<<"\n";
    }
}