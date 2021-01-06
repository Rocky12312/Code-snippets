#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& v){
	stack<int> s;
	vector<int> res;
	for(int i=v.size()-1;i>=0;i--){
		if(s.empty() == true){
			res.push_back(-1);
		}
		else if(s.empty() == false && s.top() > v[i]){
			res.push_back(s.top());
		}
		else if(s.empty() == false && s.top() <= v[i]){
			while(s.empty() == false && s.top() <= v[i]){
				s.pop();
			}
			if(s.empty() == true){
				res.push_back(-1);
			}else{
				res.push_back(s.top());
			}
		}
		s.push(v[i]);
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	vector<int> v = {2,3,7,4,3,2,5,6};
	vector<int> res;
	res = solve(v);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
}