// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

// Input Format
// The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

//2 number sum
// #include<iostream>
// using namespace std;

// int main(){

//     int n,a[1000],target;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     cin>>target;
//     sort(a,a+n);

//     int i=0,j=n-1;

//         while(i<=j){
//             if(a[i]+a[j]<target){
//             i++;
//             }
//             else if(a[i]+a[j]==target){
//                 cout<<a[i]<<" "<<a[j]<<endl;
//                 i++;
//                 j--;
//             }
//             else{
//                 j--;
//             }
//         }
   
//     return 0;
// }






// 3 number sum
#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n,a[1000],target;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>target;

    sort(a,a+n);

    for(int k=0;k<n;k++){
        int i=k+1,j=n-1;
        while(i<j){
            if(a[i]+a[j]+a[k]<target){
            i++;
            }
            else if(a[i]+a[j]+a[k]==target){
                if(a[i]>a[j]){
                    cout<<a[k]<<" "<<a[j]<<" "<<a[i]<<endl;
                }
                else{
                    cout<<a[k]<<" "<<a[i]<<" "<<a[j]<<endl;
                }
                i++;
                j--;
            }
            else{
                j--;
            }
        }
    }
   
    return 0;
}
