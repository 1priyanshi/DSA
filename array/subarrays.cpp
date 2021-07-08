#include<iostream>
using namespace std;

int main(){

    int a[1000], n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0,max=sum;
            for(int k=i;k<=j;k++){
                cout<<a[k]<<",";
            }
            cout<<endl;
        }
    }
    return 0;
}