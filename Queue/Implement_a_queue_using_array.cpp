#include<bits/stdc++.h>
using namespace std;
const int size = 3;

struct Queue{
	int arr[size];
	int front = -1;
	int rear = -1;
	void push(int n){
		if(rear >= n){
			cout<<"Queue capacity full"<<endl;
			return;
		}else{
			if(front == -1){
				front = 0;
			}
			rear++;
			arr[rear] = n;
		}
		return;
	}
	void front_elem(){
		if(front == -1){
			cout<<"No element in queue"<<endl;
		}else{
			cout<<arr[front]<<endl;
		}
		return;
	}
	void pop(){
		if(front == -1){
			cout<<"No element in queue to pop"<<endl;
			return;
		}else{
			front++;
		}
	}
	void is_empty(){
		if(front == -1 || front > rear){
			cout<<"Queue is empty"<<endl;
		}else{
			cout<<"Queue not empty"<<endl;
		}
		return;
	}
};

int main(){
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.front_elem();
	q.pop();
	q.front_elem();
	q.is_empty();
}