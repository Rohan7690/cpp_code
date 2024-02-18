#include<bits/stdc++.h>
using namespace std;

class kqueue{
    public:
    int size;
    int num;
    int *front;
    int *rear;
    int *arr;
    int *next;
    int freespot;

    kqueue(int size,int num){
        this->size = size;
        this->num = num;
        arr = new int[size];
        front = new int[num];
        rear = new int[num];
        for(int i = 0 ; i <num ; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        freespot = 0 ;
        next = new int[size];
        for(int i = 0 ; i <size ; i++){
            next[i] = i+1;
        }
        next[size-1]=-1;

    }

    int enque(int val,int n){
        if(freespot == -1){
            cout<<"OverFLow";
            return 0;
        }
        int ind = freespot;
        freespot = next[ind];
        if(front[n-1] == -1){
            front[n-1] = ind;
        }else{
           next[rear[n-1]] = ind;
        }
        next[ind] = -1;
        rear[n-1] = ind;
        arr[ind] = val;
        return 1;
    }
    void deque(int n){
        //underflow
        if(front[n-1] == -1){
            cout<<"underflow";
            return;
        }
        int ind = front[n-1];

        //front update
        front[n-1] = next[ind];
        next[ind] = freespot;
        freespot = ind;
        cout<<arr[ind]<<endl;

    }


};

int main(){

    kqueue q(6,3);

    q.enque(10,1);
    q.enque(11,2);
    q.enque(12,1);
    q.enque(10,1);
    q.enque(11,2);
    q.enque(12,1);

    q.deque(2);
    q.enque(13,3);
    q.deque(3);

    return 0;
}