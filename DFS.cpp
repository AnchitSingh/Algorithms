#include<bits/stdc++.h>
using namespace std;
vector<string> color;
int Dtime;
vector<int> p;
vector<int> d;
vector<int> f;
void addEdge(vector<int> g[],int u,int v){
    g[u].push_back(v);
    g[v].push_back(u);

}
void DFSUtil(vector<int> g[],int src){
    Dtime++;
    d[src]=Dtime;
    color[src]="gray";
    for(auto i= g[src].begin();i!=g[src].end();i++){
        if(color[*i]=="white"){
            p[*i]=src;
            DFSUtil(g,*i);
        }
    }
    color[src]="black";
    Dtime++;
    f[src]=Dtime;
}
void DFS(vector<int> g[],int V){
    color.assign(V,"white");
    p.assign(V,-1);
    d.assign(V,-1);
    f.assign(V,-1);
    Dtime=0;
    for(int i=0;i<V;i++){
        if(color[i]=="white"){
            DFSUtil(g,i);
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
    DFS(g, n); 
    for(int i=0;i<n;i++){
        printf(" %d ",d[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf(" %d ",f[i]);
    }
    return 0;
}
