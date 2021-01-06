#include<iostream>
using namespace std;

void swap(int*a,int*b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int*arr,int arr_sz){
	bool swapped;
	for(int i=0;i<arr_sz-1;i++){
		swapped = false;
		for(int j=0;j<arr_sz-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				swapped = true;
			}
		}
		if(swapped == false){
			return;
		}
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
	bubble_sort(arr,arr_sz);
	print_array(arr,arr_sz);
	return 0;
}
