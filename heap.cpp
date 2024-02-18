#include<bits/stdc++.h>
using namespace std;

//define Heap
// It is a data structure which works on the principle of complete binary tree
//  and uses array data structure to store data into it.

class heap{
    public:
    int arr[100];
    int size;
    heap(){
        size = 0;
        arr[0] = -1;
    }
    
    void insert(int val){
        size += 1;
        int index = size;
        arr[index] = val;
        while(index > 1){
            int parent = index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void del(){
        int i;
        swap(arr[1],arr[size]);
        size--;
        i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if(leftIndex<size && arr[i]<arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }else if(rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }else{
                return;
            }
        }

    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

//heapyfy function does check in the heap if there is any violation in max heap it fixes the tree

int heapyfy(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapyfy(arr,n,largest);
    }

}
void heap_sort(int arr[],int n){
    int size = n;

    while(size > 0){
        swap(arr[size],arr[0]);
        size--;
        heapyfy(arr,size,0);
    }
}
int main(){
    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // h.del();
    // h.print();

    int arr[5] = {54,53,55,52,50};
    int n=4;
    //why heapyfy?
    //It checks in the array is if there is violation of max heap in the
    // order of log n time complexity O(log n) and we are avoiding the leaf node elements to decrease time complexity
    //Note--Heapyfy function also brings the max element at the top of the index value which helps in heap sort

    //assumptions::It start traversal from n/2 till 1 and recursive call in heapfy function till which it checks left and right child

    for(int i=n/2;i>=0;i--){
        heapyfy(arr,n,i);
    }

    cout<<"printing array after heapyfy"<<endl;

    for(int i=0;i<=n;i++){
    cout<<arr[i]<<" ";
    }

    heap_sort(arr,n);

    cout<<endl<<"printing array after heapyfy"<<endl;

    for(int i=0;i<=n;i++){
    cout<<arr[i]<<" ";
    }

    cout<<endl;
    return 0;
}