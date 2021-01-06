#include<bits/stdc++.h>
using namespace std;

bool is_palindrome(string s,int i,int j){
	while(i < j){
		if(s[i] != s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int solve(string s,int a,int b){
	if(a >= b){
		return 0;
	}
	if(is_palindrome(s,a,b)){
		return 0;
	}
	int res = INT_MAX;
	for(int k=a;k<=b-1;k++){
		int temp = 1+solve(s,a,k)+solve(s,k+1,b);
		res = min(res,temp);
	}
	return res;

}

int main(){
	string s = "nitin";
	int p = solve(s,0,s.length()-1);
	cout<<"Minimum number of cut needed to be made in string so that each substring will be palindrome is: "<<p<<endl;
}