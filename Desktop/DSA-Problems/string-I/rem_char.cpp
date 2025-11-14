#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string remove_char(string a){
    string ans="";
    for(int i=0;i<a.length();i++){
        if(tolower(a[i])>='a' && tolower(a[i])<='z'){
            ans.push_back(a[i]);
        } 
    }
    return ans;
}
int main(){
     string str="take12% *&u ^$#forward";
    cout<<remove_char(str)<<"\n";
}