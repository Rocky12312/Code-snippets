#include<bits/stdc++.h>
using namespace std;

bool checking_palindromestring(string p){
	if(p.length() == 0 || p.length() == 1){
		return true;
	}
	int i=0;
	int j=p.length()-1;
	while(i<j){
		if(p[i] == p[j]){
			i++;
			j--;
		}else{
			return false;
		}
	}
	return true;
}

void solve(string ip,string op,unordered_map<string,int> &um){
	if(ip.length() == 0){
		return;
	}
	string op1 = op;
	string op2 = op;
	op1.push_back(ip[0]);
	ip.erase(ip.begin()+0);
	if(checking_palindromestring(op1) == true){
		if(um.find(op1)==um.end()){
			um[op1] = 1;
		}
	}
	if(checking_palindromestring(op2) == true){
		if(um.find(op2)==um.end()){
			um[op2] = 1;
		}
	}
	solve(ip,op1,um);
	solve(ip,op2,um);
	return;
}

int main(){
	string ip = "sourabh";
	string op = "";
	//vector<string> v;
	unordered_map<string, int> um;
	solve(ip,op,um);
	//solve(ip,op,v);
	for(auto i=um.begin();i!=um.end();i++){
		cout<<i->first<<endl;
	}
	cout<<um.size()<<endl;
}
