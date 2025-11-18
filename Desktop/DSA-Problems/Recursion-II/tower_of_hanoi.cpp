#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int toh(int n){
    return pow(2,n)-1;
}
int main(){
    cout<<toh(2)<<"\n";
}