#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int num_child(vector<int>&g, vector<int>&c){
    int m=g.size();
    int n=c.size();
    sort(g.begin(),g.end());
    sort(c.begin(),c.end());
    int i=0,j=0;
    int num=0;
    while(j<n){
        if(c[j]<=g[i]){
            num=num+1;
            i++;
        }
        j++;
    }
    return num;
}
int main(){
    vector<int>g={1,2,3};
    vector<int>c={1,1};
    cout<<num_child(g,c)<<"\n";
}