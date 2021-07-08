// #include<iostream>
// #include<>
// using namespace std;

// int main(){

//     int n;
//     cin>>n;

//     int a[100];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int l=0;
//     int mid = 0;
//     int h= n-1;

//     while (mid<=h){

//         if(a[mid]=='0'){
//             swap(a[mid++],a[l++]);
//         }
//         else if(a[mid]=='1'){
//             mid++;
//         }
//         else if(a[mid]=='2'){
//             swap(a[mid],a[h--]);
//         }
//     }

//      for(int i=0;i<n;i++){
//         cout<<a[i];
//     }

//     return 0;
// }

#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int c0=0,c1=0,c2=0,i=0;

    while (i<n){

        if(a[i]==0){
            c0++;
        }
        else if(a[i]==1){
            c1++;
        }
        else if(a[i]==2){
            c2++;
        }
        i++;
    }

    int j=0;

    while(c0>0){
        a[j++]=0;
        c0--;
    }
    while(c1>0){
        a[j++]=1;
        c1--;
    }
    while(c2>0){
        a[j++]=2;
        c2--;
    }

     for(int k=0;k<n;k++){
        cout<<a[k]<<" ";
    }

    return 0;
}