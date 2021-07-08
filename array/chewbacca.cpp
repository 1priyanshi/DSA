#include<iostream>
#include<math.h>
using namespace std;

int main(){

    long long int n,a[100000],N;
    cin>>n;

    int i=0;

    while(n/10>0){

        N= n%10;
        if(9-N < N){
            a[i]= 9-N;
        }
        else{
            a[i]=N;
        }

        n=n/10;
        i++;
    }

    if(9-n<n){
        cout<<9-n;
    }
    else{
        cout<<n;
    }

    for(int j=i-1;j>=0;j--){
        cout<<a[j];
    }
    return 0;
}