#include<bits/stdc++.h>
using namespace std;

struct trie_node{
	int wend;
	trie_node* child[26];
};

trie_node* creating_trie_node(){
	trie_node* p = new trie_node;
	p->wend = 0;
	for(int i=0;i<26;i++){
		p->child[i] = NULL;
	}
	return p;
}

void populating_the_trie(vector<string>& words,trie_node*root){
	for(int i=0;i<words.size();i++){
		trie_node* temp = root;
		for(int j=0;j<words[i].size();j++){
			int idx = words[i][j]-'a';
			if(!temp->child[idx]){
				temp->child[idx] = creating_trie_node();
			}
			temp = temp->child[idx];
		}
		temp->wend++;
	}
}

bool is_leafnode(trie_node*temp){
	trie_node*temp1 = temp;
	bool op = true;
	for(int k=0;k<26;k++){
		if(temp->child[k]){
			op = false;
			break;
		}
	}
	return op;
}

void generating_word_with_prefix(trie_node* temp,string curr_prefix,vector<string>& res){
	if(temp->wend > 0){
		res.push_back(curr_prefix);
	}
	if(is_leafnode(temp)){
		return;
	}
	for(int i=0;i<26;i++){
		if(temp->child[i]){
			curr_prefix.push_back(i+'a');
			generating_word_with_prefix(temp->child[i],curr_prefix,res);
		}
	}
}

vector<string> check_all_word_with_a_given_prefix(string s,trie_node*root){
	vector<string> res;
	trie_node*temp = root;
	for(int i=0;i<s.length();i++){
		int idx = s[i]-'a';
		if(!temp->child[idx]){
			cout<<"No string_with_given_prefix"<<endl;
		}else{
			temp = temp->child[idx];
		}
	}
	if(temp->wend!=0 && is_leafnode(temp)){
		res.push_back(s);
	}
	if(!is_leafnode(temp)){
		string curr_prefix = s;
		generating_word_with_prefix(temp,curr_prefix,res);
	}
	return res;
}


int main(){
	vector<string> v = {"sourabh","soara","sourab"};
	trie_node* root = creating_trie_node();
	populating_the_trie(v,root);
	string s = "sou";
	vector<string> res;
	res = check_all_word_with_a_given_prefix(s,root);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	return 0;
}