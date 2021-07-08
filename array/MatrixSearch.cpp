#include<iostream>
using namespace std;

int main(){

    int n,m,a[100][100],flag=0;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int key;
    cin>>key;

    int i=0,j=m-1;

    while (j>0 || i<n-1){
        if(a[i][j]== key){
            cout<<"1";
            flag=1;
            break;
        }
        else if(a[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }

if(flag==0){
    cout<<"0";
}
    return 0;
}