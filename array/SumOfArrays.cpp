#include<iostream>
using namespace std;

int main(){

    int n, a[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int m, b[1000];
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    int c[1000]={0},carry=0;
    int p=min(n,m);
    int h= max(n,m);

    for(int i=0;i<p;i++){
        c[h-1-i]= (a[n-1-i]+b[m-1-i]+carry)%10;
        carry = (a[n-1-i]+b[m-1-i]+carry)/10;
    }

    for(int i=(h-p-1);i>=0;i--){
        if(m>n){
            c[i]= (b[i]+carry)%10;
            carry= (b[i]+carry)/10;
        }
        else{
            c[i]= (a[i]+carry)%10;
            carry= (a[i]+carry)/10;
        }
    }

    if(carry!=0){
            cout<<carry<<" ";
        }

    for(int i=0;i<h;i++){
            cout<<c[i]<<" ";
    }
    cout<<"END";

    return 0;
}