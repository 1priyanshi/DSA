#include<iostream>
using namespace std;

int countbit(int n){
    int c=0;
    while (n>0){
        n= (n & (n-1));
        c++;
    }
    return c;
}

int main(){

    int t;
    cin>>t;
    while (t>0){
        int a,b,ans=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++){
            ans+= countbit(i);
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}
