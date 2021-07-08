// Input:
// N = 7
// Arr[] = {4, 3, 7, 8, 6, 2, 1}
// Output: 3 7 4 8 2 6 1
// Explanation: 3 < 7 > 4 < 8 > 2 < 6 > 1

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool flag=true;

    for(int i=0;i<n-2;i++){
        if(flag){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
        else{
            if(a[i]<a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
        flag=!flag;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}