//my way
// #include<iostream>
// using namespace std;

// int main(){

//     int n,m,a[100][100];
//     cin>>n>>m;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>a[i][j];
//         }
//     }
//    for(int j=m-1;j>=0;j--){
//        for(int i=0;i<n;i++){
//            cout<<a[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//     return 0;
// }

#include<iostream>
using namespace std;

int main(){

    int n,m,a[100][100];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

   for(int i=0;i<n;i++){
           int sc= 0, ec = m-1;
       while(sc<=ec){
           swap(a[i][sc],a[i][ec]);
            sc++;
            ec--;
       }
   }

   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i<j){
                swap(a[i][j],a[j][i]);
            }
        }
    }

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
