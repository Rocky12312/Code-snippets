#include<bits/stdc++.h>
using namespace std;

struct Queue{
	stack<int> a;
	void enqueue(int n){
		a.push(n);
	}
	int dequeue(){
		if(a.empty() == true){
			cout<<"Queue is empty"<<endl;
			return INT_MIN;
		}
		int x = a.top();
		a.pop();
		if(a.empty() == true){
			return x;
		}
		int val = dequeue();
		a.push(x);
		return val;
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