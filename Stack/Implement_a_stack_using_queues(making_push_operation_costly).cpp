#include<bits/stdc++.h>
using namespace std;

struct Stack{//Making push operation costly
	queue<int> a;
	queue<int> b;
	void push(int val){
		b.push(val);
		while(a.empty() == false){
			b.push(a.front());
			a.pop();
		}
		queue<int> q = a;
		a = b;
		b = q;
	}
	void pop(){
		if(a.empty() == true){
			cout<<"Stack is empty"<<endl;
			return;
		}
		a.pop();
		return;
	}
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	int top_val = s.pop();
	cout<<top_val<<endl;
}