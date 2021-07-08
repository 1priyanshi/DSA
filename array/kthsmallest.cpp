#include<iostream>
#include<algorithm>
using namespace std;

void merge(int a[],int left, int m, int right){

    int n1= m-left+1;
    int n2= right-m;

    int l[n1],r[n2];

    for(int i=0;i<n1;i++){
        l[i]=a[left+i];
    }

    for(int i=0;i<n2;i++){
        r[i]=a[m+i+1];
    }

    int i=0,j=0,k=left;

    while (i<n1 && j<n2){
        if(l[i]<=r[j]){
            a[k++]=l[i++];
        }
        else{
            a[k++]= r[j++];
        }
    }

    while (i<n1){
        a[k++]=l[i++];
    }
    while (j<n2){
        a[k++]=r[j++];
    }  
    
}

void mergeSort(int a[], int left, int right){
    if(left>=right){
        return;
    }
    int m= left +(right-1)/2;
    mergeSort(a,left,m);
    mergeSort(a,m+1,right);
    merge(a,left,m,right);
}

int main(){
    int n,k;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];                                                       //not done
    }
    cin>>k;
    
    mergeSort(a,0,n-1);

    // cout<<a[k-1];
     for(int i=0;i<n;i++){
       cout<<a[i]<<" ";
    }
    return 0;
}