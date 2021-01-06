#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}

int partition(int *arr,int l,int h){
	int pivot = arr[l];
	int i=l;
	int j=h;
	do{
		do{i++;}while(arr[i]<=pivot);
		do{j--;}while(arr[j]>pivot);
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}while(i<j);
	swap(&arr[l],&arr[j]);
	return j;
}

void quick_sort(int*arr,int l,int h){
	int j;
	if(l<h){
		j = partition(arr,l,h);
		quick_sort(arr,l,j);
		quick_sort(arr,j+1,h);
	}
}

int main(){
	int n;
	cout<<"enter size of array"<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int l = 0;
	int h = n;
	quick_sort(arr,l,h);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}
