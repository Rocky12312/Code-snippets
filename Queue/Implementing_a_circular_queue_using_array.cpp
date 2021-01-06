#include<bits/stdc++.h>
using namespace std;
const int sz = 4;

struct cir_queue{
	int arr[sz];
	int front = -1;
	int rear = -1;
	void push(int n){
		if(rear+1 >= sz && front == 0){
			cout<<"Queue capacity full"<<endl;
		}
		else if(rear+1 >= sz){
			rear = 0;
			arr[rear] = n;
		}else if(rear+1 == front){
			cout<<"Queue full"<<endl;
		}else{
			if(front == -1){
				front = 0;
			}
			rear++;
			arr[rear] = n;
		}
		return;
	}
	void pop(){
		if(front == -1){
			cout<<"Queue is empty"<<endl;
		}
		else if(front == rear){
			front = -1;
			rear = -1;
		}
		else if(front < rear){
			front++;
		}
		return;
	}
	void front_elem(){
		if(front == -1){
			cout<<"No element in queue"<<endl;
			return;
		}
		cout<<arr[front]<<endl;
		return;
	}
	void is_empty(){
		if(front == -1){
			cout<<"Queue is empty"<<endl;
			return;
		}
		cout<<"Queue is not empty"<<endl;
		return;
	}
};

int main(){
	cir_queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.pop();
	q.pop();
	q.push(5);
	q.push(6);
	q.push(7);
	q.front_elem();
	q.is_empty();
}