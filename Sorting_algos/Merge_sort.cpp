#include<iostream>
using namespace std;

void swap(int*a,int*b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void merge(int*arr,int low,int mid,int high){
	int i = low;
	int j = mid+1;
	int k = low;
	int temp_arr[100];
	while(i <= mid && j <= high){
		if(arr[i] < arr[j]){
			temp_arr[k++] = arr[i++];
		}
		else{
			temp_arr[k++] = arr[j++];
		}
	}
	while(i<=mid){
		temp_arr[k++] = arr[i++];
	}
	while(j<=high){
		temp_arr[k++] = arr[j++];
	}
	for(int l=low;l<k;l++){
		arr[l] = temp_arr[l];
	}
}

void merge_sort(int*arr,int low,int high){
	//int mid;
	if(low < high){
		int mid = (low+high)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);
		merge(arr,low,mid,high);
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
	merge_sort(arr,0,arr_sz-1);
	print_array(arr,arr_sz);
	return 0;
}
