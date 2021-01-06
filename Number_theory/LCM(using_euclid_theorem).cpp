#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a,long long int b){
	while(b){
		a = a%b;
		swap(a,b);
	}
	return a;
}

long long int lcm(long long int a,long long int b){
	return (a/gcd(a,b))*b;
}

int main(){
	int a = 20;
	int b = 28;
	long long int res = lcm(a,b);
	cout<<"LCM of the numbers are "<<res<<endl;
}
