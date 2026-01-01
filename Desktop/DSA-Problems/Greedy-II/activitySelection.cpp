#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int activitySelection(vector<int>&s, vector<int>&f){
    int n=s.size();
    vector<pair<int,int>>activities;
    for(int i=0;i<n;i++){
        activities.push_back({f[i],s[i]});
    }
    sort(activities.begin(),activities.end());
    int count=1;
    int lf=activities[0].first;
    for(int i=1;i<n;i++){
        if(activities[i].second>=lf){
            count++;
            lf=activities[i].first;
        }
    }
    return count;
}
int main(){
    vector<int>s={1, 3, 2, 5};
    vector<int>f={2, 4, 3, 6};
    cout<<activitySelection(s,f)<<"\n";
}