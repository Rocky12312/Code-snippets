#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a,long long int b,int& x,int& y,queue<pair<int,int>>&q) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    long long int d = gcd(b, a % b, x1, y1,q);
    x = y1;
    y = x1 - y1 * (a / b);
    q.push({x,y});
    return d;
}

int main(){
    int a = 289848484;
    int b = 202444949;
    int x;
    int y;
    queue<pair<int,int>> q;
    long long int res = gcd(a,b,x,y,q);
    cout<<"The gcd of the numbers a and b is "<<res<<endl;
    cout<<"Coefficients in form of a * x + b * y = res are "<<q.back().first<<" "<<q.back().second<<endl;
    return 0;
}

