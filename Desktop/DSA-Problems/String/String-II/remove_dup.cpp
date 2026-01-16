#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


string remove_duplicates(string& str){
    bool arr[26]={false};
    string ans="";
    ans.reserve(str.length());
    for(char ch:str){
        if(!arr[ch-'a']){
            arr[ch-'a']=true;
            ans+=ch;
        }
    }
    return ans;
}
int main(){
    string str="apple";
    cout<<remove_duplicates(str)<<"\n";

}