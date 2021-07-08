// Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.
// Input:
// N = 5, K = 3
// arr[] = {1,2,3,4,5}
// Output: 3 2 1 5 4
// Explanation: First group consists of elements
// 1, 2, 3. Second group consists of 4,5.

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int i=0;
    while (i+k<n){
        int j=i+k;
        reverse(a+i,a+j);
        i=i+k;
    }

    if(i<n){
        reverse(a+i,a+n);
    }

      for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}