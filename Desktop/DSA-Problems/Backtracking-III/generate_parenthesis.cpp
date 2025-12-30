#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void generate(vector<string>&ans,string& part,int& n, int open, int close ){
        if(open==n && close==n){
            ans.push_back(part);
            return;
        }
        if(open<n){
            part.push_back('(');
            generate(ans,part,n,open+1,close);
            part.pop_back();
        }
        if(close<open){
            part.push_back(')');
            generate(ans,part,n,open,close+1);
            part.pop_back();
        }
    }
int main(){
    vector<string>ans;
    string part="";
    int n=3;
    generate(ans,part,n,0,0);
    for(string str:ans){
        cout<<str<<"\n";
    }
}