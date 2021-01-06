#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr){
	int res = INT_MIN;
	vector<int> lis(arr.size(),1);
	for(int i=1;i<lis.size();i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && lis[j]+1>lis[i]){
				lis[i] = lis[j]+1;
			}
		}
	}
	for(int i=0;i<lis.size();i++){
		res = max(res,lis[i]);
	}
	return res;
}

int main(){
	vector<int> arr = {1,1,1,1,1,1,1,2,2,2,2,3,3,3,4,4,4,4,4,5};
	int res = solve(arr);
	cout<<res<<endl;
}