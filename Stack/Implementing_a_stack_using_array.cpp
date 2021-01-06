#include<bits/stdc++.h>
using namespace std;
const int size = 100;

struct Stack{
	int arr[size];
	int size_fill = 0;
	void push(int n){
		if(size_fill >= size){
			cout<<"Capacity exceeded"<<endl;
			return;
		}
		arr[size_fill] = n;
		size_fill++;
	}
	void top(){
		if(size_fill <= 0){
			cout<<"Stack contain no element"<<endl;
			return;
		}
		cout<<arr[size_fill-1]<<endl;
	}
	void pop(){
		if(size_fill == 0){
			cout<<"Stack is empty"<<endl;
			return;
		}
		size_fill--;
	}
	void is_empty(){
		if(size_fill <= 0){
			cout<<"Stack is empty"<<endl;
		}
		return;
	}
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.top();
	s.is_empty();
}