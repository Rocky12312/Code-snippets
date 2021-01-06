#include<bits/stdc++.h>
using namespace std;

int solve(int n){
	vector<int> cns(n+1,0);
	cns[0] = 1;
	cns[1] = 1;
	for(int i=2;i<=n;i++){
		cns[i] = 0;
		for(int j=0;j<i;j++){
			cns[i] += cns[j]*cns[i-j-1];
		}
	}
	return cns[n];
}

int main(){
	int n;
	cin>>n;
	int res = solve(n);
	cout<<res<<endl;
}
