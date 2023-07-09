#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1 = m-l-+1;
	int n2 = r-m;
	int L[n1],R[n2];
	
	for(i=0,i<n1;i++)
	{
		
	}
}
void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		
		merge(arr,l,m,r);
	}
}
void print(int arr[],int n){
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n,i;
	cout<<"Enter length of array : ";
	cin>>n;
	int arr[n];
	cout<<"Enter array elements : "<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Original array"<<endl;
	print(arr,n);
	
	cout<<"Sorted array"<<endl;
	insertionSort(arr, n);
	print(arr,n);
	
	return 0;
}
