#include<bits/stdc++.h>
using namespace std;

void solve(int* a){
	//a = a+20;
	*a = *a+20;
	cout<<*a<<endl;
}


int main(){
	int a = 20;
	solve(&a);
	cout<<a<<endl;
}