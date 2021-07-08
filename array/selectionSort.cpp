#include<iostream>
using namespace std;

void selectionSort(int a[], int n){

    for(int i=0;i<n-1;i++){
        int min_index=i;

        for(int j=i;j<n;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }

        swap(a[i],a[min_index]);
    }
}

int main(){

    int a[100],n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    selectionSort(a,n);
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}