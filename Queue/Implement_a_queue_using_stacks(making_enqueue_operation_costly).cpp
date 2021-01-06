#include<bits/stdc++.h>
using namespace std;

struct Queue{//Making enqueue operation costly
	stack<int> a;
	stack<int> b;
	void enqueue(int n){
		while(a.empty() == false){
			b.push(a.top());
			a.pop();
		}
		a.push(n);
		while(b.empty() == false){
			a.push(b.top());
			b.pop();
		}
	}
	int dequeue(){//Showing deququed values
		if(a.empty() == true){
			cout<<"Queue is empty"<<endl;
			return INT_MIN;
		}else{
			int top_val = a.top();
			a.pop();
			return top_val;
		}
		return 0;
	}
};

int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	int val = q.dequeue();
	if(val == INT_MIN){

	}else{
		cout<<val<<endl;
	}
	return 0;
}