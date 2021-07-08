#include<iostream>
using namespace std;

int main(){

    int n,m,a[100][100];
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    int sum=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tl= (i+1)*(j+1);
            int br= (n-i)*(m-j);
            sum+= tl*br*a[i][j];
        }
    }

    cout<<sum;

    return 0;
}