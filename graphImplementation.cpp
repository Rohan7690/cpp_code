#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>> adj;
    void addNode(int u,int v,int direction){
        //undirected graph
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printNodes(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }cout<<""<<endl;
        }
    }
};
int main(){
    graph g;
    int n,m;
    cout<<"Enter the Numbers of nodes"<<endl;
    cin>>n;
    cout<<"Enter the Number of Edges"<<endl;
    cin>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addNode(u,v,0);
    }

    g.printNodes();

    return 0;
}