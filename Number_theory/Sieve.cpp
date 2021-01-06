#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define ll long long 

vector<ll> solve(int num){
	vector<ll> res(num,0);
	for(ll i=3;i<num;i=i+2){
		if(i&1){
			res[i] = 1;
		}
	}
	for(ll i=3;i<=sqrt(num);i=i+2){
		if(res[i] == 1){
			for(ll j=i*i;j<num;j=j+i){
				res[j] = 0;
			}
		}
	}
	res[2] = 1;
	return res;
}

int main(){
	ll num;
	cin>>num;
	vector<ll> v = solve(num);
	for(ll i=0;i<v.size();i++){
		if(v[i] == 1){
			cout<<i<<endl;
		}
	}
	return 0;
}