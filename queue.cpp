#include <bits/stdc++.h> 
using namespace std;
class Queue {
    int qfront;
    int rear;
    int size;
    int *arr;

public:
    Queue() {
        size = 100001;
       arr = new int[size];
        rear = 0;
        qfront = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
       if(qfront == rear){
           return 1;
       }
       return 0;
    }

    void enqueue(int data) {
        if(rear == size){
            cout<<"full";
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        int ans = arr[qfront];
        if(qfront == rear){
            return -1;
        }else{
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
       if(qfront == rear){
           return -1;
       }
       return arr[qfront];
    }
};
int main(){
    return 0;
}