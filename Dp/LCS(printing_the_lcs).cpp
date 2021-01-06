#include<bits/stdc++.h>
using namespace std;
//Longest common substring
void solve(string a,string b,int c,int d){
	int ax[c+1][d+1];
	cout<<a<<endl;
	cout<<b<<endl;
	for(int i=0;i<c+1;i++){
		for(int j=0;j<d+1;j++){
			if(i==0 || j==0){
				ax[i][j] = 0;
			}
		}
	}
	for(int i=1;i<c+1;i++){
		for(int j=1;j<d+1;j++){
			if(a[i-1] == b[j-1]){
				ax[i][j] = 1 + ax[i-1][j-1];
			}else{
				ax[i][j] = 0;
			}
		}
	}
	int max = INT_MIN;
	for(int i=0;i<c+1;i++){
		for(int j=0;j<d+1;j++){
			if(ax[i][j]>max){
				max = ax[i][j];
			}
		}
	}
	cout<<max;
	//return ax[c][d];
}

int main(){
	string a = "abcdpolabcdefl";
	string b = "abcdefgh";
	solve(a,b,a.length(),b.length());
}
