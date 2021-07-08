#include<iostream>
using namespace std;

int main(){

    int n,m,a[100][100], val =1;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]= val++;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int sr= 0,sc=0,er=n-1,ec=m-1,b[10000],k=0;
    
    while(sr<=er && sc<=ec){

        for(int i= sc;i<=ec;i++){
            b[k++]=a[sr][i];
        }
        sr++;

        for(int i=sr;i<=er;i++){
            b[k++]=a[i][ec];
        }
        ec--;

        if(sr<er){
            for(int i= ec; i>=sc;i--){
            b[k++]=a[er][i];
            }
            er--;
        }

        if(ec>sc){
             for(int i=er;i>=sr;i--){
            b[k++]=a[i][sc];
            }
            sc++;
        }

    }
    for(int i=0;i<k;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}