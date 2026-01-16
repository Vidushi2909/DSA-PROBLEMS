#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


bool isAlphaNumeric(char c){
    if((c>='0' && c<='9') || (tolower(c)>='a' && tolower(c)<='z')){
        return true;
    }
    else{
        return false;
    }
}
bool isPalindrome(string str){
    int start=0,end=str.length()-1;
    while(start<end){
        if(!isAlphaNumeric(str[start])){
            start++;
            continue;
        }
        if(!isAlphaNumeric(str[end])){
            end--;
            continue;
        }
        if(tolower(str[start])!=tolower(str[end])){
            return false;
        }
        else{
        start++;
        end--;
        }
    }
    return true;
}
int main(){
    string str = "A man, a plan, a canal: Panama";
    if(isPalindrome(str)){
        cout<<"is palindrome"<<"\n";
    }
    else{
        cout<<"isn't palindrome"<<"\n";
    }
}