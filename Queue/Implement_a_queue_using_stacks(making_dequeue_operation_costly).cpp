#include<bits/stdc++.h>
using namespace std;

struct Queue{//Making Dequeue operation costly
	stack<int> a;
	stack<int> b;
	void enqueue(int n){
		a.push(n);
	}
	int dequeue(){
		if(a.empty() && b.empty()){
			cout<<"Queue is empty"<<endl;
			return INT_MIN;
		}
		if(b.empty() == true){
			while(a.empty() == false){
				b.push(a.top());
				a.pop();
			}
		}
		int top_val = b.top();
		b.pop();
		return top_val;
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