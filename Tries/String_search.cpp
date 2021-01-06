#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
	TrieNode* child[26];
	int endofword;
    TrieNode()
    {
        for(int i=0;i<26;i++) 
        {
            child[i]=NULL;
        }
        endofword=0;
    }
   
};
void insert_string(TrieNode* root,string key){
	TrieNode* temp = root;
	for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(temp->child[index] == NULL){
        	temp->child[index] = new TrieNode();
        }
        temp=temp->child[index];
    }
    temp->endofword++;
}
bool find_string(TrieNode* root,string key){
	TrieNode*temp = root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(temp->child[index]==NULL){
            return false;
        }
        else{
            temp=temp->child[index];
        }
    }
    if(temp->endofword > 0){
        return true;
    }
    else{
        return false;
    }
}
    
int main() {
    TrieNode *root=new TrieNode();
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    for (int i = 0; i < n; i++){
    	insert_string(root, keys[i]); 
    }
    if(find_string(root, "any")){
    	cout<<"Yes"<<endl;
    }else{
    	cout<<"No"<<endl;
    }
    return 0; 

}