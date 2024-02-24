#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    //checks for further character
    bool isChecked(char ch){
        return (links[ch - 'a'] != NULL);
    }
    //create a node
    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }
    //get a node
    Node *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    int setRemove(){
        flag = false;
        return 1;
    }

    bool checkEnd(){
        return flag;
    }

};

class Trie{

    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isChecked(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isChecked(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->checkEnd();
    }

    int checkFirstTwo(string pre){
        Node *node = root;
        for(int i=0;i<pre.size();i++){
            if(!node->isChecked(pre[i])){
               return false;
            }
            node = node->get(pre[i]);
        }
        return true;
    }
 
    int remove(string word){

        Node *node = root;
        for(int i=0;i<word.size();i++){
            if(!node->isChecked(word[i])){
               return false;
            }
            node = node->get(word[i]);
        }
        return (node->setRemove());
    }

};
int main(){


    Trie tri;

    tri.insert("hsgdh");
    cout<<tri.search("hsgdh")<<endl;
    tri.remove("hsgdh");
    cout<<tri.search("hsgdh")<<endl;

    cout<<tri.checkFirstTwo("hsgdhy");

    return 0;

}