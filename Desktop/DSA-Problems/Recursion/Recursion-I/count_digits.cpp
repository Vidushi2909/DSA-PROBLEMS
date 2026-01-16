#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int count_digits(int original, int n, int count){
    if(n==0)return count;
    int digit=original%10;
    if(digit!=0 && original%digit==0){
        return count_digits(original,n/10,count+1);
    }
    else{
        return count_digits(original,n/10,count);
    }
}
int main(){
    int n=124;
    cout<<count_digits(n,n,0)<<"\n";
}