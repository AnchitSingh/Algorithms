#include<bits/stdc++.h>
using namespace std;
int maxLen(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int lps(string a,int i,int l){
    if(i>l){                //Base case when we have traversed half of string.
        return 0;
    }
    if(i==l){
        return 1;
    }
    int c1=0;
    if(a[i]==a[l]){
        c1=2+lps(a,i+1,l-1);
    }
    int c2=lps(a,i,l-1);
    int c3=lps(a,i+1,l);
    return maxLen(c1,maxLen(c2,c3));
}
int main(){
    string a;
    cin>>a;
    printf("Length of longest palindromic substring is : %d",lps(a,0,a.size()-1));
    return 0;
}
