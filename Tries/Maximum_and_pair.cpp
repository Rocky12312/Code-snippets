//Just an experiment(problem resolving)
#include<bits/stdc++.h>
using namespace std;

struct trie_node{
	trie_node* left;
	trie_node* right;
};

trie_node* create_trie_node(){
	trie_node* p = new trie_node;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void populating_trie(vector<int>& v,trie_node* root){
	for(int i=0;i<v.size();i++){
		trie_node* temp = root;
		int val = v[i];
		for(int j=31;j>=0;j--){
			int bit_val = (val>>j)&1;
			if(bit_val == 0){
				if(!temp->left){
					temp->left = create_trie_node();
				}
				temp = temp->left;
			}else{
				if(!temp->right){
					temp->right = create_trie_node();
				}
				temp = temp->right;
			}
		}
	}
}

int max_and_pair(vector<int>& v,trie_node* root){
	int max_value = INT_MIN;
	for(int i=0;i<v.size();i++){
		trie_node* temp = root;
		int pair_val = 0;
		int val = v[i];
		for(int j=31;j>=0;j--){
			int bit_val = (v[i]>>j)&1;
			if(bit_val == 1){
				if(temp->right){
					pair_val = pair_val+pow(2,j);
					temp = temp->right;
				}else{
					temp = temp->left;
				}
			}else{
				//Have to think of something else
				if(temp->left){
					temp = temp->left;
				}else{
					temp = temp->right;
				}
			}
		}
		if(pair_val > max_value){
			max_value = pair_val;
		}
	}
	return max_value;
}

int main(){
	vector<int> v = {1,2,3};
	trie_node* root = create_trie_node();
	populating_trie(v,root);
	int res = 0;
	res = max_and_pair(v,root);
	cout<<"The maximum and pair has and pair value of: "<<res<<endl;
	return 0;
}