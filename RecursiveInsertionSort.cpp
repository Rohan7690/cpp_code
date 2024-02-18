//insertion sort with recursion
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n){
    if(n<=1){
        return;
    }
    insertion_sort(arr,n-1);
    int key = arr[n-1];
    int j = n-2;
    while( j >= 0 && arr[j] > key){
        //copy element further
        arr[j+1]=arr[j];
        j--;
    }
    //less than element j se ausko copy karege auske age wale index pe
    arr[j+1]=key;
}
int main(){
    int arr[] = {5,3,6,7,2,1};
    insertion_sort(arr,6);
    for(int i =0 ;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

