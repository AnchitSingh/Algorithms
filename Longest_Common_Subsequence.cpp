#include<bits/stdc++.h>
using namespace std;
int maxLen(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int lcs(string a,string b,int i1,int i2){
    if(i1==a.size()||i2==b.size()){
        return 0;
    }
    int c1=0;
    if(a[i1]==b[i2]){
        c1=1+lcs(a,b,i1+1,i2+1);
    }
    int c2=lcs(a,b,i1+1,i2);
    int c3=lcs(a,b,i1,i2+1);
    return maxLen(c1,maxLen(c2,c3));
}
int main(){
    string a,b;
    cin>>a;
    cin>>b;
    printf("length is %d",lcs(a,b,0,0));

    return 0;
}
