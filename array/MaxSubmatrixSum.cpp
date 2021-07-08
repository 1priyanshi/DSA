#include<iostream>
#include<climits>
using namespace std;

int main(){

    int n,m,a[100][100];
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            a[i][j]+= a[i][j+1];
        }
    }

     for(int i=m-1;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            a[j][i]+= a[j+1][i];
        }
    }

    int result = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result= max(result,a[i][j]);
        }
    }

    cout<<result;
    
    return 0;
}