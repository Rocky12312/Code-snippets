#include<iostream>
#include<vector>
using namespace std;
#define ll long long

vector<ll> solve(ll num){
	vector<ll> res(num+1,-1);
	for(ll i=2;i<num+1;i++){
		if(res[i] == -1){
			res[i] = i;
			for(ll j=i*i;j<num+1;j=j+i){
				res[j] = i;
			}
		}
	}
	vector<ll> op;
	ll pos = num;
	while(pos!=-1){
		op.push_back(res[pos]);
		pos = pos/res[pos];
	}
	op.pop_back();
	return op;
}

int main(){
	ll num;
	cin>>num;
	vector<ll> res = solve(num);
	ll sz = res.size();
	for(ll i=0;i<sz;i++){
		cout<<res[i]<<endl;
	}
	return 0;
}