#include<iostream>
using namespace std;

int main(){

    int a[100],e,m,s,n, key,flag=0;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cin>>key;

    s=0;
    e=n-1;

    while (e>=s){
        
        m=(s+e)/2;

        if(key>a[m]){
            s=m+1;
        }

        else if(key==a[m]){
            flag=1;
            break;
        }
        else{
            e=m-1;
        }
    }

    if(flag==1){
        cout<<"element found";
    }
    else{
        cout<<"Not found";
    }
    return 0;
}