#include<iostream>
using namespace std;

void swap(int*a,int*b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertion_sort(int*arr,int arr_sz){
	for(int i=1;i<arr_sz;i++){
		int p_elem = arr[i];
		int j = i-1;
		while(j>-1 && arr[j]>p_elem){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = p_elem;
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
	insertion_sort(arr,arr_sz);
	print_array(arr,arr_sz);
	return 0;
}
