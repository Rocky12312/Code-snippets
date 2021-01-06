#include<iostream>
using namespace std;

void swap(int*a,int*b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int*arr,int low,int high){
	int pivot = arr[high];
	int i = low-1;
	for(int j=low;j<high;j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}

void quick_sort(int*arr,int low,int high){
	if(low < high){
		int partn = partition(arr,low,high);
		quick_sort(arr,low,partn-1);
		quick_sort(arr,partn+1,high);
	}
	return;
}

void print_array(int*arr,int arr_sz){
	for(int i=0;i<arr_sz;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return;
}

int main(){
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int arr_sz = sizeof(arr)/sizeof(arr[0]);//or use n for size
	print_array(arr,arr_sz);
	quick_sort(arr,0,arr_sz);
	print_array(arr,arr_sz);
	return 0;
}
