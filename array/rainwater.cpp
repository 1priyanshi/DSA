#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int left[100000], right[100000],mxl=0,mxr=0;
    for(int i=0;i<n;i++){
        if(a[i]>mxl){
            mxl=a[i];
        }
        left[i]=max(a[i],mxl);
    }
    for(int i=n-1;i>=0;i--){
         if(a[i]>mxr){
            mxr=a[i];
        }
        right[i]=max(a[i],mxr);
    }
    int w=0;
    for(int i=0;i<n;i++){
        w+= min(left[i],right[i])-a[i];
    }
    cout<<w;
    return 0;
}