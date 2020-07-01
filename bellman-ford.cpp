#include<bits/stdc++.h>
using namespace std;
vector<int> d;
vector<int> p;
void addEdge(vector<pair<int,int>> g[],int u,int v,int wt){
    g[u].push_back(make_pair(v,wt));
}
void Init(int V,int src){
    d.assign(V,std::numeric_limits<int>::max()-1000);
    p.assign(V,-1);
    d[src]=0;
}
void relax(int u,int v, int wt){
    if(d[v]>d[u]+wt){
        d[v]=d[u]+wt;
        p[v]=u;
    }
}
bool BFord(vector<pair<int,int>> g[],int V,int s){
    Init(V,s);
    for(int i=1;i<=n-1;i++){
        for(int u=0;u< V;u++){
            for(auto it = g[u].begin();it != g[u].end();it++){
                int v=it->first;
                int wt=it->second;
                relax(u,v,wt);
            }   
        }
    }
    for(int u=0;u< V;u++){
        for(auto it = g[u].begin();it != g[u].end();it++){
            int v=it->first;
            int wt=it->second;
            if(d[v]>d[u]+wt){
                return false;
            }
        }   
    }
    return true;
}
int main(){
    int V = 5; 
    int E = 8;
    vector<pair<int, int> > adj[V]; 
    addEdge(adj, 0, 1, 10); 
    addEdge(adj, 0, 4, 20); 
    addEdge(adj, 1, 0, 10);
    addEdge(adj, 1, 2, 30); 
    addEdge(adj, 1, 3, 40); 
    addEdge(adj, 2, 3, 60); 
    addEdge(adj, 3, 4, 70);
    addEdge(adj, 1, 4, -10); 
    if(BFord(adj, V,0)){
        printf("No -ve Cycle\n");
        printf("\nDistance from Source are : ");
        for(int i=0;i<V;i++){
            printf(" %d ",d[i]);
        }
        printf("\nParent of vertices are : ");
        for(int i=0;i<V;i++){
            printf(" %d ",p[i]);
        }
        printf("\n");
    }else{
        printf("-ve cycle present\n");
    }
    
    return 0;
}
