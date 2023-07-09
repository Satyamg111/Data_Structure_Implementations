#include <iostream>
#define MAX_VAL 10
using namespace std;

void CountSort(int arr[],int n) {
    int i,C[MAX_VAL],O[n];
    
    for(i=0;i<MAX_VAL;i++){
        C[i] = 0;
    }
    for(i=0;i<n;i++){
        C[arr[i]]++;
    }
    for(i=1;i<MAX_VAL;i++){
        C[i] = C[i]+C[i-1];
    }
    i=n-1;
    while(i>=0){
        O[C[arr[i]]-1] = arr[i];
        C[arr[i]]--;
        i--;
    }
    for(i=0;i<n;i++){
        arr[i] = O[i];
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
    
    CountSort(arr,n);
    print(arr,n);

    return 0;
}
