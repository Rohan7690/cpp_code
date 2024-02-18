// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    /// intialization
    Node(int data){
        this->data = data;
        this->next = NULL;        
    }
};
void InsertFromHead(Node* &head ,int data){
    Node* temp= new Node(data);
    temp->next = head;
    head = temp;

}
void InsertPosition(Node* &head,int after,int data){
    Node *temp = head;
    Node *btw = new Node(data);
    btw->next=NULL;
    btw->data=data;
    while(temp->data!=after){
        temp=temp->next;
    }
    btw->next=temp->next;
    temp->next = btw;
}
void InsertFromTail(Node* &tail,int data){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next; 
    tail->next = NULL;
}

void DeleteFromHead(Node * &head){
    Node * temp = head;
    head = head->next;
    free(temp);
}
void DeleteFromTail(Node * &head,Node* &tail){
    Node * temp = head;
   while(temp->next!=tail){
    temp = temp->next;
   }
   tail = temp;
   temp = tail->next;
   tail->next=NULL;
   free(temp);
}

void print(Node * &head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;

}
int main(){
    Node* node = new Node(12);
    Node *head = node;
    Node *tail = node;

    InsertFromHead(head,11);
    InsertFromHead(head,10);
    InsertFromTail(tail,13);
    InsertFromTail(tail,14);
    InsertFromHead(head,9);
    InsertFromTail(tail,15);
    print(head);
    DeleteFromHead(head);
    print(head);
    DeleteFromTail(head,tail);
    print(head);
    InsertPosition(head,12,16);
    print(head);
    InsertPosition(head,16,17);
    print(head);
    return 0;
}