#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& v,int k){
	int i=0,j=0;
	int res = 0;
	int sum = 0;
	sort(v.begin(),v.end());
	while(j<v.size()){
		sum = sum+v[j];
		if(sum == k){
			res = max(res,j-i+1);
			j++;
		}
		else if(sum < k){
			j++;
		}
		else if(sum > k){
			while(sum > k){
				sum = sum-v[i];
				i++;
				if(sum == k){
					res = max(res,j-i+1);
				}
			}
			if(sum == k){
				res = max(res,j-i+1);
			}
			j++;
		}
	}
	return res;
}

int main(){
	vector<int> v = {5,2,1,-7};
	int k = -6;
	int res;
	res = solve(v,k);
	cout<<res<<endl;
}