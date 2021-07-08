// Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader 
// if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 
// n = 6
// A[] = {16,17,4,3,5,2}
// Output: 17 5 2
// Explanation: The first leader is 17 
// as it is greater than all the elements
// to its right.  Similarly, the next 
// leader is 5. The right most element 
// is always a leader so it is also 
// included.
 

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> max[100000];
    max[0]=a[n-1];

    int i,j=0;
    for(i= n-2; i>=0 ;i--){
        if(max[j]<a[i]){
            max[++j]=a[i];
        }
    }

     for(int i= j;i>=0;i--){
        cout<<max[i]<<" ";
    }
    return 0;
}