#include<bits/stdc++.h>
using namespace std;

void maximum_product_subarray(int *arr,int n){
	int max_ending_here = 1;
	int min_ending_here = 1;
	int max_so_far = 1;
	for(int i=0;i<n;i++){
		if(arr[i]>0){
			max_ending_here = max_ending_here*arr[i];
			min_ending_here = min(min_ending_here*arr[i],1);
		}
		else if(arr[i] == 0){
			max_ending_here = 1;
			min_ending_here = 1;
		}
		else{
			int temp = max_ending_here;
			max_ending_here = max(min_ending_here*arr[i],1);
			min_ending_here = temp;
		}
		if(max_so_far<max_ending_here){
			max_so_far = max_ending_here;
		}
	}
	cout<<max_so_far<<endl;
}
int main(){
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	maximum_product_subarray(arr,n);
}
