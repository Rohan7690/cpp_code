#include<bits/stdc++.h>
using namespace std;
class Stack{

    int *arr;
    int size;
    int top;
    public:
    Stack(int size){
        this->size = size;
        arr= new int[size];
        top = -1;
    }
    void push(int val){
        if(top>=size){
            cout<<"stack overflow"<<endl;
        }else{
            top++;
            arr[top]=val;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
        }else{
            int temp = arr[top];
            top--;
        }
    }
    void peek(){
        cout<<arr[top]<<endl;
    }
    void print(){
        int temp = top;
        while(temp!=-1){
            cout<<arr[temp]<<" ";
            temp--;
        }
        cout<<endl;
    }
};

int main(){
    Stack st(3);
    st.push(2);
    st.print();
    st.push(3);
    st.print();
    st.push(23);
    st.print();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.print();
    st.push(26);
    st.print();
    st.push(55);
    st.print();
    st.push(3);
    st.print();

    st.peek();
    st.print();
    return 0;
}