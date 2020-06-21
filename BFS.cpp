#include<bits/stdc++.h>
using namespace std;
vector<string> color;
vector<int> d;
vector<int> p;
void addEdge(vector<int> g[],int u,int v){
    g[u].push_back(v);
}
void BFSUtil(vector<int> g[],int s){
    queue<int> q;
    q.push(s);
    color[s]="Gray";
    d[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        printf(" %d ",u);
        for(auto i= g[u].begin();i!=g[u].end();i++){
            if(color[*i]=="White"){
                color[*i]="Gray";
                d[*i]=d[u]+1;
                p[*i]=u;
                q.push(*i);
            }
        }
        color[u]="Black";
    }
    
}
void BFS(vector<int> g[],int n){
    color.assign(n,"White");
    d.assign(n,std::numeric_limits<int>::max());
    p.assign(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]=="White"){
            BFSUtil(g,i);
        }
    }
}

int main(){
    int n = 7; 
    vector <int> g[n];   
    addEdge(g, 0, 1); 
    addEdge(g, 0, 2); 
    addEdge(g, 1, 3); 
    addEdge(g, 1, 4); 
    addEdge(g, 2, 5); 
    addEdge(g, 2, 6); 
    BFS(g, n); 
    printf("\nDistance from Source are : ");
    for(int i=0;i<7;i++){
        printf(" %d ",d[i]);
    }
    printf("\nParent of vertices are : ");
    for(int i=0;i<7;i++){
        printf(" %d ",p[i]);
    }
    printf("\n");
    return 0;
}