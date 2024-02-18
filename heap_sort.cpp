#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(int A[],int n,int i){
    int largest = i;
    int l = 2*i;
    int r = (2*i)+1;

    if(l<=n && A[l]>A[largest]){
    largest = l;
    }

    if(r<=n && A[r]>A[largest]){
    largest = r;
    }
    
    if (largest != i){
        swap(A[largest],A[i]);
        heapify(A,n,largest);
    }  
}

void heapsort(int A[],int n){
    for(int i = n/2 ; i >= 1; i--){
        heapify(A,n,i);
    }
    for(int i = n ; i >= 1 ; i-- ){
        swap(A[1],A[i]);
        heapify(A,i,1);
    }

}

void printArray(int A[], int n)
{
    for (int i = 1; i <= n; i++){
        cout<< A[i]<<endl;
    }
}

int main(){

    int A[7]={-1,12,20,1,5,10,105};
    int n = sizeof(A) / sizeof(A[0]);

    heapsort(A,n);   
    cout<<"sorted array is" <<endl;
    printArray(A, n);
    return 0;

}

