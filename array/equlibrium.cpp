// Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
// Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
  
    for(int i=0;i<n;i++){
        sum+=a[i];
    }

     for(int i=0;i<n;i++){
        sum-=a[i];

        if(leftsum==sum){
            return i+1;
            flag++;
        }
        leftsum+=a[i];
    }
    if(flag==0){
        return -1;
    }

    return 0;
}