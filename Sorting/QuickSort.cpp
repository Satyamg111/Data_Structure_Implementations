#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int position(int arr[],int l,int r) {
    int piv = arr[l];
    int i=l ,j=r;
    
    while(i<j) {
        while(arr[i] <= piv) i++;
        while(arr[j] > piv) j--;
    
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[l],&arr[j]);

    
    return j;
}
void QuickSort(int arr[],int l,int r) {
    if(l<r) {
        int piv = position(arr,l,r);
        QuickSort(arr,l,piv-1);
        QuickSort(arr,piv+1,r);
    }
}
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int n;
    cout<<"Enter n = ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements "<<endl;
    for(int i=0;i<n;i++) {
    	cin>>arr[i];
	}
    
	print(arr,n);
    
    QuickSort(arr,0,n-1);
    print(arr,n);

    return 0;
}
