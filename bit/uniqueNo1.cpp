#include<iostream>
using namespace std;

int main(){
    int n,ans=0;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        ans= ans^a[i];
    }

    cout<<ans;
    return 0;
}