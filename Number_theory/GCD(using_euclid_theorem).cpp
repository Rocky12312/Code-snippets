#include<bits/stdc++.h>
using namespace std;

//Recursive
long long int gcd_r(long long int a,long long int b){
	if(b == 0){
		return a;
	}
	return gcd_r(b,a%b);
}

//Iterative
long long int gcd_i(long long int a,long long int b){
	while(b){
		a = a%b;
		swap(a,b);
	}
	return a;
}

int main(){
	int a = 20;
	int b = 28;
	long long int res = gcd_i(a,b);
	cout<<"GCD of the numbers are "<<res<<endl;
}