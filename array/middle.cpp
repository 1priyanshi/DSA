// Given an unsorted array of size N. Find the first element in array such that all of its left 
// elements are smaller and all right elements to it are greater than it.

// Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n,flag=0;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int min[100000],max[100000];
    min[0]=0;
    max[n-1]=0;
    int mx=a[0], mi= a[n-1];

   for(int i=1;i<n;i++){
       if(a[i]>mx){
           max[i]=1;
           mx=a[i];
       }
       else{
           max[i]=0;
       }
   }
    for(int i=n-2;i>=0;i--){
        if(a[i]<=mi){
            min[i]=1;
            mi=a[i];
        }
        else{
            min[i]=0;
        }
    }
    for(int i=1;i<n-1;i++){
        if(min[i]==1 && max[i]==1){
            flag=1;
            cout<<a[i];
        }
    }
    if(flag==0){
        cout<<"-1";
    }
    return 0;
}