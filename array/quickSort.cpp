#include<iostream>
using namespace std;


int partition(int *a,int s,int e){
    int i= s-1;
    int j=s;
    int p= a[e];

    while (j<=e-1){
        if(a[j]<=p){
            i=i+1;
            swap(a[i],a[j]);
        }
        j=j+1;
    }
    //tp put pivot at right place
    swap(a[i+1], a[e]);
    return i+1;
}

void quicksort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
    int p= partition(arr, s, e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main(){
    int n,a[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}