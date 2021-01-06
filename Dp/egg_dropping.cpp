#include<bits/stdc++.h>
using namespace std;

int solve(int eggs,int floor){
	if(floor == 0 || floor == 1){
		return floor;
	}
	if(eggs == 1){
		return floor;
	}
	int minimum = INT_MAX;
	for(int k=1;k<=floor;k++){
		int temp = 1+max(solve(eggs-1,k-1),solve(eggs,floor-k));
		minimum = min(minimum,temp);
	}
	return minimum;
}

int main(){
	int eggs = 30;
	int floor = 40;
	int min = solve(eggs,floor);
	cout<<min<<endl;
}
