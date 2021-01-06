#include<bits/stdc++.h>
using namespace std;

struct trienode{
	trienode* child[26];
	bool wordend;
};

trienode* create_newnode(){
	trienode*temp = new trienode;
	temp->wordend = false;
	for(int i=0;i<26;i++){
		temp->child[i] = NULL;
	}
	return temp;
}

void populating_trie(trienode*root,string s){
	trienode*tempx = root;
	for(int j=0;j<s.length();j++){
		int idx = s[j]-'a';
		if(!tempx->child[idx]){
			tempx->child[idx] = create_newnode();
		}
		tempx = tempx->child[idx];
	}
	tempx->wordend = true;
}

bool search(trienode*root,string s){
	trienode*tempy = root;
	for(int j=0;j<s.length();j++){
		int idx = s[j]-'a';
		if(!tempy->child[idx]){
			return false;
		}
		tempy = tempy->child[idx];
	}
	if(tempy->wordend){
		return true;
	}
	return false;
}

bool solve(vector<string> &v,string s){
	trienode* root = create_newnode();
	for(int i=0;i<v.size();i++){
		populating_trie(root,v[i]);
	}
	bool op = search(root,s);
	return op;
}

int main(){
	vector<string> v = {"sourabh","soura","sour"};
	string search = "sou";
	bool op = solve(v,search);
	if(op == true){
		cout<<"Yes string you are searching is present"<<endl;
	}else{
		cout<<"No string present in the words list which you are searching"<<endl;
	}
	return 0;
}
