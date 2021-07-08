#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    while (t>0){
        int n,ans=0;
        cin>>n;
        while (n>0){
            ans+= n&1;
            n= n>>1;
        }
        cout<<ans<<endl;
        t--;
    }
    
    return 0;
}