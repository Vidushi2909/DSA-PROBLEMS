#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int fact(int n){
    if(n==1){
        return 1;
    }
    return (n*fact(n-1));
}
int main(){
    int num=5;
    cout<<fact(num);
}