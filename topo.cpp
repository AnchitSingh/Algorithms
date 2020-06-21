#include<bits/stdc++.h>
using namespace std;
vector<string> visited;
stack<int> s;
void addEdge(vector<int> g[],int u,int v){
    g[u].push_back(v);
}
void topoUtil(vector<int> g[],int src){
    for(auto it=g[src].begin();it!=g[src].end();it++){
        if(visited[*it]=="no"){
            topoUtil(g,*it);
        }
    }
    visited[src]="yes";
    s.push(src);
}
void topo(vector<int> g[],int V){
    visited.assign(V,"no");
    for(int i=0;i<V;i++){
        if(visited[i]=="no"){
            topoUtil(g,i);
        }
    }
}

int main(){
    int V = 8; 
    vector <int> g[V];   
    addEdge(g, 0, 2); 
    addEdge(g, 1, 2); 
    addEdge(g, 1, 3); 
    addEdge(g, 2, 4); 
    addEdge(g, 3, 5); 
    addEdge(g, 4, 5); 
    addEdge(g, 5, 6); 
    addEdge(g, 4, 7); 
    topo(g,V);
    for(int i=0;i<V;i++){
        printf(" %d ",s.top());
        s.pop();
    }
    return 0;
}