#include<bits/stdc++.h>
using namespace std;

void permute(int k,string s,string& comb,vector<bool>& visited){
	if(k == s.size()){
		cout<<comb<<endl;
		return;
	}else{
		for(int i=0;i<s.size();i++){
			if(visited[i] == false){
				comb.push_back(s[i]);
				visited[i] = true;
				permute(k+1,s,comb,visited);
				visited[i] = false;
				comb.pop_back();
			}
		}
	}
}

int main(){
	string s = "abcd";
	string comb;
	vector<bool> v(s.size(),false);
	permute(0,s,comb,v);
}