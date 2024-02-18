#include <bits/stdc++.h> 
int partition(vector<int>& arr,int s,int e){
    int pivot = arr[s];
    int count = 0;
    for(int i = s+1 ; i<=e ;i++){
        if(arr[i]<=pivot){
            count++;
        }
    } 
    count = s + count;
    int i = s;
    int j = e;
    swap(arr[count],arr[s]);
    while(i<count && j>count){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<count && j>count){
            swap(arr[i++],arr[j--]);
        }
    }
    return count;

}
void quicksort(vector<int>& arr,int s ,int e){
    if(s>=e)
        return;
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);

}
vector<int> quickSort(vector<int> arr)
{
    quicksort(arr,0,arr.size()-1);
    return arr;
}
