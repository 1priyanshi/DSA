#include<iostream>
using namespace std;

void insertionSort(int a[], int n){
    
    for(int i=1;i<n;i++){
        int e = a[i];

        int j= i-1;
        while(j>=0 && a[j]>e){
            a[j+1] = a[j];
            j=j-1;
        }
        a[j+1]=e;
    }
}

int main(){
    
    int a[100],n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    insertionSort(a,n);
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}