#include<bits/stdc++.h>
using namespace std;

void solve(vector <int> &v,int n,int k){
	int ax[n+1][k+1];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<k+1;j++){
			if(i == 0){
				ax[i][j] = false;
			}
			if(j == 0){
				ax[i][j] = true;
			}
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<k+1;j++){
			if(v[i-1]<=j){
				ax[i][j] = ax[i-1][j-v[i-1]] || ax[i-1][j];
			}
			else{
				ax[i][j] = ax[i-1][j];
			}
		}
	}
	if(ax[n][k] == true){
		cout<<"hurray"<<endl;
	}
}

int main(){
	vector<int> v = {1,2,3,4,5};
	int k;
	int n = 5;
	cout<<"Sum to be found"<<endl;
	cin>>k;
	solve(v,n,k);
}

