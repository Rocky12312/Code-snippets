#include<bits/stdc++.h>
using namespace std;

struct Stack{//Making push operation costly
	queue<int> a;
	queue<int> b;
	void push(int val){
		a.push(val);
	}
	void pop(){
		if(a.empty() == true){
			cout<<"Stack is empty"<<endl;
		}
		while(a.size()!=1){
			b.push(a.front());
			a.pop();
		}
		a.pop();
		queue<int> q = a;
		a = b;
		b = a;
	}
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.pop();
}