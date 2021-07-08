#include<iostream>
using namespace std;

int main(){
    int n,m,ans=0;
    cin>>n>>m;

    int a[100000],b[100000],c[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    for(int i=0;i<n;i++){
        c[a[i]]= c[a[i]]+1;
    }

    for(int i=0;i<m;i++){
        if(c[b[i]]>0){
            ans++;
            c[b[i]]-=1;
        }
    }

    cout<<ans;
    return 0;
}