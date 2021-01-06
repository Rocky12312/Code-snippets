#include<bits/stdc++.h>
using namespace std;

struct d_linked_l{
	int data;
	d_linked_l* next;
	d_linked_l* prev;
	d_linked_l(){
		data = 0;
		next = NULL;
		prev = NULL;
	}
};

void insert_back(int n,d_linked_l** last){
	d_linked_l* temp = new d_linked_l();
	temp->data = n;
	temp->prev = *last;
	d_linked_l* tempx = temp->prev;
	tempx->next = temp;
	*last = temp;
	//If not using back pointer
	/*if(root->next == NULL){
		root->next = new d_linked_l();
		root->next->data = n;
		root->next->prev = root;
		*last = root->next;
	}else{
		d_linked_l* temp = root;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = new d_linked_l();
		temp->next->data = n;
		temp->next->prev = temp;
		*last = temp->next;

	}*/
	return;
}

void insert_front(d_linked_l* root,int n){
	if(root != NULL){
		d_linked_l* temp = new d_linked_l();
	    temp->data = n;
	    temp->next = root;
	    root->prev = temp;
	    root = temp;
	}else{
		root = new d_linked_l();
		root->data = n;
	}
	return;
}

void insert_pos(d_linked_l* root,int n,int pos){
	if(root != NULL){
		d_linked_l* temp = root;
	    int idx = 1;
	    while(idx+1 != pos && temp->next){
	    	temp = temp->next;
		    idx++;
		}
	    d_linked_l* temp1 = temp->next;
	    temp->next = new d_linked_l();
	    temp->next->data = n;
	    temp->next->prev = temp;
	    temp->next->next = temp1;
	    temp1->prev = temp->next;
	}else{
		root = new d_linked_l();
		root->data = n;
	}
	return;
}

void iterating_dll(d_linked_l* root){
	if(root != NULL){
		d_linked_l* temp = root;
	    while(temp){
	    	cout<<temp->data<<endl;
		    temp = temp->next;
		}
	}else{
		cout<<"The list is empty"<<endl;
	}
	return;
}

void delete_back(d_linked_l* root,d_linked_l** last){
	if(root!=NULL){
		d_linked_l* temp = *last;
	    d_linked_l* tempx = temp->prev;
	    tempx->next = NULL;
	    temp->prev = NULL;
	    delete(temp);
	}else{
		return;
	}
	return;
}

void delete_front(d_linked_l* root){
	if(root == NULL){
		return;
	}else{
		d_linked_l* temp = root;
		d_linked_l* tempx = temp->next;
		tempx->prev = NULL;
		temp->next = NULL;
		root = tempx;
		delete(temp);
	}
	return;
}

void delete_pos(d_linked_l* root,int pos){
	if(root == NULL){
		return;
	}else{
		d_linked_l* temp = root;
		int idx = 1;
		while(idx != pos && temp->next){
			temp = temp->next;
			idx++;
		}
		d_linked_l* tempx = temp->prev;
		tempx->next = temp->next;
		temp->next->prev = tempx;
		delete(temp);
	}
	return;
}



int main(){
	d_linked_l* root = new d_linked_l();
	root->data = 1;
	d_linked_l* last = root;//For last node address
	insert_back(2,&last);
	insert_back(4,&last);
	insert_back(5,&last);
	insert_pos(root,3,3);
	//delete_back(root,&last);
	delete_pos(root,2);
	iterating_dll(root);
	return 0;
}