//3 loops
// #include<iostream>
// using namespace std;

// int main(){

//     int a[1000], n, max=0,left=0, right=0;
//     cin>>n;

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){
//                 sum=sum+ a[k];
//             }
//             if(sum>max){
//                 max= sum;
//                 left =i;
//                 right=j;
//             }
//         }
//     }
//     cout<<max<<endl;
//     for(int i=left;i<right;i++){
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }

//2 loops
// #include<iostream>
// using namespace std;

// int main(){

//     int a[1000], n,cumSum[1000]={0}, max=0,left=-1, right=-1;
//     cin>>n;

//     cin>>a[0];
//     cumSum[0]=a[0];

//     for(int i=1;i<n;i++){
//         cin>>a[i];
//         cumSum[i]=cumSum[i-1]+ a[i];
//     }

//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int CurrentSum=0;

//             CurrentSum= cumSum[j]- cumSum[i-1];

//             if(CurrentSum>max){
//                 max= CurrentSum;
//                 left =i;
//                 right=j;
//             }
//         }
//     }
//     cout<<max<<endl;
//     for(int i=left;i<right;i++){
//         cout<<a[i]<<" ";
//     }
//     return 0;
// }


//kadane's Algo(1 loop)
#include<iostream>
using namespace std;

int main(){

    int n,a[1000],cs=0,ms=0;
    cin>>n;

    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    for(int i=0;i<n;i++){
        cs= cs+ a[i];
        if(cs<0){
            cs=0;
        }
        ms=max(cs,ms);
    }

    cout<<ms;

    return 0;
}


