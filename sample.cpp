#include<iostream>

using namespace std;

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[],int i ,int j){
    int pivot = arr[i];

    while(i<j){
        do{
            i++;
        }while(arr[i]>=pivot);

        do{
            j--;
        }while(arr[j]<pivot);
            
        swap(arr[i],arr[j]);
    }

    swap(pivot,arr[j]);

}

void quickSort(int &arr[], int low, int high){
    if(low<high){
        int j = partition(arr,low,high);
        quickSort(arr,low,j);
        quickSort(arr,j+1,high);
    }
}

int main(){
    int arr[5] = {5, 4, 3, 2, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<"\n";
    }

    return 0;

}