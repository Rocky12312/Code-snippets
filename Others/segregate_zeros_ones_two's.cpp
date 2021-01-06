#include<bits/stdc++.h>
using namespace std;

void swap(int& a,int& b){
	a = a^b;
	b = b^a;
	a = a^b;
}

void solve(vector<int>& v){
	int low=0;
	int high=v.size();
	int mid=0;
	while(mid < high){
		switch(v[mid]){
			case 0:
			swap(v[low],v[mid]);
			low++;
			mid++;
			break;

			case 1:
			mid++;
			break;

			case 2:
			swap(v[mid],v[high]);
			high--;
			break;
		}
	}
}

int main(){
	vector<int> v = {0,1,2,2,2,1,0,2,1,0,1};
	solve(v);
	int n = v.size();
	for(int i=0;i<n;i++){
		cout<<v[i]<<endl;
	}
	return 0;
}