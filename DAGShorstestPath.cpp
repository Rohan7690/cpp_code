#include<bits/stdc++.h>
using namespace std;

class graph{
    private:
    unordered_map<int,list<pair<int,int>>> adj;

    public:

    void addNode(int u,int v,int weight){
        pair<int,int> p = make_pair(v,weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")";
            }cout<<endl;
        }
    }

    void dfs(int src,stack<int> &s,unordered_map<int,bool> &vis){
        vis[src] = 1;
        for(auto neighbor:adj){
            if(!vis[neighbor.first]){
                dfs(neighbor.first,s,vis);
            }
        }
        s.push(src);
    }

    void shortestPath(int src,vector<int> &dis,stack<int> s){
        dis[src] = 0;

        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(dis[top]!=INT_MAX)
            for(auto i:adj[top]){
                int v = i.first;
                int wt = i.second;
                if(dis[top]+wt < dis[v]){
                    dis[v] = dis[top] + wt;
                }
            }
        }
    }

};
int main(){
    graph g;

    g.addNode(0,1,5);
    g.addNode(0,2,3);
    g.addNode(1,2,2);
    g.addNode(1,3,6);
    g.addNode(2,3,7);
    g.addNode(2,4,4);
    g.addNode(2,5,2);
    g.addNode(3,4,-1);
    g.addNode(4,5,-2);

    g.printAdj();

    //topological sort

    unordered_map<int,bool> vis;
    stack<int> s;
    int n = 6;
    for(int i=0; i<n ;i++){
        if(!vis[i]){
            g.dfs(i,s,vis);
        }
    }

    int src = 1;
    vector<int> dis(n);

    for(int i=0;i<n;i++){
        dis[i] = INT_MAX;
    }

    g.shortestPath(src,dis,s);

    cout<<"ans:";

    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }

    return 0;
}