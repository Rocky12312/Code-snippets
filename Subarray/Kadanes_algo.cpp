#include<bits/stdc++.h>
using namespace std;

//Handle both positive and negative
int solvepn(vector<int>& v){
	int sz = v.size();
	int max_till_here = v[0];
	int max_so_far = v[0];
	for(int i=1;i<sz;i++){
		max_till_here = max(max_till_here+v[i],v[i]);
		max_so_far = max(max_so_far,max_till_here);
	}
	return max_so_far;
}

//Handles only positive
int solvep(vector<int>& v){
	int sz = v.size();
	int max_till_here = 0;
	int max_so_far = 0;
	for(int i=0;i<sz;i++){
		max_till_here = max_till_here+v[i];
		if(max_till_here < 0){
			max_till_here = 0;
		}
		max_so_far = max(max_so_far,max_till_here);
	}
	return max_so_far;
}

int main(){
	vector<int> v = {1,2,3,4,-1,-2,3,-4};
	int res = solvep(v);
	cout<<res<<endl;
	return 0;
}
