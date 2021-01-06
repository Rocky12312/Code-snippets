#include<bits/stdc++.h>
using namespace std;

int solve(int n,int sz,int p[]){
	int res = 0;
	for(int i=1;i<(1<<sz);i++){
		int num = i;
		int cnt_bit = __builtin_popcount(num);
		int temp = 1;
		int pos = 0;
		while(num > 0){
			if((num&1)){
				temp = temp*p[pos];
			}
			num = num>>1;
			pos++;
		}
		if((cnt_bit&1)){
			res = res+(n/temp);
		}else{
			res = res-(n/temp);
		}
	}
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sz;
		cin>>sz;
		int arr[sz] = {0};
		for(int i=0;i<sz;i++){
			cin>>arr[i];
		}
		int res = solve(n,sz,arr);
		cout<<res<<endl;
	}
}