#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root,int data){
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right,data);
    }else{
        root->left = insertIntoBST(root->left,data);
    }

    return root;
}

void inputData(Node* &root){
    int data;
    cout<<"Input the data in BST"<<endl;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
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
        if(temp->left){
            q.push(temp->left);    
        }
        
        if(temp->right){
            q.push(temp->right);    
        }  
        }
       
    }
}
Node* maxValue(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* minValue(Node* root){
    Node* temp = root;

    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
//####################################IMPORTANT################################################################
Node* deleteInBST(Node* root,int val){
    if(root == NULL){
        return root;
    }
    
    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        //thoda sa confusing
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteInBST(root->right,mini);
            return root;
        }
    }else if(root->data < val){
        root->right = deleteInBST(root->right,val);
        return root;
    }else{
        root->left = deleteInBST(root->left,val);
        return root;
    }
}
int main(){ 
    Node* root = NULL;
    inputData(root);
    cout<<"Min Value"<<minValue(root)->data<<endl;
    cout<<"Max Value"<<maxValue(root)->data<<endl;
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    deleteInBST(root,83);
    cout<<"Min Value"<<minValue(root)->data<<endl;
    cout<<"Max Value"<<maxValue(root)->data<<endl;
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);
    return 0;
}