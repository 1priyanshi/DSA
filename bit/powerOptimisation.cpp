#include<iostream>
using namespace std;

int main(){
    int a,n,ans=1;
    cin>>a>>n;
    while (n>0){
        int lb= (n&1);
        if(lb){
            ans=ans*a;
        }
        a=a*a;
        n= n>>1;
    }
    
    cout<<ans;
    return 0;
}
