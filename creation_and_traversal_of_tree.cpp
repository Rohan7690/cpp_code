#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<< "enter data "<<endl;
    int d;
    cin>>d;
    root = new node(d);
    /// recursive call 
    //base case
    if(d == -1){
        return NULL;
    }

    cout<<"enter the left child"<<endl;
    root->left=buildTree(root->left);

    cout<<"enter the right child"<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        /// space dene ke liye
        if(temp == NULL){
            cout<<endl;
            //change line after end of level current level
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);    
        }
        
        if(temp->right){
            q.push(temp->right);    
        }  
        }
       
    }
}

void reverse(node* root){
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        /// space dene ke liye
        if(temp == NULL){
            cout<<endl;

            //change line after end of level
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";
        s.push(temp);
        if(temp->left){
            q.push(temp->left);    
        }
        
        if(temp->right){
            q.push(temp->right);    
        }  
        }


       
    }
    
    while(!s.empty()){
    node* temp = s.top();
    s.pop();
    cout<<temp->data<<" ";
    }

}
void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
node* buildLevelOrderTraversal(node* &root){
    queue<node*> q;
    int data;
    cout<<"enter data for root element"<<endl;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        int leftChild;
        cout<<"enter the left child "<< temp->data<<endl;
        cin>>leftChild;

        if(leftChild != -1){
            temp->left = new node(leftChild);
            q.push(temp->left);
        }
        
        int rightChild;
        cout<<"enter the right child "<< temp->data<<endl;
        cin>>rightChild;
        if(rightChild != -1){
            temp->right  = new node(rightChild);
            q.push(temp->right);
        }
    }



}
int main(){
    node* root = NULL;
    buildLevelOrderTraversal(root);
    reverse(root);

    // root = buildTree(root);
    // 10 7 8 -1 -1 3 -1 -1 13 5 9 -1 -1 -1 6 10 -1 -1 -1 
    // cout<<"printing"<<endl;
    // levelOrderTraversal(root);
    // cout<<"inorder";
    // inorder(root);
    //     cout<<"preorder";
    // preorder(root);
    //     cout<<"postorder";
    // postorder(root);

    return 0;
}