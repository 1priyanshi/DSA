#include<iostream>
using namespace std;

int main(){

    int n,m,k,s;
    char  a[100][100];

    cin>>n>>m>>k>>s;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(a[i][j]=='.'){
              s= s-2;
          }
          if(a[i][j]=='*'){
              s=s+5;
          }
          if(a[i][j]=='#'){
              break;
          }
          if(j!=m-1){
               s=s-1;
          }
        }
        if(s<k){
            break;
        }
    }
    
    if(s<k){
        cout<<"not possible";
    }
    else{
        cout<<s;
    }
    return 0;
}