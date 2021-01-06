#include<iostream>
#include<vector>
using namespace std;
#define ll long long

ll solve(ll a,ll b,ll mod_val){
	ll res = 1;
	while(b > 0){
		if(b&1){
			res = (res*a)%mod_val;
		}
		a = (a*a)%mod_val;
		b = b>>1;
	}
	return res;
}

int main(){
	ll a;
	cin>>a;
	ll b;
	cin>>b;
	ll mod_val;
	cin>>mod_val;
	ll res = solve(a,b,mod_val);
	cout<<res<<endl;
}
