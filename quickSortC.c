#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int i ,int j){
    int pivot = arr[i];
    //reserved pointer
    int l = i;
    int h = j;

    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);

        do{
            j--;
        }while(arr[j]>pivot);
        
        if(i<j)  
        swap(&arr[i],&arr[j]);
    }

    swap(&arr[l],&arr[j]);
    return j;
    
}

void quickSort(int arr[], int low, int high){
    if(low<high){
    int j = partition(arr,low,high);
    quickSort(arr,low,j);
    quickSort(arr,j+1,high);
    }
}

int main(){
    int arr[5] = {6,23,9,0,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n);

    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }

    return 0;

}

