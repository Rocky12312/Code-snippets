#include<iostream>
using namespace std;

void swap(int*a,int*b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selection_sort(int*arr,int arr_sz){
	int min_index;
	for(int i=0;i<arr_sz-1;i++){
		min_index = i;
		for(int j=i+1;j<arr_sz;j++){
			if(arr[j]<arr[min_index]){
				min_index = j;
			}
		}
		swap(&arr[i],&arr[min_index]);
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
	selection_sort(arr,arr_sz);
	print_array(arr,arr_sz);
	return 0;
}
