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

    int temp = ans, pos=0;
    while ((temp&1)==0){
        pos++;
        temp=temp>>1;
    }

    int mask = 1<<pos,x=0,y=0;

    for(int i=0;i<n;i++){
        if(a[i]&mask>0){
            x=x^a[i];
        }
    }

    y= x^ans;

    cout<<min(x,y)<<" "<<max(x,y);
    
    return 0;
}