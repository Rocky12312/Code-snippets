#include<bits/stdc++.h>
using namespace std;

void swap(int& a,int& b){
	a = a^b;
	b = b^a;
	a = a^b;
}

void solve(vector<int>& v){
	int i=0;
	int j=v.size()-1;
	while(i < j){
		if(v[i] == 0){
			i++;
		}
		if(v[i] == 1){
			swap(v[i],v[j]);
			j--;
		}
	}
}

int main(){
	vector<int> v = {1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1};
	solve(v);
	int n = v.size();
	for(int i=0;i<n;i++){
		cout<<v[i]<<endl;
	}
	return 0;
}