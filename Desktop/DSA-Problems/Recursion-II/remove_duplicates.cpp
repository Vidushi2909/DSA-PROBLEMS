#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int>remove_dup(vector<int>& vec){
    unordered_map<int,int>m;
    vector<int>ans;
    for(int i=0;i<vec.size();i++){
        if(m.find(vec[i])==m.end()){
            ans.push_back(vec[i]);
            m[vec[i]]++;
        }
    }
    return ans;
}

int main(){
    vector<int>vec={4,3,6,2,7,4,5,6,7,3,2,1};
    vector<int>ans=remove_dup(vec);
    for(int val:ans){
        cout<<val<<"";
    }
    cout<<"\n";
}