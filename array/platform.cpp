#include<iostream>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;
    int a[100000],b[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int i=0,p=1;
    if(b[i]<=a[i+1] || a[i]>= b[i+1]){
        p=p;
    }
    else{
        p++;
    }
    cout<<p;
    return 0;
}