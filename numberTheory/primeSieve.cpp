#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int p[1000]={0};
    for(int i=3;i<=1000;i=i+2){
        p[i]=1;
    }

    for(long long int i=3;i<=1000;i=i+2){
        if(p[i]==1){
            for(long long int j= i*i;j<1000; j= j+i){
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[1]=p[0]=0;

    for(int i=0;i<=n;i++){
        if(p[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}