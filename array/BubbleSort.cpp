#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){

    for(int j=0;j<n;j++){
        int N= n-j;
        for(int i=0;i<N;i++){
        int k= i+1;
        if(a[k]<a[i]){
            swap(a[k],a[i]);
        }
    }
    }
    
}

int main(){

     int a[100],n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    bubbleSort(a,n);
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}