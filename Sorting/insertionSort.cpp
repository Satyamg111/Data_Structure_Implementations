#include<iostream>
using namespace std;

void insertionSort(int arr[],int n)
{
	int i,j,curr;
	
	for(j=0;j<n;j++)
	{
		curr = arr[j];
		i = j-1;
		
		while((arr[i]>curr) && i>=0)
		{
			arr[i+1] = arr[i];
			i--;
		}
		arr[i+1] = curr;
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
