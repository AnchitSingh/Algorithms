#include<bits/stdc++.h>
using namespace std;

struct node{
    int v;
    int dist;
};
class minHeap{
    int capacity;
    int heap_size;
    struct node *h;
    public:
        minHeap(int c);
        int leftKey(int i){return (2*i+1);}
        int rightKey(int i){return (2*i+2);}
        int parent(int i){return (i-1)/2;}
        int getMin(){return h[0].v;}
        int extractMin();
        void insertKey(int v,int d);
        void deleteKey(int i);
        void decreaseKey(int i,int n);
        void minHeapify(int i);
        bool empty();
};
bool minHeap::empty(){
    if(heap_size==0){
        return true;
    }else{
        return false;
    }
}
minHeap::minHeap(int c){
    capacity=c;
    heap_size=0;
    h=new node[c];
}
int minHeap::extractMin(){
    if(heap_size==0){
        return 50000;
    }
    if(heap_size==1){
        heap_size--;
        return h[0].v;
    }
    int root=h[0].v;
    heap_size--;
    h[0].dist=h[heap_size].dist;
    minHeapify(0);
    return root;
}
void minHeap::minHeapify(int i){
    int l=leftKey(i);
    int r=rightKey(i),smallest;
    if(l<heap_size && h[l].dist<h[i].dist){
        smallest=l;
    }else{
        smallest=i;
    }
    if(r<heap_size && h[r].dist<h[smallest].dist){
        smallest=r;
    }
    if(smallest!=i){
        int temp_d=h[smallest].dist;
        int temp_v=h[smallest].v;
        h[smallest].dist=h[i].dist;
        h[smallest].v=h[i].v;
        h[i].dist=temp_d;
        h[i].v=temp_v;
        minHeapify(smallest);
    }
}
void minHeap::decreaseKey(int i,int n){
    h[i].dist=n;
    while(i!=0 && h[parent(i)].dist>h[i].dist){
        int temp_d=h[parent(i)].dist;
        int temp_v=h[parent(i)].v;
        h[parent(i)].dist=h[i].dist;
        h[parent(i)].v=h[i].v;
        h[i].dist=temp_d;
        h[i].v=temp_v;
        i=parent(i);
    }
}
void minHeap::insertKey(int v,int d){
    heap_size++;
    int i=heap_size-1;
    h[i].dist=10000;
    h[i].v=v;
    decreaseKey(i,d);
}
void minHeap::deleteKey(int i){
    heap_size--;
    decreaseKey(i,-1000);
    extractMin();
}
int main(){
    minHeap hp(10);
    hp.insertKey(16,500);
    hp.insertKey(7,50);
    hp.insertKey(12,0);
    hp.insertKey(71,520);
    printf(" %d ",hp.extractMin());
    printf(" %d ",hp.extractMin());
    return 0;
}