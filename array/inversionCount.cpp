// For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 
// has three inversions (2, 1), (4, 1), (4, 3).

#include<iostream>
using namespace std;

int merge(int a[], int temp[], int left, int mid, int right){

    int i,j,k;
    int count=0;

    i=left;
    j=mid;
    k=left;

    while((i<=mid-1) && (j<=right)){
        if(a[i]<=a[j]){
            temp[k++]= a[i++];
        }
        else{
            temp[k++]=a[j++];
            count= count+ mid-i;
        }
    }
     while (i <= mid - 1)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];
 
    for (i = left; i <= right; i++)
        a[i] = temp[i]; 
 
    return count;

}
int _mergeSort(int a[], int temp[], int left, int right){
    int mid, count=0;

    if(right>left){
        mid=(left+right)/2;

        count+= _mergeSort(a,temp,left,mid);
        count+= _mergeSort(a,temp,mid+1,right);
        
        count+=merge(a,temp,left, mid+1,right);
    }
    return count;
}

int mergeSort(int a[], int N ){
    int temp[N];
    return _mergeSort(a, temp, 0, N-1);
}

int main(){
    int n, a[1000],f=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
    int ans = mergeSort(a,n);
    cout<<ans;
    // while (i<n){
    //     for(int j=i+1;j<n;j++){
    //         if(a[i]>a[j]){
    //             f++;
    //         }
    //     }
    //     i++;
    // }
    return 0;
}