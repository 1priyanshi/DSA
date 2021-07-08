// Given an array arr of N integers, write a function that returns true 
// if there is a triplet (a, b, c) that satisfies a2 + b2 = c2, otherwise false.

#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
                                                                                   //Not done
int main(){

    int n,a[100000],flag=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k=j+1;
            while (k<n){
                if(pow(a[i],2)+ pow(a[j],2)==pow(a[k],2)){
                    flag=1;
                    break;
                }
            }
        }
    }
    if(flag==0){
        cout<<"no";
    }
    else{
        cout<<"yes";
    }
    return 0;
}