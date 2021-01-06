#include<bits/stdc++.h>
using namespace std;
vector<string> all_prefix_strings;

struct trienode{
	trienode* child[26];
	int wordcount;
};

trienode* create_newnode(){
	trienode*temp = new trienode;
	temp->wordcount = 0;
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
	tempx->wordcount++;
}

bool is_leafnode(trienode*temp){
	for(int x=0;x<26;x++){
		if(temp->child[x]){
			return false;
		}
	}
	return true;
}

void generating_strings_having_prefix(trienode*tempy,string prefix){
	if(tempy->wordcount > 0){
		all_prefix_strings.push_back(prefix);
	}
	if(is_leafnode(tempy)){
		return;
	}
	for(int j=0;j<26;j++){
		if(tempy->child[j]){
			prefix.push_back(j+'a');
			generating_strings_having_prefix(tempy->child[j],prefix);
		}
	}
}


void generating_words(trienode*root,string s){
	trienode*tempy = root;
	for(int j=0;j<s.length();j++){
		int idx = s[j]-'a';
		if(!tempy->child[idx]){
			cout<<"No word with this prefix"<<endl;
			return;
		}
		tempy = tempy->child[idx];
	}
	bool is_not_prefix = false;//Checking whether the given prefix is a word or just a prefix
	if(tempy->wordcount > 0){
		is_not_prefix = true;
	}
	bool leafnode = is_leafnode(tempy);//Checking whether the it is leaf node of not
	if(is_not_prefix && leafnode){
		all_prefix_strings.push_back(s);
	}
	if(!leafnode){
		string curr_prefix = s;
		generating_strings_having_prefix(tempy,curr_prefix);
	}
}

void solve(vector<string> &v,string s){
	trienode* root = create_newnode();
	for(int i=0;i<v.size();i++){
		populating_trie(root,v[i]);
	}
	generating_words(root,s);
}

int main(){
	vector<string> v = {"sourabh","soura","sour"};
	string search = "soura";
	solve(v,search);
	for(int i=0;i<all_prefix_strings.size();i++){
		cout<<all_prefix_strings[i]<<endl;
	}
	return 0;
}
