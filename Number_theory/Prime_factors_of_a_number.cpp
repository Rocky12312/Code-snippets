#include<bits/stdc++.h>
using namespace std;

void solve(int a){
    while(a%2 == 0){
        cout<<2<<" ";
        a = a/2;
    }
    for(int i=3;i<=sqrt(a);i+=2){
        if(a%i == 0){
            cout<<i<<" ";
            a = a/i;
        }
    }
    if(a > 2){
        cout<<a<<endl;
    }
}

int main(){
    int a = 32;
    solve(a);
    return 0;
}
