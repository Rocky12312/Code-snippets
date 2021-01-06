#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr){
	int res = INT_MIN;
	vector<int> incs = arr;
	for(int i=1;i<incs.size();i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && incs[j]+arr[i]>incs[i]){
				incs[i] = incs[j]+arr[i];
			}
		}
	}
	for(int i=0;i<incs.size();i++){
		res = max(res,incs[i]);
	}
	return res;
}

int main(){
	vector<int> arr = {1,1,1,1,12,2,24,3,4,3,4,3,45,6,6,7};
	int res = solve(arr);
	cout<<res<<endl;
}